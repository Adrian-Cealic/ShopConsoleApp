#include"Cart.h"
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
}


void Cart::clearCart() {
	count = 0;
}



