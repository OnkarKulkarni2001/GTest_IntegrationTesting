#include "pch.h"
#include "cProcessOrder.h"

cProcessOrder::cProcessOrder() {

}

cProcessOrder::~cProcessOrder() {

}


bool cProcessOrder::AddToCart(cProducts* product) {
	orderItems.push_back(product);
	return true;
}

bool cProcessOrder::IsAddedToCart(cProducts* product)
{
	for (vector<cProducts*>::iterator productIterator = orderItems.begin(); productIterator != orderItems.end(); productIterator++) {
		if (*productIterator == product) {
			return true;
			break;
		}
	}
	return false;
}



double cProcessOrder::CalculateOrderTotal() {
	double orderTotalWithoutTaxAndDiscount = 0.0;
	for (int itemIndex = 0; itemIndex != sizeof(orderItems); itemIndex++) {
		orderTotalWithoutTaxAndDiscount += orderItems[itemIndex]->productPrice;
	}
	double orderTotal = orderTotalWithoutTaxAndDiscount * orderQty * orderDiscount * orderTax;
	return orderTotal;
}
