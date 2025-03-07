#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

const double PI = 3.14159265358979323846;

class Circle;
class Rectangle;

// abstract visitor
class Visitor {
  public:
    virtual ~Visitor() = default;
    virtual void visitCircle(Circle* circle) = 0;
    virtual void visitRectangle(Rectangle* rectangle) = 0;
};

// element interface
class Shape {
  public:
    virtual ~Shape() = default;
    virtual void accept(Visitor* visitor) = 0;
};

// concrete element
class Circle : public Shape {
  public:
    explicit Circle(double radius) : radius_(radius) {}

    double getRadius() { return radius_; }

    void accept(Visitor* visitor) override { visitor->visitCircle(this); }

  private:
    double radius_;
};

// concrete element
class Rectangle : public Shape {
  public:
    Rectangle(double width, double height) : width_(width), height_(height) {}

    double getWidth() { return width_; }

    double getHeight() { return height_; }

    void accept(Visitor* visitor) { visitor->visitRectangle(this); }

  private:
    double width_, height_;
};

// concrete visitor
class AreaCalculator : public Visitor {
  public:
    void visitCircle(Circle* circle) override {
        double area = PI * std::pow(circle->getRadius(), 2);
        std::cout << "Circle Area: " << area << std::endl;
    }

    void visitRectangle(Rectangle* rectangle) override {
        double area = rectangle->getWidth() * rectangle->getHeight();
        std::cout << "Rectangle Area: " << area << std::endl;
    }
};

// concrete visitor
class ShapeDrawer : public Visitor {
  public:
    void visitCircle(Circle* circle) override {
        std::cout << "Drawing a Circle with radius " << circle->getRadius() << std::endl;
    }

    void visitRectangle(Rectangle* rectangle) override {
        std::cout << "Drawing a Rectangle with width " << rectangle->getWidth() << " and height "
                  << rectangle->getHeight() << std::endl;
    }
};

int main() {
    std::vector<std::shared_ptr<Shape>> shapes = {std::make_shared<Circle>(5.0), std::make_shared<Rectangle>(4.0, 6.0)};

    AreaCalculator areaCalculator;
    ShapeDrawer shapeDrawer;

    for (const auto& shape : shapes) {
        shape->accept(&areaCalculator);
        shape->accept(&shapeDrawer);
    }

    return 0;
}