#include <iostream>
#include <memory>
#include <string>

// subject
class Image {
  public:
    virtual void display() const = 0;
    virtual ~Image() = default;
};

// real subject
class RealImage : public Image {
  public:
    explicit RealImage(const std::string& fileName) : filename_(fileName) { loadFromDisk(); }

    void display() const override { std::cout << "Displaying image: " << filename_ << std::endl; }

  private:
    std::string filename_;

    void loadFromDisk() const { std::cout << "Loading image from disk: " << filename_ << std::endl; }
};

// subject proxy
class ProxyImage : public Image {
  public:
    explicit ProxyImage(const std::string& fileName) : filename_(fileName), realImage_(nullptr) {}

    void display() const override {
        if (!realImage_) {
            realImage_ = std::make_unique<RealImage>(filename_); // delay loading real image
        }
        realImage_->display();
    }

  private:
    std::string filename_;
    mutable std::unique_ptr<RealImage> realImage_; // lazy initialization
};

int main() {
    ProxyImage proxyImage("test_image.jpg");

    // load the picture the first time you call display()
    proxyImage.display();
    // displayed directly the second time you call display()
    proxyImage.display();

    return 0;
}
