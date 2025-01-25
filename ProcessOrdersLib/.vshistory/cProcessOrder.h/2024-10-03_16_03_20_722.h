#pragma once
#include "../ProductsLib/cProducts.h"
#include <vector>

using namespace std;

class cProcessOrder {
public:
	int orderID = 1;
	int orderQty = 1;
	double orderTax = 1.13;
	double orderDiscount = 0.85;

	vector<cProducts*> orderItems;

	cProcessOrder();
	~cProcessOrder();

	bool AddToCart(cProducts* product);
	bool IsAddedToCart(cProducts* product);
	double CalculateOrderTotal();
	int RemoveOrderItemsByProductID(int productID);
};