#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class Products{
private:
    string productName;
    string productCategory;
    string productDescription;
    int amountInStore;
    float regularPrice;
    float discountRate;
public:
    Products(string name = "", string category = "", string description = "", int amount = 0, float price = 0.0, float discount = 0.0)
        : productName(name), productCategory(category), productDescription(description), amountInStore(amount), regularPrice(price), discountRate(discount) {}


    string getProductName() const;
    void setProductName(string name);
    string getProductCategory() const;
    void setProductCategory(string category);
    string getProductDescription() const;
    void setProductDescription(string description);
    int getAmountInStore() const;
    void setAmountInStore(int amount);
    float getRegularPrice() const;
    void setRegularPrice(float price);
    float getDiscountRate() const;
    void setDiscountRate(float discount);

    void PurchaseProduct(int amount);
    void RestockProduct(int amount);

    float calculateDiscount(int amountOfProducts) const;
    float netTotal(int amountOfProducts) const;

};


void EditInformationByKeyboard(Products& p);
void generateInformationRandom(Products& p);

void ShowAllDiscount(Products ar[], int size);

void grossTotal(Products ar[], int size);