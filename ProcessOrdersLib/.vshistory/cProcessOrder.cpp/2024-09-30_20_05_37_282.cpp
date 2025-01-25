#include "cProcessOrder.h"

cProcessOrder::cProcessOrder() {

}

cProcessOrder::~cProcessOrder() {

}


void cProcessOrder::AddToCart(cProducts* product) {
	orderItems.push_back(product);
}

double cProcessOrder::CalculateOrderTotal() {
	double orderTotalWithoutTaxAndDiscount = 0.0;
	for (int itemIndex = 0; itemIndex != sizeof(orderItems); itemIndex++) {
		orderTotalWithoutTaxAndDiscount += orderItems[itemIndex]->productPrice;
	}
	double orderTotal = orderTotalWithoutTaxAndDiscount * orderQty * orderDiscount * orderTax;
	return orderTotal;
}
