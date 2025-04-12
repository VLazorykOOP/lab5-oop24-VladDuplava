#include <iostream>
#include <string>
using namespace std;

class Engine {
private:
    double power;

public:
    Engine(double power = 100.0) : power(power) {}

    double getPower() const {
        return power;
    }
};

class Car {
private:
    string brand;
    double price;
    Engine engine;

public:
    Car(const string& brand, double price, double enginePower)
        : brand(brand), price(price), engine(enginePower) {}

    void print() const {
        cout << "Brand: " << brand << ", Price: " << price << " USD, Engine Power: " << engine.getPower() << " HP" << endl;
    }

    double getPrice() const {
        return price;
    }

    string getBrand() const {
        return brand;
    }
};

class Truck : public Car {
private:
    double loadCapacity;

public:
    Truck(const string& brand, double price, double enginePower, double loadCapacity)
        : Car(brand, price, enginePower), loadCapacity(loadCapacity) {}

    void print() const {
        Car::print();
        cout << "Load Capacity: " << loadCapacity << " kg" << endl;
    }

    double getLoadCapacity() const {
        return loadCapacity;
    }
};

int main() {
    Car car1("Toyota", 20000, 150);
    car1.print();

    Truck truck1("Volvo", 50000, 350, 12000);
    truck1.print();

    return 0;
}
