#include <iostream>
#include <string>
using namespace std;

// Базовий клас
class Furniture {
protected:
    string material;
    double price;

public:
    // Конструктор за замовченням
    Furniture() : material("Unknown"), price(0.0) {}

    // Конструктор із параметрами
    Furniture(const string& material, double price)
        : material(material), price(price) {}

    // Конструктор копіювання
    Furniture(const Furniture& other)
        : material(other.material), price(other.price) {}

    // Оператор присвоювання
    Furniture& operator=(const Furniture& other) {
        if (this != &other) { // захист від самоприсвоювання
            material = other.material;
            price = other.price;
        }
        return *this;
    }

    // Віртуальний деструктор
    virtual ~Furniture() {}

    // Віртуальна функція друку
    virtual void print(ostream& os) const {
        os << "Material: " << material << ", Price: " << price << " USD";
    }

    // Віртуальна функція вводу
    virtual void input(istream& is) {
        cout << "Enter material: ";
        is >> material;
        cout << "Enter price: ";
        is >> price;
    }

    // Перевантаження операторів для базового класу
friend ostream& operator<<(ostream& os, const Furniture& furniture) {
    furniture.print(os);
    return os;
}

friend istream& operator>>(istream& is, Furniture& furniture) {
    furniture.input(is);
    return is;
}
};

// Похідний клас
class Table : public Furniture {
private:
    int legs; // кількість ніжок

public:
    // Конструктор за замовченням
    Table() : Furniture(), legs(4) {}

    // Конструктор із параметрами
    Table(const string& material, double price, int legs)
        : Furniture(material, price), legs(legs) {}

    // Конструктор копіювання
    Table(const Table& other)
        : Furniture(other), legs(other.legs) {}

    // Оператор присвоювання
    Table& operator=(const Table& other) {
        if (this != &other) {
            Furniture::operator=(other); // копіюємо базову частину
            legs = other.legs;
        }
        return *this;
    }

    // Перевизначення друку
    void print(ostream& os) const override {
        Furniture::print(os);
        os << ", Legs: " << legs;
    }

    // Перевизначення вводу
    void input(istream& is) override {
        Furniture::input(is);
        cout << "Enter number of legs: ";
        is >> legs;
    }

    // Перевантаження операторів для похідного класу
    friend ostream& operator<<(ostream& os, const Table& table) {
        table.print(os);
        return os;
    }

    friend istream& operator>>(istream& is, Table& table) {
        table.input(is);
        return is;
    }
};

// Тестування
int main() {
    cout << "Furniture object" << endl;
    Furniture f1;
    cin >> f1;
    cout << f1 << endl;

    cout << "\nTable object" << endl;
    Table t1;
    cin >> t1;
    cout << t1 << endl;

    cout << "\nCopying Table" << endl;
    Table t2 = t1; // конструктор копіювання
    cout << t2 << endl;

    cout << "\nAssignment Table" << endl;
    Table t3;
    t3 = t2; // оператор присвоювання
    cout << t3 << endl;

    return 0;
}
