#include "pch.h"
#include "cProcessOrder.h"

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
	if (orderItems.empty()) {
		return 0.0; 
	}

	for (vector<cProducts*>::iterator productIterator = orderItems.begin(); productIterator != this->orderItems.end(); productIterator++) {
		orderTotalWithoutTaxAndDiscount += (*productIterator)->productPrice;
	}
	double orderTotal = orderTotalWithoutTaxAndDiscount * orderQty * orderDiscount * orderTax;
	return orderTotal;
}
