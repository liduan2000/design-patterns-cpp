#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// observer interface
class Observer {
   public:
    virtual ~Observer() = default;
    virtual void update(const std::string& message) const = 0;
};

// abstract subject
class Subject {
   public:
    virtual ~Subject() = default;
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() const = 0;
};

// concrete subject
class ConcreteSubject : public Subject {
   public:
    void attach(Observer* observer) override { observers_.push_back(observer); }

    void detach(Observer* observer) override {
        observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
    }

    void notify() const override {
        for (Observer* observer : observers_) {
            observer->update(state_);
        }
    }

    std::string getState() const { return state_; }

    void setState(const std::string& state) {
        state_ = state;
        notify();
    }

   private:
    std::string state_;
    std::vector<Observer*> observers_;
};

// concrete observer
class ConcreteObserver : public Observer {
   public:
    ConcreteObserver(const std::string& name) : name_(name) {}

    void update(const std::string& message) const {
        std::cout << "Observer " << name_ << " received message: " << message << std::endl;
    }

   private:
    std::string name_;
};

int main() {
    ConcreteSubject subject;
    ConcreteObserver observer1("observer1");
    ConcreteObserver observer2("observer2");

    subject.attach(&observer1);
    subject.attach(&observer2);

    subject.setState("State 1");

    subject.detach(&observer2);

    subject.setState("State 2");

    return 0;
}