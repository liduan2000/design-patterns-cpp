#include <iostream>
#include <memory>

class Button {
  public:
    virtual ~Button() = default;
    virtual void render() = 0;
};

class WindowsButton : public Button {
  public:
    void render() override { std::cout << "Windows render" << std::endl; }
};

class MacbookButton : public Button {
  public:
    void render() override { std::cout << "Macbook render" << std::endl; }
};

// allow subclasses to determine the type of instantiated object
class Dialog {
  public:
    virtual ~Dialog() = default;
    virtual std::unique_ptr<Button> createButton() = 0;

    void render() {
        std::unique_ptr<Button> button = createButton();
        button->render();
    }
};

class WindowsDialog : public Dialog {
  public:
    std::unique_ptr<Button> createButton() override { return std::make_unique<WindowsButton>(); }
};

class MacbookDialog : public Dialog {
  public:
    std::unique_ptr<Button> createButton() override { return std::make_unique<MacbookButton>(); }
};

int main() {
    std::unique_ptr<Dialog> windowsDialog = std::make_unique<WindowsDialog>();
    windowsDialog->render();

    std::unique_ptr<Dialog> macbookDialog = std::make_unique<MacbookDialog>();
    macbookDialog->render();

    return 0;
}