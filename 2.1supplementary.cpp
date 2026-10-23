#include <iostream>
#include <string>
using namespace std;

class Fruit {
private:
    string name;
    double price;
    int quantity;

public:
    // Constructor
    Fruit(string n = "", double p = 0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    // Destructor
    ~Fruit() {
        cout << "Fruit Destructor: " << name << endl;
    }

    // Copy Constructor
    Fruit(const Fruit& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    // Copy Assignment Operator
    Fruit& operator=(const Fruit& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    double calculateSum() const {
        return price * quantity;
    }

    void display() const {
        cout << "Fruit: " << name
             << " | Price: PHP " << price
             << " | Quantity: " << quantity
             << " | Total: PHP " << calculateSum()
             << endl;
    }
};

class Vegetable {
private:
    string name;
    double price;
    int quantity;

public:
    // Constructor
    Vegetable(string n = "", double p = 0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    // Destructor
    ~Vegetable() {
        cout << "Vegetable Destructor: " << name << endl;
    }

    // Copy Constructor
    Vegetable(const Vegetable& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    // Copy Assignment Operator
    Vegetable& operator=(const Vegetable& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    double calculateSum() const {
        return price * quantity;
    }

    void display() const {
        cout << "Vegetable: " << name
             << " | Price: PHP " << price
             << " | Quantity: " << quantity
             << " | Total: PHP " << calculateSum()
             << endl;
    }
};

double TotalSum(Fruit* fruits[], int fruitCount,
                Vegetable* vegetables[], int vegCount) {

    double total = 0;

    for (int i = 0; i < fruitCount; i++) {
        if (fruits[i] != NULL)
            total += fruits[i]->calculateSum();
    }

    for (int i = 0; i < vegCount; i++) {
        if (vegetables[i] != NULL)
            total += vegetables[i]->calculateSum();
    }

    return total;
}

int main() {

    Fruit* GroceryFruits[2];
    Vegetable* GroceryVegetables[2];

    GroceryFruits[0] = new Fruit("Apple", 10, 7);
    GroceryFruits[1] = new Fruit("Banana", 10, 8);

    GroceryVegetables[0] = new Vegetable("Broccoli", 60, 12);
    GroceryVegetables[1] = new Vegetable("Lettuce", 50, 10);

    cout << "===== Jenna's Grocery List =====\n\n";

    for (int i = 0; i < 2; i++)
        GroceryFruits[i]->display();

    for (int i = 0; i < 2; i++)
        GroceryVegetables[i]->display();

    cout << "\n==============================\n";
    cout << "Total Amount = PHP "
         << TotalSum(GroceryFruits, 2, GroceryVegetables, 2)
         << endl;

    cout << "\nDeleting Lettuce...\n";
    delete GroceryVegetables[1];
    GroceryVegetables[1] = NULL;

    cout << "\nTotal After Removing Lettuce = PHP "
         << TotalSum(GroceryFruits, 2, GroceryVegetables, 2)
         << endl;

    return 0;
}

