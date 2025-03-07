#include <iostream>
#include <memory>

class Button {
  public:
    virtual ~Button() = default;
    virtual void render() const = 0;
};

class Checkbox {
  public:
    virtual ~Checkbox() = default;
    virtual void render() const = 0;
};

class WindowsButton : public Button {
  public:
    void render() const override { std::cout << "Windows button render" << std::endl; }
};

class MacbookButton : public Button {
  public:
    void render() const override { std::cout << "Macbook button render" << std::endl; }
};

class WindowsCheckbox : public Checkbox {
  public:
    void render() const override { std::cout << "Windows checkbox render" << std::endl; }
};

class MacbookCheckbox : public Checkbox {
  public:
    void render() const override { std::cout << "Macbook checkbox render" << std::endl; }
};

// abstract factory interface
// create a series of related or interdependent objects without specifying their specific classes
class GUIFactory {
  public:
    virtual ~GUIFactory() = default;
    virtual std::unique_ptr<Button> createButton() const = 0;
    virtual std::unique_ptr<Checkbox> createCheckbox() const = 0;
};

class WindowsFactory : public GUIFactory {
  public:
    std::unique_ptr<Button> createButton() const override { return std::make_unique<WindowsButton>(); }
    std::unique_ptr<Checkbox> createCheckbox() const override { return std::make_unique<WindowsCheckbox>(); }
};

class MacbookFactory : public GUIFactory {
  public:
    std::unique_ptr<Button> createButton() const override { return std::make_unique<MacbookButton>(); }
    std::unique_ptr<Checkbox> createCheckbox() const override { return std::make_unique<MacbookCheckbox>(); }
};

void clientCode(const GUIFactory& factory) {
    std::unique_ptr<Button> button = factory.createButton();
    std::unique_ptr<Checkbox> checkbox = factory.createCheckbox();
    button->render();
    checkbox->render();
}

int main() {
    std::unique_ptr<WindowsFactory> windowsFactory = std::make_unique<WindowsFactory>();
    clientCode(*windowsFactory);

    std::unique_ptr<MacbookFactory> macbookFactory = std::make_unique<MacbookFactory>();
    clientCode(*macbookFactory);

    return 0;
}