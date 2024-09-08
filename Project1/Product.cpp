#include "Product.h"
#include <iostream>
#include <iomanip>
using namespace std;

const int PRODUCT_COUNT = 10;
Product products[PRODUCT_COUNT];

// Constructor
Product::Product(int id, string name, int price, int qty) :id(id), name(name), price(price), qty(qty) {}
// Destructor
Product::~Product() {}

void initProducts() {
    for (int i = 0;i < PRODUCT_COUNT;i++) {
        products[i] = Product(i + 1, "Product " + to_string(i + 1), 100 + i * 4, 10);
    }
}

// toString method
void Product::toString() {
    cout << left << setw(15) << name
        << right << setw(10) << price << "$"
        << right << setw(10) << qty << " units" << endl;
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
ostream& operator<<(ostream& COUT, Product& p) {
    COUT << p.name << " " << p.price << "$ " << p.qty << " units" << endl;
    return COUT;
}

istream& operator>>(istream& IN, Product& p) {
    cout << "Nume produs: "; getline(IN, p.name);
    cout << "Pret produs: "; IN >> p.price;
    cout << "Cantitatea produs: "; IN >> p.qty;
    IN.ignore();
    return IN;
}
