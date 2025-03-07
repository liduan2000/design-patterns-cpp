#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

// Suppose we have a character rendering system.
// Shared state: the font styles of characters (such as font, size).
// Unique state: the position of characters.

// flyweight interface
class Flyweight {
  public:
    virtual ~Flyweight() = default;
    virtual void render(int x, int y) const = 0;
};

// concrete flyweight
class Character : public Flyweight {
  public:
    Character(char symbol, const std::string& font, int size) : symbol_(symbol), font_(font), size_(size) {}

    void render(int x, int y) const override {
        std::cout << "Rendering character '" << symbol_ << "' at (" << x << ", " << y << ") with font '" << font_
                  << "' and size " << size_ << std::endl;
    }

  private:
    char symbol_;
    std::string font_;
    int size_;
};

// flyweight factory
class FlyweightFactory {
  public:
    std::shared_ptr<Flyweight> getFlyweight(char symbol, const std::string& font, int size) {
        std::string key = getKey(symbol, font, size);
        if (flyweights_.find(key) == flyweights_.end()) {
            flyweights_[key] = std::make_shared<Character>(symbol, font, size);
            std::cout << "Creating new flyweight for key: " << key << std::endl;
        } else {
            std::cout << "Reusing existing flyweight for key: " << key << std::endl;
        }
        return flyweights_[key];
    }

    size_t getFlyweightCount() const { return flyweights_.size(); }

  private:
    std::unordered_map<std::string, std::shared_ptr<Flyweight>> flyweights_;

    std::string getKey(char symbol, const std::string& font, int size) const {
        return std::string(1, symbol) + "_" + font + "_" + std::to_string(size);
    }
};

int main() {
    FlyweightFactory factory;

    std::shared_ptr<Flyweight> flyweightA = factory.getFlyweight('A', "Arial", 12);
    std::shared_ptr<Flyweight> flyweightB = factory.getFlyweight('B', "Arial", 12);
    std::shared_ptr<Flyweight> flyweightA1 = factory.getFlyweight('A', "Arial", 12);

    flyweightA->render(10, 20);
    flyweightB->render(30, 40);
    flyweightA1->render(50, 60);

    std::cout << "Total flyweights created: " << factory.getFlyweightCount() << std::endl;
    return 0;
}