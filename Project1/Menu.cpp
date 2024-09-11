//imports
#include "Menu.h"
#include "Cart.h"
//libraries
#include <iostream>
#include <conio.h>
#include <stdlib.h>

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
//buy product
void buyProduct() {
    int id, qty;
    cout << "Enter product id to buy: ";
    cin >> id;
    cout << "Enter quantity: ";
    cin >> qty;

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
