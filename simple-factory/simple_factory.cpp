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

enum class ButtonType { WINDOWS, MACBOOK };

// button factory is responsible for creating button objects
class ButtonFactory {
   public:
    static std::unique_ptr<Button> createButton(ButtonType type) {
        if (type == ButtonType::WINDOWS) {
            return std::make_unique<WindowsButton>();
        } else if (type == ButtonType::MACBOOK) {
            return std::make_unique<MacbookButton>();
        }
        return nullptr;
    }
};

int main() {
    std::unique_ptr<Button> windowsButton = ButtonFactory::createButton(ButtonType::WINDOWS);
    windowsButton->render();

    std::unique_ptr<Button> macbookButton = ButtonFactory::createButton(ButtonType::MACBOOK);
    macbookButton->render();

    return 0;
}