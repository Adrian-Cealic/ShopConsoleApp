//imports
#include "Menu.h"
#include "Cart.h"
//libraries
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <regex>
#include <limits>
#include <stdexcept>



//namespace
using namespace std;

Cart cart;
//view product
void viewProduct() {
    for (int i = 0;i < PRODUCT_COUNT;i++) {
        cout << products[i];
    }
}
//view cart
void viewCart() {
    cart.viewCart();
}

bool isValidNonNegativeInteger(const string& input) {
    regex integerPattern("^\\d+$"); 
    return regex_match(input, integerPattern);
}
//buy product
void buyProduct() {

    string input;
    int id, qty;
    regex integerPattern("^\\d+$");

   cout << "Enter product id to buy: ";
   getline(cin, input);

    if (isValidNonNegativeInteger(input)) {
        try {
            id = stoi(input); 
        }
        catch (const out_of_range& e) {
            cout << "Product ID out of range. Please enter a valid product ID.\n";
            //cout << e.what();
            return; 
        }
        catch (const invalid_argument& e) { 
            cout << "Invalid input for product ID. Please enter a valid integer.\n";
            return; 
        }
    }
    else {
        cout << "Invalid input. Please enter a valid product ID.\n";
        return; 
    }

    cout << "Enter quantity: ";
    getline(cin, input);

    if (isValidNonNegativeInteger(input)) {
        try {
            qty = stoi(input);
        }
        catch (const out_of_range& e) {
            cout << "Quantity out of range. Please enter a valid quantity.\n";
            return;
        }
        catch (const invalid_argument& e) {
            cout << "Invalid input for quantity. Please enter a valid integer.\n";
            return; 
        }
    }
    else {
        cout << "Invalid input. Please enter a valid quantity.\n";
        return;
    }

    bool productFound = false;
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        if (products[i].getId() == id) {
            if (products[i].getQty() >= qty) {
                cart.addProduct(products[i], qty);
                products[i].setQty(products[i].getQty() - qty);
            }
            else {
                cout << "Not enough stock available\n";
            }
            productFound = true;
            break;
        }
    }
    if (!productFound) {
        cout << "Product not found\n";
    }
}

//clear cart
void static clearCart() {
    cart.clearCart();
    cout << "Thank you for buying!\n";
}


//show menu
void menu(){

    initProducts();

    while (true) {
        system("cls");
        cout << "-----Menu-----\n";
        cout << "1. View Products\n";
        cout << "2. Buy Product\n";
        cout << "3. View Cart\n";
        cout << "4. Go to checkout\n";
        cout << "5. Exit\n";
        cout << "Alege o optiune:\n ";

        switch (_getch()) {
        case '1':
            // view product
            viewProduct();
            break;
        case '2':
            // buy product
            buyProduct();
            break;
        case '3':
            // view cart
            viewCart();
            break;
        case '4':
            clearCart();
            break;  
        case '5':
            exit(0);
            break;
        default:
            cout << "Optiune invalida, incearca din nou (1-4)\n";
            break;
        }

        cout << "\nPress any key to return to the menu.";
        _getch();
    }
}
