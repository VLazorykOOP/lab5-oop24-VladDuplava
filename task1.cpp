#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;// марка машини
    int cylinders; //кількість циліндрів
    double power; // потужність

public:
    // Конструктор за замовчуванням
    Car() : brand(""), cylinders(0), power(0) {}

    // Конструктор з параметрами
    Car(string brand, int cylinders, double power) : brand(brand), cylinders(cylinders), power(power) {}

    // Функція виводу інформації
    void print() const {
        cout << "Brand: " << brand << ", Cylinders: " << cylinders << ", Power: " << power << " HP" << endl;
    }

    // Функція перепризначення марки
    void setBrand(string newBrand) {
        brand = newBrand;
    }

    // Функція перепризначення потужності
    void setPower(double newPower) {
        power = newPower;
    }
};

// Наслідуваний клас
class Truck : public Car {
private:
    double loadCapacity;

public:
    //Конструктор
    Truck() : Car(), loadCapacity(1000) {}

    // Конструктор з параметрами
    Truck(string brand, int cylinders, double power, double loadCapacity)
        : Car(brand, cylinders, power), loadCapacity(loadCapacity) {}

    void print() const {
        Car::print();
        cout << "Load Capacity: " << loadCapacity << " kg" << endl;
    }

    // Функція перепризначення вантажопідйомності
    void setLoadCapacity(double newLoadCapacity) {
        loadCapacity = newLoadCapacity;
    }
};

int main() {
    Car car1("Mercedes", 5, 150);
    car1.print();

    Truck truck1("VW", 8, 350, 12000);
    truck1.print();

    car1.setBrand("BMW");
    car1.setPower(180.0);
    car1.print();

    truck1.setLoadCapacity(14000.0);
    truck1.print();

    return 0;
}
