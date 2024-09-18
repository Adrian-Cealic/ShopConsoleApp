#include "Menu.h"
#include "Cart.h"
#include "Cupon.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <regex>
#include <stdexcept>
#include <conio.h>

using namespace std;

Cart cart;

// Function to view products
void viewProduct() {
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        cout << products[i];
    }
}

// Function to view cart
void viewCart() {
    cart.viewCart();
    cout << "\n---TOTAL PRICE----\n";
    cout << cart.totalPrice();
}

// Validate non-negative integer input
bool isValidNonNegativeInteger(const string& input) {
    regex integerPattern("^\\d+$");
    return regex_match(input, integerPattern);
}

// Function to buy a product
void buyProduct() {
    string input;
    int id, qty;

    cout << "Enter product id to buy: ";
    getline(cin, input);
    if (isValidNonNegativeInteger(input)) {
        try {
            id = stoi(input);
        }
        catch (const out_of_range& e) {
            cout << "Product ID out of range. Please enter a valid product ID.\n";
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

// Function to clear the cart
void clearCart() {
    cart.clearCart();
}

// Function to view offers
void viewOffers() {
    cout << "-----Offers------\n";
    cout << "FREE SHIPPING FOR PRODUCTS OVER " << FREE_SHIPPING << " USD\n";
}

// Function to go to checkout
void goToCheckout() {
    float originalTotal = cart.totalPrice(); 
    float discountedTotal = originalTotal;  
    bool discountApplied = false;           

    while (true) {
        system("cls");
        cout << "------Checkout-------\n";
        cout << "1. Buy.\n";
        cout << "2. Enter promo code.\n";
        cout << "Total: " << discountedTotal << "\n";

        if (discountedTotal >= FREE_SHIPPING) {
            cout << "Congratulations! You qualify for free shipping!" << endl;
        }
        else {
            cout << "You need $" << (FREE_SHIPPING - discountedTotal) << " more to qualify for free shipping." << endl;
        }

        switch (_getch()) {
        case '1': {
            system("cls");
            clearCart();
            _getch();
            menu();
            return; 
        }
        case '2': {
            if (discountApplied) {
                cout << "A discount has already been applied.\n";
                break;
            }

            string promocode;
            cout << "Enter promo code: ";
            cin >> promocode;
            promocode = toUpperCase(promocode);
            if (promoCodes.find(promocode) != promoCodes.end()) {
                system("cls");
                float discount = promoCodes[promocode];
                if (discount == true) {
                    cout << "Promo code for free shipping applied!\n";
                }
                else {
                    cout << "Promo code has been redeemed! You get a " << (discount * 100) << "% discount!\n";
                    float discountAmount = originalTotal * discount;
                    discountedTotal -= discountAmount;
                }
                discountApplied = true; 
            }
            else {
                cout << "Invalid promo code.\n";
                cout << "Total: " << discountedTotal << " $" << endl;
            }
            break;
        }
        default:
            cout << "Invalid option. Try again (1-3)\n";
            break;
        }

        cout << "\nPress any key to return to the menu.";
        _getch();
    }
}



void validateCart() {
    if (cart.getCount() == 0) {
        cout << "Buy someting first!\n";
    }
    else {
        goToCheckout();
    }
}
void displayMenu(int currentOption) {
    string options[6] = { "View Products", "Buy Product", "View Cart","Go to checkout","View offers","Exit" };
    for (int i = 0; i < 6; i++) {
        if (i == currentOption) {
            cout << "> " << options[i] << endl; 
        }
        else {
            cout << "  " << options[i] << endl;
        }
    }
}
// Function to show the menu
void menu() {
    initProducts();

    int currentOption = 0;
    char key;
    do {
        system("cls"); 
        displayMenu(currentOption);

        key = _getch(); 

        // Up arrow
        if (key == 72) {
            if (currentOption > 0) currentOption--;
        }
        // Down arrow
        if (key == 80) {
            if (currentOption < 5) currentOption++;
        }

    } while (key != '\r');

    switch (currentOption)
    {
    case 0 : 
        system("cls");
        viewProduct();
        break;
    case 1:
        system("cls");
        buyProduct();
        break;
    case 2:
        system("cls");
        viewCart();
        break;
    case 3:
        system("cls");
        validateCart();
        break;
    case 4:
        system("cls");
        viewOffers();
        break;
    case 5:
        exit(0);
        break;
    default:
        cout << "Invalid option, try again (1-6)\n";
        break;
    }


    cout << "\nPress any key to return to the menu.";
    _getch();
    menu();


   /* while (true) {
        system("cls");
        cout << "-----Menu-----\n";
        cout << "1. View Products\n";
        cout << "2. Buy Product\n";
        cout << "3. View Cart\n";
        cout << "4. Go to checkout\n";
        cout << "5. View offers\n";
        cout << "6. Exit\n";
        cout << "Choose an option:\n ";
        switch (_getch()) {
        case '1':
            system("cls");
            viewProduct();
            break;
        case '2':
            system("cls");
            buyProduct();
            break;
        case '3':
            system("cls");
            viewCart();
            break;
        case '4':
            system("cls");
            validateCart();
            break;
        case '5':
            system("cls");
            viewOffers();
            break;
        case '6':
            exit(0);
            break;
        default:
            cout << "Invalid option, try again (1-6)\n";
            break;
        }

        cout << "\nPress any key to return to the menu.";
        _getch();
    }*/
}
