//abstract class
#include"Cart.h"

//libraries
#include<iostream>

using namespace std;

void Cart::addProduct(const Product& p, int qty) {
	for (int i = 0;i < count;i++) {
		if (items[i].product.getId() == p.getId()) {
			items[i].qty += qty;
			return;
		}
	}
	if (count < 100) {
		items[count++] = CartItem(p, qty);
	}
}
void Cart::viewCart()const {

	cout << "----CART----\n";
	for (int i = 0;i < count;i++) {
		cout << items[i].product.getName() << "-" << items[i].qty << " units\n";
	}

	int totalPrice = 0;
	cout << "\n---TOTAL PRICE----\n";
	for (int i = 0;i < count;i++) {
		totalPrice += items[i].product.getPrice() * items[i].qty;
	}
	cout << totalPrice;
}

void Cart::clearCart() {
	count = 0;
}



