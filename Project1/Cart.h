#pragma once
//imports
#include"Product.h"
#include<string>

#ifndef CART_H
#define CART_H

const int FREE_SHIPPING = 150;
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
    int itemCount;
public:
    Cart() :itemCount(0) {}
    int getCount()const;
    void addProduct(const Product& p, int qty);
    void viewCart()const;
    void clearCart();
    float totalPrice()const;
};
#endif
