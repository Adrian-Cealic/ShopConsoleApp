#pragma once
//imports
#include"Product.h"

#ifndef CART_H
#define CART_H

//namespace
using namespace std;


class CartItem {
public:
    Product product;
    int qty;
    CartItem(Product p = Product(), int qty = 0) : product(p), qty(qty) {}
};

class Cart {
private:
    CartItem items[100];
    int count;
public:
    Cart() :count(0) {}
    void addProduct(const Product& p, int qty);
    void viewCart()const;
    void clearCart();
};
#endif
