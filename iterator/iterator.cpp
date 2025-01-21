#include <iostream>
#include <memory>
#include <string>
#include <vector>

// iterator interface
template <typename T>
class Iterator {
   public:
    virtual ~Iterator() = default;
    virtual void first() = 0;
    virtual void next() = 0;
    virtual T current() const = 0;
    virtual bool isDone() const = 0;
};

// concrete iterator
template <typename T>
class ConcreteIterator : public Iterator<T> {
   public:
    explicit ConcreteIterator(const std::vector<T>& collection) : collection_(collection) {}

    void first() override { index = 0; }

    void next() override {
        if (!isDone()) ++index;
    }

    T current() const override {
        if (!isDone()) {
            return collection_[index];
        }
        throw std::out_of_range("Iterator out of range");
    }

    bool isDone() const override { return index >= collection_.size(); }

   private:
    const std::vector<T>& collection_;
    size_t index = 0;
};

// aggregate interface
template <typename T>
class Aggregate {
   public:
    virtual ~Aggregate() = default;
    virtual std::unique_ptr<Iterator<T>> createIterator() const = 0;
};

// concrete aggregate
template <typename T>
class ConcreteAggregate : public Aggregate<T> {
   public:
    void add(const T& item) { collection_.push_back(item); }

    std::unique_ptr<Iterator<T>> createIterator() const override {
        return std::make_unique<ConcreteIterator<T>>(collection_);
    }

   private:
    std::vector<T> collection_;
};

int main() {
    ConcreteAggregate<std::string> aggregate;
    aggregate.add("Element 1");
    aggregate.add("Element 2");
    aggregate.add("Element 3");

    std::unique_ptr<Iterator<std::string>> it = aggregate.createIterator();

    std::cout << "Elements in the collection:" << std::endl;
    for (it->first(); !it->isDone(); it->next()) {
        std::cout << it->current() << std::endl;
    }

    return 0;
}