#include "pch.h"
#include "cProducts.h"
#include <iostream>

using namespace std;

cProducts::cProducts(int productID, string productName, string productDescription, int productQty, double productPrice, double productDiscount, bool bIsProductAvailable) {
	this->productID = productID;
	this->productName = productName;
	this->productDescription = productDescription;
	this->productPrice = productPrice;
	this->productDiscount = productDiscount;
	this->productQty = productQty;
	this->bIsProductAvailable = bIsProductAvailable;
	cout << "New product created with ID: " << productID << endl;
}

cProducts::~cProducts() {

}

void cProducts::GetProductDetails(int productID, double& productPrice, double& productDiscount) {
	this->productPrice = productPrice;
	this->productDiscount = productDiscount;
	cout << "Product Details:\nID: " << productID
		<< "\nProduct Name : " << productName
		<< "\nProduct Description : " << productDescription
		<< "\nProduct Quantity : " << productQty
		<< "\nProduct Price : " << productPrice
		<< "\nProduct Discount : " << productDiscount
		<< "\nProduct Availabilty : " << bIsProductAvailable << endl;
}

int cProducts::UpdateStock(int& productQty) {
	this->productQty += productQty;
	return this->productQty;
}