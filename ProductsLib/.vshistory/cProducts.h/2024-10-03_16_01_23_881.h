#pragma once
#include <string>

using namespace std;

class cProducts {

public:
	string productName;
	string productDescription;

	int productID;
	int productQty;
	double productPrice;
	double productDiscount;

	bool bIsProductAvailable;

	cProducts(int productID, string productName, string productDescription, int productQty, double productPrice, double productDiscount = 0.90, bool bIsProductAvailable = false);
	~cProducts();

	//void GetProductDetails(int productID, double& productPrice, double& productDiscount);
	bool SetAvailability(bool bIsAvailable);
	int SetProductQty(int productQty);
	void SetPrice(double productPrice);
	double GetPrice(double productID);
	int GetProductID(cProducts* product);
};