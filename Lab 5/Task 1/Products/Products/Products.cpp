// Products.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"PRODUCTS.h"

//////////////////////////////////////////////////////////////////////////////////////////////////

// Getter and Setter Methods for the 6 variables..
string Products:: getProductName() const { return productName; }
void Products::setProductName(string name) { productName = name; }

string Products::getProductCategory() const { return productCategory; }
void Products::setProductCategory(string category) { productCategory = category; }

string Products::getProductDescription() const { return productDescription; }
void Products::setProductDescription(string description) { productDescription = description; }

int Products::getAmountInStore() const { return amountInStore; }
void Products::setAmountInStore(int amount) { amountInStore = amount; }

float Products::getRegularPrice() const { return regularPrice; }
void Products::setRegularPrice(float price) { regularPrice = price; }

float Products::getDiscountRate() const { return discountRate; }
void Products::setDiscountRate(float discount) { discountRate = discount; }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Purchase Product and Restock Product
void Products::PurchaseProduct(int amount) {
    if (amount > amountInStore) {
        cout << "Not enough stock available.\n";
    }
    else {
        amountInStore -= amount;
        cout << "Purchased " << amount << " units.\n";
    }
}

void Products::RestockProduct(int amount) {
    amountInStore += amount;
    cout << "Restocked " << amount << " units.\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// Calculate Discount
float Products::calculateDiscount(int amountOfProducts) const {
    float discount = 0;
    if (amountOfProducts >= 5) {
        discount += discountRate;
        if (amountOfProducts >= 10) {
            discount += (float)3.0; // Additional 3% discount
        }
    }
    return ((regularPrice * (float)amountOfProducts * discount) / 100);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Calculate Net Total using the calculateDiscount Function to calculate Discount.
float Products::netTotal(int amountOfProducts) const {
    float discountAmount = calculateDiscount(amountOfProducts);
    float totalCost = regularPrice * (float)amountOfProducts;
    return totalCost - (float)discountAmount;
}

// Manually input the parameters. This function is used for the first 2 objects. Non-member function
void EditInformationByKeyboard(Products& p) {
    string name, category, description;
    int amount;
    float price, discount;

    cout << "Enter Product Name: ";
    cin >> name;
    cout << "Enter Product Category: ";
    cin >> category;

    cout << "Enter Product Description: ";
    cin.ignore();
    getline(cin, description);

    cout << "Enter Amount in Store: ";
    cin >> amount;
    cout << "Enter Regular Price: ";
    cin >> price;
    cout << "Enter Discount Rate: ";
    cin >> discount;

    p.setProductName(name);
    p.setProductCategory(category);
    p.setProductDescription(description);
    p.setAmountInStore(amount);
    p.setRegularPrice(price);
    p.setDiscountRate(discount);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function to generate random information. This function is used to generate random info for the remaining products..
void generateInformationRandom(Products& p) {
    p.setProductName("Product" + to_string(rand() % 100));
    p.setProductCategory("Category" + to_string(rand() % 100));
    p.setProductDescription("Description of Product " + to_string(rand() % 100));
    p.setAmountInStore(rand() % 100);
    p.setRegularPrice((float)(rand() % 500) + 50);
    p.setDiscountRate((float)(rand() % 13) + 3);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Show Discount for all products. 
void ShowAllDiscount(Products ar[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Discount for " << ar[i].getProductName() << ": " << ar[i].calculateDiscount(10) << " BDT\n";
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function to calculate gross total for all products
void grossTotal(Products ar[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        int amountToPurchase = rand() % 20 + 1;
        float total = ar[i].netTotal(amountToPurchase);
        cout << "Net total for " << ar[i].getProductName() << ": " << total << " BDT\n";
        sum += total;
    }
    cout << "Total cost for all products: " << sum << " BDT\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
