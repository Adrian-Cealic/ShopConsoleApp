//imports
#include "Product.h"
//libraries
#include <iostream>
#include <iomanip>
using namespace std;
//constants
const int PRODUCT_COUNT = 10;
Product products[PRODUCT_COUNT];

// Constructor
Product::Product(int id, string name, int price, int qty) :id(id), name(name), price(price), qty(qty) {}
// Destructor
Product::~Product() {}

//initialize products
void initProducts() {
    string fragranceNames[PRODUCT_COUNT] = {
        "Dior Sauvage", "Chanel No. 5", "YSL Black Opium", "Gucci Bloom", "Tom Ford Oud Wood",
        "Creed Aventus", "Versace Eros", "Armani Acqua Di Gio", "Prada Luna Rossa", "Jo Malone Peony & Blush"
    };

    for (int i = 0; i < PRODUCT_COUNT; i++) {
        products[i] = Product(i + 1, fragranceNames[i], 100 + i * 20, 10);
    }
}


// Setters
void Product::setName(string name) { this->name = name; }
void Product::setPrice(int price) { this->price = price; }
void Product::setQty(int qty) { this->qty = qty; }
// Getters
const int Product::getId()const { return id; }
const string Product::getName() const { return name; }
const int Product::getPrice() const { return price; }
const int Product::getQty() const { return qty; }

// Stream operator overloads
//output overload
ostream& operator<<(ostream& COUT,Product& p) {
    COUT << "==========================" << endl;
    COUT << "    Product Details" << endl;
    COUT << "==========================" << endl;
    COUT << "Name       : " << p.name << endl;
    COUT << "Price      : $" << p.price << endl;
    COUT << "Quantity   : " << p.qty << " units" << endl;
    COUT << "==========================" << endl;
    return COUT;
}
//input overload
istream& operator>>(istream& IN, Product& p) {
    cout << "Nume produs: "; getline(IN, p.name);
    cout << "Pret produs: "; IN >> p.price;
    cout << "Cantitatea produs: "; IN >> p.qty;
    IN.ignore();
    return IN;
}
