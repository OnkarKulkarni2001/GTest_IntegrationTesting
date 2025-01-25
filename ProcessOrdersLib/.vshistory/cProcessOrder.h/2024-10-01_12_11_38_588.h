#pragma once
#include "../ProductsLib/cProducts.h"
#include <vector>

using namespace std;

class cProcessOrder {
public:
	int orderID;
	int orderQty;
	double orderTax = 1.13;
	double orderDiscount = 0.85;

	vector<cProducts> orderItems;

	cProcessOrder();
	~cProcessOrder();

	void AddToCart(cProducts* product);
	bool IsAddedToCart(cProducts& product);
	double CalculateOrderTotal();
};