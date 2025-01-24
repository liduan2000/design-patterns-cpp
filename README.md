## C++ Design Patterns

Design patterns are typical solutions to common problems in software design. They are like pre-made blueprints that can be tailored to fit specific needs, and they can be used to address recurring design issues in your code.

Unlike methods or libraries, design patterns are not something you can directly plug into your program. A pattern is not a specific piece of code, but rather a general concept for solving a particular problem. You can implement a solution based on the pattern that fits the actual requirements of your program.

An algorithm is more like a recipe: it provides clear steps to achieve a goal. A pattern, on the other hand, is more like a blueprint: you can see the final result and the functionality of the pattern, but you need to determine the implementation steps yourself.

### Creational Patterns

Deal with object creation mechanisms, aiming to create objects in a suitable way for the situation.

- [Singleton](https://github.com/liduan2000/design-pattern-cpp/blob/main/singleton/singleton.cpp): Ensures a class has only one instance and provides a global point of access to it.

- [Factory Method](https://github.com/liduan2000/design-pattern-cpp/blob/main/factory-method/factory_method.cpp): Defines an interface for creating an object but lets subclasses alter the type of objects created.

- [Abstract Factory](https://github.com/liduan2000/design-pattern-cpp/blob/main/abstract-factory/abstract_factory.cpp): Provides an interface for creating families of related or dependent objects without specifying their concrete classes.

- [Builder](https://github.com/liduan2000/design-pattern-cpp/blob/main/builder/builder.cpp): Separates the construction of a complex object from its representation, allowing the same construction process to create various representations.

- [Prototype](https://github.com/liduan2000/design-pattern-cpp/blob/main/prototype/prototype.cpp): Specifies the kinds of objects to create using a prototypical instance and creates new objects by copying this prototype.

### Structural Patterns

Concerned with class and object composition, focusing on how classes and objects are structured to form larger structures.

- [Adapter](https://github.com/liduan2000/design-pattern-cpp/blob/main/adapter/adapter.cpp): Converts the interface of a class into another interface clients expect, enabling classes to work together that couldn’t otherwise.

- [Bridge](https://github.com/liduan2000/design-pattern-cpp/blob/main/bridge/bridge.cpp): Separates an object’s abstraction from its implementation, allowing the two to vary independently.

- [Composite](https://github.com/liduan2000/design-pattern-cpp/blob/main/composite/composite.cpp): Composes objects into tree structures to represent part-whole hierarchies, allowing clients to treat individual objects and compositions uniformly.

- [Decorator](https://github.com/liduan2000/design-pattern-cpp/blob/main/decorator/decorator.cpp): Dynamically adds behavior to an object without affecting the behavior of other objects from the same class.

- [Facade](https://github.com/liduan2000/design-pattern-cpp/blob/main/facade/facade.cpp): Provides a simplified interface to a complex subsystem.

- [Flyweight](https://github.com/liduan2000/design-pattern-cpp/blob/main/flyweight/flyweight.cpp): Reduces the cost of creating and manipulating many similar objects by sharing as much data as possible.

- [Proxy](https://github.com/liduan2000/design-pattern-cpp/blob/main/proxy/proxy.cpp): Provides a surrogate or placeholder for another object to control access to it.

### Behavioral Patterns

Focus on communication between objects, defining how objects interact and distribute responsibility.

- [Chain of Responsibility](https://github.com/liduan2000/design-pattern-cpp/blob/main/chain-of-responsibility/chain_of_responsibility.cpp): Passes a request along a chain of handlers, where each handler either processes the request or passes it to the next handler.

- [Command](https://github.com/liduan2000/design-pattern-cpp/blob/main/command/command.cpp): Encapsulates a request as an object, allowing parameterization of clients with queues, requests, and operations.

- [Iterator](https://github.com/liduan2000/design-pattern-cpp/blob/main/iterator/iterator.cpp): Provides a way to access elements of a collection sequentially without exposing its underlying representation.

- [Mediator](https://github.com/liduan2000/design-pattern-cpp/blob/main/mediator/mediator.cpp): Defines an object that encapsulates how a set of objects interact, promoting loose coupling.

- [Memento](https://github.com/liduan2000/design-pattern-cpp/blob/main/memento/memento.cpp): Captures and externalizes an object’s internal state without violating encapsulation, allowing the object to be restored later.

- [Observer](https://github.com/liduan2000/design-pattern-cpp/blob/main/observer/observer.cpp): Defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified.

- [State](https://github.com/liduan2000/design-pattern-cpp/blob/main/state/state.cpp): Allows an object to alter its behavior when its internal state changes, appearing to change its class.

- [Strategy](https://github.com/liduan2000/design-pattern-cpp/blob/main/strategy/strategy.cpp): Defines a family of algorithms, encapsulates each one, and makes them interchangeable, allowing the algorithm to vary independently from clients.

- [Template Method](https://github.com/liduan2000/design-pattern-cpp/blob/main/template-method/template_method.cpp): Defines the skeleton of an algorithm in a method, deferring some steps to subclasses.

- [Interpreter](https://github.com/liduan2000/design-pattern-cpp/blob/main/interpreter/interpreter.cpp): Defines a grammatical representation for a language and provides an interpreter to deal with this grammar.

- [Visitor](https://github.com/liduan2000/design-pattern-cpp/blob/main/visitor/visitor.cpp): Represents an operation to be performed on elements of an object structure, allowing new operations to be defined without changing the classes of the elements.

### References

Design patterns in this repository are based on:

- [Refactoring Guru: Design Patterns](https://refactoring.guru/design-patterns/)
- [Wikipedia](https://en.wikipedia.org/wiki/Software_design_pattern)
