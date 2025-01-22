#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Memento {
   public:
    explicit Memento(const std::string& state) : state_(state) {}
    std::string getState() const { return state_; }

   private:
    std::string state_;
};

class Originator {
   public:
    void setState(const std::string& state) {
        this->state_ = state;
        std::cout << "State set to: " << state << std::endl;
    }

    std::string getState() const { return state_; }

    std::unique_ptr<Memento> saveToMemento() const { return std::make_unique<Memento>(state_); }

    void restoreFromMemento(const Memento& memento) {
        state_ = memento.getState();
        std::cout << "Restored state to: " << state_ << std::endl;
    }

   private:
    std::string state_;
};

class Caretaker {
   public:
    explicit Caretaker(Originator& originator) : originator_(originator) {}

    void save() { mementos_.emplace_back(originator_.saveToMemento()); }

    void undo() {
        if (mementos_.empty()) {
            std::cout << "No states to undo!" << std::endl;
            return;
        }
        originator_.restoreFromMemento(*mementos_.back());
        mementos_.pop_back();
    }

   private:
    std::vector<std::unique_ptr<Memento>> mementos_;
    Originator& originator_;
};

int main() {
    Originator originator;
    Caretaker caretaker(originator);

    originator.setState("State1");
    caretaker.save();

    originator.setState("State2");
    caretaker.save();

    originator.setState("State3");
    caretaker.save();

    caretaker.undo();
    caretaker.undo();

    return 0;
}