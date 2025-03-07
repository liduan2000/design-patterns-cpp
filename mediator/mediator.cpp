#include <iostream>
#include <string>
#include <vector>

class Colleague;

// abstract mediator
class Mediator {
  public:
    virtual ~Mediator() = default;
    virtual void sendMessage(const std::string& message, Colleague* sender) = 0;
};

// abstract colleague
class Colleague {
  public:
    explicit Colleague(Mediator* mediator) : mediator_(mediator) {}
    virtual ~Colleague() = default;
    virtual void receiveMessage(const std::string& message) = 0;

  protected:
    Mediator* mediator_;
};

// concrete mediator
class ChatMediator : public Mediator {
  public:
    void addColleague(Colleague* colleague) { colleagues_.push_back(colleague); }

    void sendMessage(const std::string& message, Colleague* sender) override {
        for (auto& colleague : colleagues_) {
            if (colleague != sender) { colleague->receiveMessage(message); }
        }
    }

  private:
    std::vector<Colleague*> colleagues_;
};

// concrete colleague
class User : public Colleague {
  public:
    User(const std::string& name, Mediator* mediator) : Colleague(mediator), name_(name) {}

    void sendMessage(const std::string& message) {
        std::cout << name_ << " sends: " << message << std::endl;
        mediator_->sendMessage(message, this);
    }

    void receiveMessage(const std::string& message) override {
        std::cout << name_ << " receives: " << message << std::endl;
    }

  private:
    std::string name_;
};

int main() {
    ChatMediator chatMediator;

    User user1("Alice", &chatMediator);
    User user2("Bob", &chatMediator);
    User user3("John", &chatMediator);

    chatMediator.addColleague(&user1);
    chatMediator.addColleague(&user2);
    chatMediator.addColleague(&user3);

    user1.sendMessage("Hi everyone!");
    user2.sendMessage("Nice to connect!");
    user3.sendMessage("Good to see you all!");

    return 0;
}