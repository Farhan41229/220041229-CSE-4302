#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include"PRODUCTS.h"
using namespace std;

int main() {
    ////////////////////////////////////////////////////////////////////////////////////////////////
        // Creating 100 products
    Products products[100];
    ////////////////////////////////////////////////////////////////////////////////////////////////

        // Manually insert first 2 products
    for (int i = 0; i < 2; i++) {
        EditInformationByKeyboard(products[i]);
    }

    // Randomly generate information for the rest
    for (int i = 2; i < 100; i++) {
        generateInformationRandom(products[i]);
    }

    // Show discounts
    ShowAllDiscount(products, 100);

    // Show gross total
    grossTotal(products, 100);

    return 0;
}
