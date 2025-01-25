#include "pch.h"
#include "cProcessOrder.h"
#include <iostream>

cProcessOrder::cProcessOrder() {

}

cProcessOrder::~cProcessOrder() {

}


bool cProcessOrder::AddToCart(cProducts* product) {
	if (product->bIsProductAvailable == true) {
		orderItems.push_back(product);
		return true;
	}
	return false;
}

bool cProcessOrder::IsAddedToCart(cProducts* product)
{
	for (vector<cProducts*>::iterator productIterator = orderItems.begin(); productIterator != orderItems.end(); productIterator++) {
		if (*productIterator == product) {
			return true;
		}
	}
	return false;
}



double cProcessOrder::CalculateOrderTotal() {
	double orderTotalWithoutTaxAndDiscount = 0.0;
	double orderTotal = 0.0;
	if (orderItems.empty()) {
		return orderTotal;
	}
	else {
		for (vector<cProducts*>::iterator productIterator = orderItems.begin(); productIterator != orderItems.end(); productIterator++) {
			orderTotalWithoutTaxAndDiscount += (*productIterator)->productPrice;
			cout << (*productIterator);
		}
		orderTotal = orderTotalWithoutTaxAndDiscount * orderQty * orderDiscount * orderTax;
		return orderTotal;
	}
}
