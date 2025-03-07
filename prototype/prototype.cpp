#include <iostream>
#include <memory>
#include <unordered_map>

enum class ShapeType { CIRCLE, RECTANGLE };

// prototype class: Shape
class Shape {
  public:
    virtual ~Shape() = default;
    virtual std::unique_ptr<Shape> clone() const = 0;
    virtual void draw() const = 0;
};

// concrete prototype: Circle
class Circle : public Shape {
  public:
    explicit Circle(double radius) : radius_(radius) {}
    std::unique_ptr<Shape> clone() const override { return std::make_unique<Circle>(*this); }
    void draw() const override { std::cout << "Drawing a circle with radius " << radius_ << std::endl; }

  private:
    double radius_;
};

// concrete prototype: Rectangle
class Rectangle : public Shape {
  public:
    Rectangle(double width, double height) : width_(width), height_(height) {}
    std::unique_ptr<Shape> clone() const override { return std::make_unique<Rectangle>(*this); }
    void draw() const override {
        std::cout << "Drawing a rectangle with width " << width_ << " and height " << height_ << std::endl;
    }

  private:
    double width_;
    double height_;
};

// prototype manager
class ShapeManager {
  public:
    void registerPrototype(ShapeType type, std::unique_ptr<Shape> prototype) {
        prototypes_[type] = std::move(prototype);
    }

    std::unique_ptr<Shape> createShape(ShapeType type) const {
        auto it = prototypes_.find(type);
        if (it != prototypes_.end()) { return it->second->clone(); }
        return nullptr;
    }

  private:
    std::unordered_map<ShapeType, std::unique_ptr<Shape>> prototypes_;
};

void clientCode(const ShapeManager& manager) {
    std::unique_ptr<Shape> circle = manager.createShape(ShapeType::CIRCLE);
    std::unique_ptr<Shape> rectangle = manager.createShape(ShapeType::RECTANGLE);
    if (circle) circle->draw();
    if (rectangle) rectangle->draw();
}

int main() {
    ShapeManager manager;
    manager.registerPrototype(ShapeType::CIRCLE, std::make_unique<Circle>(1.0));
    manager.registerPrototype(ShapeType::RECTANGLE, std::make_unique<Rectangle>(2.0, 3.0));
    clientCode(manager);

    return 0;
}