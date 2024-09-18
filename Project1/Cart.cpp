//abstract class
#include"Cart.h"

//libraries
#include<iostream>

using namespace std;

void Cart::addProduct(const Product& p, int qty) {
	for (int i = 0;i < itemCount;i++) {
		if (items[i].product.getId() == p.getId()) {
			items[i].qty += qty;
			return;
		}
	}
	if (itemCount < 100) {
		items[itemCount++] = CartItem(p, qty);
	}
}
void Cart::viewCart()const {

	cout << "----CART----\n";
	for (int i = 0;i < itemCount;i++) {
		cout << items[i].product.getName() << "-" << items[i].qty << " units\n";
	}
}

float Cart::totalPrice()const {
	float totalPrice = 0.0f;
	for (int i = 0;i < itemCount;i++) {
		totalPrice += items[i].product.getPrice() * items[i].qty;
	}
	return totalPrice;
}
void Cart::clearCart() {
	itemCount = 0;
	cout << "Thank you for buying!\n";
}
int Cart::getCount() const {
	return itemCount;
}



