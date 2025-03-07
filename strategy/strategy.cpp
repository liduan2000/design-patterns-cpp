#include <iostream>
#include <memory>

// strategy interface
class PaymentStrategy {
  public:
    virtual ~PaymentStrategy() = default;
    virtual void pay(double amount) const = 0;
};

// concrete strategy
class CreditCardPayment : public PaymentStrategy {
  public:
    explicit CreditCardPayment(const std::string& cardNumber) : cardNumber_(cardNumber) {}

    void pay(double amount) const override {
        std::cout << "Paid " << amount << " using Credit Card: " << cardNumber_ << std::endl;
    }

  private:
    std::string cardNumber_;
};

// concrete strategy
class AlipayPayment : public PaymentStrategy {
  public:
    explicit AlipayPayment(const std::string& account) : account_(account) {}

    void pay(double amount) const override {
        std::cout << "Paid " << amount << " using Alipay account: " << account_ << std::endl;
    }

  private:
    std::string account_;
};

// context
class PaymentContext {
  public:
    void setPayment(std::unique_ptr<PaymentStrategy> payment) { payment_ = std::move(payment); }

    void executePayment(double amount) const {
        if (payment_) {
            payment_->pay(amount);
        } else {
            std::cout << "No payment strategy set!" << std::endl;
        }
    }

  private:
    std::unique_ptr<PaymentStrategy> payment_;
};

int main() {
    PaymentContext context;
    context.setPayment(std::make_unique<CreditCardPayment>("1111-2222-3333-4444"));
    context.executePayment(100.0);
    context.setPayment(std::make_unique<AlipayPayment>("test@gmail.com"));
    context.executePayment(200.0);

    return 0;
}