#include <iostream>
#include <memory>

// implementation interface
class Color {
   public:
    virtual ~Color() = default;
    virtual void applyColor() const = 0;
};

// concrete implementation color: red
class Red : public Color {
   public:
    void applyColor() const override { std::cout << "Applying red color" << std::endl; }
};

// concrete implementation color: blue
class Blue : public Color {
   public:
    void applyColor() const override { std::cout << "Applying blue color" << std::endl; }
};

// abstract class
class Shape {
   public:
    explicit Shape(std::shared_ptr<Color> color) : color_(std::move(color)) {}
    virtual ~Shape() = default;
    virtual void draw() const = 0;

   protected:
    std::shared_ptr<Color> color_;
};

// extended abstraction shape: circle
class Circle : public Shape {
   public:
    explicit Circle(std::shared_ptr<Color> color) : Shape(std::move(color)) {}
    void draw() const override {
        std::cout << "Drawing circle and ";
        color_->applyColor();
    }
};

// extended abstraction shape: rectangle
class Rectangle : public Shape {
   public:
    explicit Rectangle(std::shared_ptr<Color> color) : Shape(std::move(color)) {}
    void draw() const override {
        std::cout << "Drawing rectangle and ";
        color_->applyColor();
    }
};

void clientCode(const std::shared_ptr<Color>& color) {
    Circle circle(color);
    Rectangle rectangle(color);
    circle.draw();
    rectangle.draw();
}

int main() {
    std::shared_ptr<Red> red = std::make_shared<Red>();
    std::shared_ptr<Blue> blue = std::make_shared<Blue>();
    clientCode(red);
    clientCode(blue);

    return 0;
}