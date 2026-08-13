#include <iostream>
#include <string>

// Base Class to allow storing both Fruit and Vegetable in one array
class Groceries {
protected:
    std::string type;
    std::string name;
    double price;
    int quantity;

public:
    // Constructor
    Groceries(std::string T = "", std::string N = "", double P = 0.0, int Q = 0)
        : type(T), name(N), price(P), quantity(Q) {}

    // Virtual Destructor (essential for base classes with virtual methods)
    virtual ~Groceries() {
        std::cout << name << " has been bagged." << std::endl;
    }

    // Copy Constructor
    Groceries(const Groceries &copyGroceries)
        : type(copyGroceries.type), name(copyGroceries.name), 
          price(copyGroceries.price), quantity(copyGroceries.quantity) {}

    // Copy Assignment Operator
    Groceries& operator=(const Groceries& copyGroceries) {
        if (this != &copyGroceries) {
            type = copyGroceries.type;
            name = copyGroceries.name;
            price = copyGroceries.price;
            quantity = copyGroceries.quantity;
        }
        return *this;
    }

    // Calculate total price for this item
    virtual double calculateSum() const {
        return price * quantity;
    }

    // Display item details
    virtual void ScannedItems() const {
        std::cout << "Type: " << type << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Price: PHP " << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "Total: PHP " << calculateSum() << std::endl;
        std::cout << std::endl;
    }
};

// Problem 1: Fruit Class
class Fruit : public Groceries {
public:
    // Constructor
    Fruit(std::string name = "", double price = 0.0, int quantity = 0)
        : Groceries("Fruit", name, price, quantity) {}

    // Destructor
    ~Fruit() override {}

    // Copy Constructor
    Fruit(const Fruit &copyFruit) : Groceries(copyFruit) {}

    // Copy Assignment Operator
    Fruit& operator=(const Fruit& copyFruit) {
        if (this != &copyFruit) {
            Groceries::operator=(copyFruit);
        }
        return *this;
    }
};

// Problem 1: Vegetable Class
class Vegetable : public Groceries {
public:
    // Constructor
    Vegetable(std::string name = "", double price = 0.0, int quantity = 0)
        : Groceries("Vegetable", name, price, quantity) {}

    // Destructor
    ~Vegetable() override {}

    // Copy Constructor
    Vegetable(const Vegetable &copyVegetable) : Groceries(copyVegetable) {}

    // Copy Assignment Operator
    Vegetable& operator=(const Vegetable& copyVegetable) {
        if (this != &copyVegetable) {
            Groceries::operator=(copyVegetable);
        }
        return *this;
    }
};

// Problem 3: Calculate sum of all objects in Jenna's Grocery List
double TotalSum(Groceries* GroceryList[], int groceries) {
    double total = 0.0;

    for (int i = 0; i < groceries; i++) {
        if (GroceryList[i] != nullptr) {
            total += GroceryList[i]->calculateSum();
        }
    }
    return total;
}

int main() {
    // Problem 2: GroceryList array storing instances
    Groceries* GroceryList[4];

    GroceryList[0] = new Fruit("Apple", 10.0, 7);
    GroceryList[1] = new Fruit("Banana", 10.0, 8);
    GroceryList[2] = new Vegetable("Broccoli", 60.0, 12);
    GroceryList[3] = new Vegetable("Lettuce", 50.0, 10);

    std::cout << "~~~~~Jiro's Grocery List~~~~~\n\n";

    // Display all items
    for (int i = 0; i < 4; i++) {
        if (GroceryList[i] != nullptr) {
            GroceryList[i]->ScannedItems();
        }
    }

    std::cout << "Total Cost: PHP " << TotalSum(GroceryList, 4) << std::endl;

    // Problem 4: Delete Lettuce and de-allocate memory
    delete GroceryList[3];
    GroceryList[3] = nullptr; // Prevents dangling pointer

    std::cout << "\nAfter deleting Lettuce:" << std::endl;
    std::cout << "Updated Total Cost: PHP " << TotalSum(GroceryList, 4) << std::endl;

    // Clean up remaining allocated memory
    for (int i = 0; i < 3; i++) {
        if (GroceryList[i] != nullptr) {
            delete GroceryList[i];
            GroceryList[i] = nullptr;
        }
    }

    return 0;
}   

