#include <iostream>

// abstract class
class Beverage {
   public:
    virtual ~Beverage() = default;

    // template method
    void prepareBeverage() {
        boilWater();
        brew();
        pourInCup();
        if (customerWantsCondiments()) {
            addCondiments();
        }
    }

   protected:
    void boilWater() { std::cout << "Boiling water" << std::endl; }

    void pourInCup() { std::cout << "Pouring into cup" << std::endl; }

    virtual void brew() = 0;

    virtual void addCondiments() = 0;

    // hook method
    virtual bool customerWantsCondiments() { return true; }
};

// concrete class
class Tea : public Beverage {
   protected:
    void brew() override { std::cout << "Steeping the tea" << std::endl; }

    void addCondiments() override { std::cout << "Adding lemon" << std::endl; }
};

// concrete class
class Coffee : public Beverage {
   public:
    explicit Coffee(bool wantsCondiments) : wantsCondiments_(wantsCondiments) {}

   protected:
    void brew() override { std::cout << "Dripping coffee through filter" << std::endl; }

    void addCondiments() override { std::cout << "Adding sugar and milk" << std::endl; }

    bool customerWantsCondiments() override { return wantsCondiments_; }

   private:
    bool wantsCondiments_;
};

int main() {
    std::cout << "Making tea..." << std::endl;
    Tea tea;
    tea.prepareBeverage();

    std::cout << "Making coffee..." << std::endl;
    bool wantsCondiments = true;
    Coffee coffee(wantsCondiments);
    coffee.prepareBeverage();

    return 0;
}