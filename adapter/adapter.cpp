#include <iostream>
#include <memory>

// target interface
class Shape {
  public:
    virtual ~Shape() = default;
    virtual void draw(int x, int y, int width, int height) const = 0;
};

// legacy class
class LegacyRectangle {
  public:
    void draw(int x1, int y1, int x2, int y2) {
        std::cout << "LegacyRectangle: draw(" << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ")" << std::endl;
    }
};

// object adapter
class RectangleAdapter : public Shape {
  public:
    explicit RectangleAdapter(std::shared_ptr<LegacyRectangle> legacy) : legacy_(legacy) {}

    void draw(int x, int y, int width, int height) const override {
        int x2 = x + width;
        int y2 = y + height;
        legacy_->draw(x, y, x2, y2);
    }

  private:
    std::shared_ptr<LegacyRectangle> legacy_;
};

void clientCode(const Shape& shape) { shape.draw(5, 5, 10, 20); }

int main() {
    std::shared_ptr<LegacyRectangle> legacyRectangle = std::make_shared<LegacyRectangle>();
    RectangleAdapter adapter(legacyRectangle);
    clientCode(adapter);

    return 0;
}