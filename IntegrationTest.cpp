#include "pch.h"
#include "../ProcessOrdersLib/cProcessOrder.h"
#include "../ProductsLib/cProducts.h"
#include <gtest/gtest.h>
class integrationTestFixture : public testing::Test {
public:
	cProcessOrder order;
	cProducts* goodProduct;
	cProducts* badProduct;
	cProducts* discountedProduct;

	void SetUp() {
		goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 1.0, true);
		badProduct = new cProducts(420, "Bad Product", "Bad Description", -1, 27.99, 1.0, false);
		discountedProduct = new cProducts(20, "Discounted Product", "Cheaper than usual", 10, 129.99, 0.9, true);
		order;
	}

	void TearDown() {
		delete goodProduct;
		delete badProduct;
		delete discountedProduct;
	}
};

TEST_F(integrationTestFixture, SetAvailability_IsAddedToCart_GoodProduct) {
	//Setup();
	EXPECT_FALSE(goodProduct->SetAvailability(order.IsAddedToCart(goodProduct)));
}

TEST_F(integrationTestFixture, SetAvailability_IsAddedToCart_BadProduct) {
	EXPECT_FALSE(badProduct->SetAvailability(order.IsAddedToCart(badProduct)));
}

TEST_F(integrationTestFixture, RemoveOrderItemsByProductID_GetProductID_BadProduct) {
	order.AddToCart(badProduct);
	order.orderQty = -1;
	EXPECT_FALSE(order.RemoveOrderItemsByProductID(badProduct->GetProductID(badProduct)));
}

TEST_F(integrationTestFixture, RemoveOrderItemsByProductID_GetProductID_GoodProduct) {
	//order.AddToCart(goodProduct);
	EXPECT_FALSE(order.RemoveOrderItemsByProductID(101/*goodProduct->GetProductID(goodProduct)*/));
}

TEST_F(integrationTestFixture, RemoveOrderItemsByProductID_GetProductID_DiscountedProduct) {
	order.AddToCart(discountedProduct);
	EXPECT_TRUE(order.RemoveOrderItemsByProductID(discountedProduct->GetProductID(discountedProduct)));
}