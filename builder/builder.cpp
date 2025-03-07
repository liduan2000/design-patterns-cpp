#include <iostream>
#include <memory>
#include <string>

// product
class House {
  public:
    void setWalls(const std::string& walls) { walls_ = walls; }
    void setDoors(const std::string& doors) { doors_ = doors; }
    void setWindows(const std::string& windows) { windows_ = windows; }
    void showHouse() const {
        std::cout << "House with " << walls_ << ", " << doors_ << ", and " << windows_ << std::endl;
    }

  private:
    std::string walls_;
    std::string doors_;
    std::string windows_;
};

// builder interface
class HouseBuilder {
  public:
    virtual ~HouseBuilder() = default;
    virtual void buildWalls() = 0;
    virtual void buildDoors() = 0;
    virtual void buildWindows() = 0;
    virtual std::shared_ptr<House> getHouse() = 0;
};

// wooden house builder
class WoodenHouseBuilder : public HouseBuilder {
  public:
    WoodenHouseBuilder() { house_ = std::make_shared<House>(); }

    void buildWalls() override { house_->setWalls("Wooden Walls"); }
    void buildDoors() override { house_->setDoors("Wooden Doors"); }
    void buildWindows() override { house_->setWindows("Wooden Windows"); }
    std::shared_ptr<House> getHouse() override { return house_; };

  private:
    std::shared_ptr<House> house_;
};

// rocky house builder
class RockyHouseBuilder : public HouseBuilder {
  public:
    RockyHouseBuilder() { house_ = std::make_shared<House>(); }

    void buildWalls() override { house_->setWalls("Rocky Walls"); }
    void buildDoors() override { house_->setDoors("Rocky Doors"); }
    void buildWindows() override { house_->setWindows("Rocky Windows"); }
    std::shared_ptr<House> getHouse() override { return house_; };

  private:
    std::shared_ptr<House> house_;
};

// director
class HouseDirector {
  public:
    HouseDirector(std::shared_ptr<HouseBuilder> builder = nullptr) : builder_(builder) {}

    void setBuilder(std::shared_ptr<HouseBuilder> builder) { builder_ = builder; }

    void constructHouse() {
        builder_->buildWalls();
        builder_->buildDoors();
        builder_->buildWindows();
    }

    std::shared_ptr<House> getHouse() { return builder_->getHouse(); }

  private:
    std::shared_ptr<HouseBuilder> builder_;
};

void clientCode(HouseDirector& director, const std::string& houseType) {
    if (houseType == "wooden") {
        director.setBuilder(std::make_shared<WoodenHouseBuilder>());
    } else if (houseType == "rocky") {
        director.setBuilder(std::make_shared<RockyHouseBuilder>());
    } else {
        std::cerr << "Unknown house type!" << std::endl;
        return;
    }

    director.constructHouse();
    std::shared_ptr<House> house = director.getHouse();
    house->showHouse();
}

int main() {
    HouseDirector director;
    clientCode(director, "wooden");
    clientCode(director, "rocky");

    return 0;
}