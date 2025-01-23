#include <iostream>
#include <memory>

class State;

// context
class Light {
   public:
    Light();
    void setState(std::shared_ptr<State> state);
    void pressSwitch();

   private:
    std::shared_ptr<State> state_;
};

// state interface
class State {
   public:
    virtual ~State() = default;
    virtual void handle(Light& light) = 0;
};

// concrete state
class OnState : public State {
   public:
    void handle(Light& light) override;
};

// concrete state
class OffState : public State {
   public:
    void handle(Light& light) override;
};

Light::Light() : state_(std::make_shared<OffState>()) {}

void Light::setState(std::shared_ptr<State> state) { state_ = std::move(state); }

void Light::pressSwitch() { state_->handle(*this); }

void OnState::handle(Light& light) {
    std::cout << "Turning the light off." << std::endl;
    light.setState(std::make_shared<OffState>());
}

void OffState::handle(Light& light) {
    std::cout << "Turning the light on." << std::endl;
    light.setState(std::make_shared<OnState>());
}

int main() {
    Light light;
    light.pressSwitch();
    light.pressSwitch();
    return 0;
}