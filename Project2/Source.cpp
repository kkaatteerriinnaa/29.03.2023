#include <iostream>
#include <string>

// Product
class Car {
public:
    void set_name(const std::string& name) {
        name_ = name;
    }

    void set_body_type(const std::string& body_type) {
        body_type_ = body_type;
    }

    void set_engine_power(int engine_power) {
        engine_power_ = engine_power;
    }

    void set_wheel_size(int wheel_size) {
        wheel_size_ = wheel_size;
    }

    void set_transmission(const std::string& transmission) {
        transmission_ = transmission;
    }

    void print() const {
        std::cout << "Name: " << name_ << std::endl;
        std::cout << "Body type: " << body_type_ << std::endl;
        std::cout << "Engine power: " << engine_power_ << " hp" << std::endl;
        std::cout << "Wheel size: " << wheel_size_ << " R" << std::endl;
        std::cout << "Transmission: " << transmission_ << std::endl;
    }

private:
    std::string name_;
    std::string body_type_;
    int engine_power_ = 0;
    int wheel_size_ = 0;
    std::string transmission_;
};

// Builder
class CarBuilder {
public:
    virtual ~CarBuilder() {}
    virtual void build_name() = 0;
    virtual void build_body_type() = 0;
    virtual void build_engine_power() = 0;
    virtual void build_wheel_size() = 0;
    virtual void build_transmission() = 0;
    virtual Car* get_car() = 0;
};

// ConcreteBuilder
class DaewooLanosBuilder : public CarBuilder {
public:
    DaewooLanosBuilder() {
        car_ = new Car();
    }

    void build_name() override {
        car_->set_name("Daewoo Lanos");
    }

    void build_body_type() override {
        car_->set_body_type("Sedan");
    }

    void build_engine_power() override {
        car_->set_engine_power(98);
    }

    void build_wheel_size() override {
        car_->set_wheel_size(13);
    }

    void build_transmission() override {
        car_->set_transmission("Manual");
    }

    Car* get_car() override {
        return car_;
    }

private:
    Car* car_;
};

class FordProbeBuilder : public CarBuilder {
public:
    FordProbeBuilder() {
        car_ = new Car();
    }

    void build_name() override {
        car_->set_name("Ford Probe");
    }

    void build_body_type() override
        class DaewooLanosBuilder : public CarBuilder {
        public:
            void setBody() override {
                car_->setBody("Sedan");
            }

            void setEngine() override {
                car_->setEngine("98 ë. ñ");
            }

            void setWheels() override {
                car_->setWheels("13 R");
            }

            void setTransmission() override {
                car_->setTransmission("5 Manual");
            }
    };

    class UazPatriotBuilder : public CarBuilder {
    public:
        void setBody() override {
            car_->setBody("Universal");
        }

        void setEngine() override {
            car_->setEngine("120 ë. ñ");
        }

        void setWheels() override {
            car_->setWheels("16 R");
        }

        void setTransmission() override {
            car_->setTransmission("4 Manual");
        }
    };

    class HyundaiGetzBuilder : public CarBuilder {
    public:
        void setBody() override {
            car_->setBody("Hatchback");
        }

        void setEngine() override {
            car_->setEngine("66 ë. ñ");
        }

        void setWheels() override {
            car_->setWheels("13 R");
        }

        void setTransmission() override {
            car_->setTransmission("4 Auto");
        }
    };
    class Shop {
    public:
        void setBuilder(CarBuilder* builder) {
            builder_ = builder;
        }

        Car* getCar() {
            return builder_->getCar();
        }

        void constructCar() {
            builder_->createNewCar();
            builder_->setBody();
            builder_->setEngine();
            builder_->setWheels();
            builder_->setTransmission();
        }

    private:
        CarBuilder* builder_;
    };
    int main() {
        Shop shop;
        CarBuilder* builder;

        builder = new DaewooLanosBuilder();
        shop.setBuilder(builder);
        shop.constructCar();
        Car* car1 = shop.getCar();
        car1->print();

        builder = new FordProbeBuilder();
        shop.setBuilder(builder);
        shop.constructCar();
        Car* car2 = shop.getCar();
        car2->print();

        builder = new UazPatriotBuilder();
        shop.setBuilder(builder);
        shop.constructCar();
        Car* car3 = shop.getCar();
        car3->print();

        builder = new HyundaiGetzBuilder();
        shop.setBuilder(builder);
        shop.constructCar();
        Car* car4 = shop.getCar();
        car4->print();

        delete car1;
        delete car2;
        delete car3;
        delete car4;

        return 0;
    }
};