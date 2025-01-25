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

	//cProcessOrder();
	//~cProcessOrder();

	__declspec(dllexport) bool AddToCart(cProducts* product);
	__declspec(dllexport) bool IsAddedToCart(cProducts* product);
	__declspec(dllexport) double CalculateOrderTotal();
	__declspec(dllexport) bool RemoveOrderItemsByProductID(int productID);
};