#pragma once
#include<iostream>
#include<string>
#ifndef PRODUCT_H
#define PRODUCT_H


using namespace std;


class Product {
private:
    int id;
    string name;
    int price;
    int qty;

public:
    Product(int id = 0, string name = "", int price = 0, int qty = 0);
    ~Product();

    // toString method
    void toString();

    // Setters and Getters
    void setName(string name);
    void setPrice(int price);
    void setQty(int qty);

    const int getId() const;
    const string getName() const;
    const int getPrice() const;
    const int getQty() const;

    // Friend function declarations for stream operators
    friend ostream& operator<<(ostream& OUT, Product& p);
    friend istream& operator>>(istream& IN, Product& p);
};
void initProducts();

extern const int PRODUCT_COUNT;
extern Product products[];

#endif
