#include <iostream>
#include <memory>
#include <string>

// receiver
class Light {
  public:
    void on() const { std::cout << "Light ON" << std::endl; }

    void off() const { std::cout << "Light OFF" << std::endl; }
};

// command interface
class Command {
  public:
    virtual ~Command() = default;
    virtual void execute() const = 0;
};

// concrete command
class LightOnCommand : public Command {
  public:
    explicit LightOnCommand(std::shared_ptr<Light> light) : light_(light) {}

    void execute() const override { light_->on(); }

  private:
    std::shared_ptr<Light> light_;
};

// concrete command
class LightOffCommand : public Command {
  public:
    explicit LightOffCommand(std::shared_ptr<Light> light) : light_(light) {}

    void execute() const override { light_->off(); }

  private:
    std::shared_ptr<Light> light_;
};

// invoker
class RemoteControl {
  public:
    void setCommand(std::shared_ptr<Command> command) { command_ = command; }

    void pressButton() {
        if (command_) command_->execute();
    }

  private:
    std::shared_ptr<Command> command_;
};

int main() {
    std::shared_ptr<Light> light = std::make_shared<Light>();

    std::shared_ptr<Command> lightOn = std::make_shared<LightOnCommand>(light);
    std::shared_ptr<Command> lightOff = std::make_shared<LightOffCommand>(light);

    RemoteControl remoteControl;

    remoteControl.setCommand(lightOn);
    remoteControl.pressButton();

    remoteControl.setCommand(lightOff);
    remoteControl.pressButton();

    return 0;
}