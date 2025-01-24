#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

// abstract expression
class Expression {
   public:
    virtual ~Expression() = default;
    virtual int interpret(const std::unordered_map<std::string, int>& context) const = 0;
};

// terminal expression
class Variable : public Expression {
   public:
    explicit Variable(const std::string& name) : name_(name) {}

    int interpret(const std::unordered_map<std::string, int>& context) const override { return context.at(name_); }

   private:
    std::string name_;
};

// terminal expression
class Constant : public Expression {
   public:
    explicit Constant(int value) : value_(value) {}

    int interpret(const std::unordered_map<std::string, int>& context) const override { return value_; }

   private:
    int value_;
};

// non-terminal expression
class Add : public Expression {
   public:
    Add(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
        : left_(std::move(left)), right_(std::move(right)) {}

    int interpret(const std::unordered_map<std::string, int>& context) const override {
        return left_->interpret(context) + right_->interpret(context);
    }

   private:
    std::shared_ptr<Expression> left_;
    std::shared_ptr<Expression> right_;
};

// non-terminal expression
class Subtract : public Expression {
   public:
    Subtract(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
        : left_(std::move(left)), right_(std::move(right)) {}

    int interpret(const std::unordered_map<std::string, int>& context) const override {
        return left_->interpret(context) - right_->interpret(context);
    }

   private:
    std::shared_ptr<Expression> left_;
    std::shared_ptr<Expression> right_;
};

int main() {
    // construct expression: a + b - 5
    std::shared_ptr<Expression> expression = std::make_shared<Subtract>(
        std::make_shared<Add>(std::make_shared<Variable>("a"), std::make_shared<Variable>("b")),
        std::make_shared<Constant>(5));

    std::unordered_map<std::string, int> context = {{"a", 10}, {"b", 20}};

    std::cout << "Result: " << expression->interpret(context) << std::endl;

    return 0;
}