#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    int id;
    float price;
    int quantity;
    int maxQuantity;

public:
    Product(string n, int i, float p, int q, int maxQ) {
        name = n;
        id = i;
        price = p;
        quantity = q;
        maxQuantity = maxQ;
    }

    void addToInventory(int addedQuantity) {
        if (quantity + addedQuantity <= maxQuantity) {
            quantity += addedQuantity;
        } else {
            cout << "Cannot add beyond max quantity!" << endl;
        }
    }

    bool isAvailable() {
        return quantity > 0;
    }

    void purchase(int purchasedQuantity) {
        if (isAvailable() && purchasedQuantity <= quantity) {
            quantity -= purchasedQuantity;
        } else {
            cout << "Purchase failed: Not enough stock or unavailable!" << endl;
        }
    }

    void updatePrice(int discountPercent) {
        price -= (price * discountPercent) / 100;
    }

    void displayInventoryValue() {
        cout << "Total value of " << name << " in inventory: " << quantity * price << endl;
    }

    void displayDetails() {
        cout << "Product Details:\n";
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Available: " << (isAvailable() ? "Yes" : "No") << endl;
    }

    float calculateInventoryValue() {
        return quantity * price;
    }

    static void displayTotalInventoryValue(Product products[], int size) {
        float totalValue = 0;
        for (int i = 0; i < size; i++) {
            totalValue += products[i].calculateInventoryValue();
        }
        cout << "Total inventory value of all products: " << totalValue << endl;
    }
};

int main() {
    // Initializing products
    Product product1("Laptop", 101, 1500, 10, 50);
    Product product2("Phone", 102, 800, 20, 100);
    Product product3("Tablet", 103, 600, 15, 70);


    product1.addToInventory(5);
    product2.addToInventory(10);
    product3.addToInventory(8);

    product1.purchase(3);
    product2.purchase(5);
    product3.purchase(7);


    product1.updatePrice(5);
    product2.updatePrice(10);
    product3.updatePrice(15);


    product1.displayDetails();
    product1.displayInventoryValue();
    product2.displayDetails();
    product2.displayInventoryValue();
    product3.displayDetails();
    product3.displayInventoryValue();


    Product products[] = {product1, product2, product3};
    Product::displayTotalInventoryValue(products, 3);

    return 0;
}
