#include <iostream>
#include <memory>
#include <string>

// component interface
class Component {
  public:
    virtual ~Component() = default;
    virtual std::string render() const = 0;
};

// concrete component
class Text : public Component {
  public:
    explicit Text(const std::string& content) : content_(content) {}
    std::string render() const override { return content_; }

  private:
    std::string content_;
};

// decorator
class Decorator : public Component {
  public:
    explicit Decorator(std::shared_ptr<Component> component) : component_(std::move(component)) {}
    std::string render() const override { return component_->render(); }

  protected:
    std::shared_ptr<Component> component_;
};

// concrete decorator: bold
class BoldDecorator : public Decorator {
  public:
    explicit BoldDecorator(std::shared_ptr<Component> component) : Decorator(std::move(component)) {}
    std::string render() const override { return "<b>" + component_->render() + "</b>"; }
};

// concrete decorator: italic
class ItalicDecorator : public Decorator {
  public:
    explicit ItalicDecorator(std::shared_ptr<Component> component) : Decorator(std::move(component)) {}
    std::string render() const override { return "<i>" + component_->render() + "</i>"; }
};

// concrete decorator: underline
class UnderlineDecorator : public Decorator {
  public:
    explicit UnderlineDecorator(std::shared_ptr<Component> component) : Decorator(std::move(component)) {}
    std::string render() const override { return "<u>" + component_->render() + "</u>"; }
};

void clientCode(const std::shared_ptr<Component>& component) {
    std::shared_ptr<BoldDecorator> boldComponent = std::make_shared<BoldDecorator>(component);
    std::shared_ptr<ItalicDecorator> italicBoldComponent = std::make_shared<ItalicDecorator>(boldComponent);
    std::shared_ptr<UnderlineDecorator> underlineItalicBoldComponent =
        std::make_shared<UnderlineDecorator>(italicBoldComponent);

    std::cout << "Original: " << component->render() << std::endl;
    std::cout << "Bold: " << boldComponent->render() << std::endl;
    std::cout << "Bold + Italic: " << italicBoldComponent->render() << std::endl;
    std::cout << "Bold + Italic + Underline: " << underlineItalicBoldComponent->render() << std::endl;
}

int main() {
    std::shared_ptr<Text> text = std::make_shared<Text>("Hello World!");
    clientCode(text);

    return 0;
}