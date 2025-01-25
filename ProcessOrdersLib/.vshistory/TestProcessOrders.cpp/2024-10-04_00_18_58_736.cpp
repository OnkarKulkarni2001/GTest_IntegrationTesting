#include "pch.h"
#include "gtest/gtest.h"
#include "cProcessOrder.h"
#include "../ProductsLib/cProducts.h"

class cProcessOrdersTestFixture : public testing::Test {
protected:
	cProcessOrder order;
	cProducts* goodProduct;
	cProducts* badProduct;
	cProducts* discountedProduct;

	void SetUp() {
		goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 1.0, true);
		badProduct = new cProducts(420, "Bad Product", "Bad Description", -1, 27.99, 1.0, false);
		discountedProduct = new cProducts(20, "Discounted Product", "Cheaper than usual", 10, 129.99, 0.9, true);
	}

	virtual void TearDown() {
		delete goodProduct;
		delete badProduct;
		delete discountedProduct;
	}
};

TEST_F(cProcessOrdersTestFixture, AddToCart_GoodProduct) {

	EXPECT_TRUE(order.AddToCart(goodProduct));
	EXPECT_TRUE(order.IsAddedToCart(goodProduct));
}

TEST_F(cProcessOrdersTestFixture, AddToCart_BadProduct) {

	EXPECT_FALSE(order.AddToCart(badProduct));
	EXPECT_FALSE(order.IsAddedToCart(badProduct));
}

TEST_F(cProcessOrdersTestFixture, CalculateOrderTotal_GoodProduct) {

	order.AddToCart(goodProduct);
	order.orderQty = 5;

	EXPECT_EQ(order.CalculateOrderTotal(), 334.68622499999998);
}

TEST_F(cProcessOrdersTestFixture, CalculateOrderTotal_DiscountedProduct) {

	order.AddToCart(discountedProduct);
	order.orderQty = 9;

	EXPECT_EQ(order.CalculateOrderTotal(), 1011.3286995);
}

TEST_F(cProcessOrdersTestFixture, CalculateOrderTotal_BadProduct) {

	order.AddToCart(badProduct);
	order.orderQty = -1;

	EXPECT_EQ(order.CalculateOrderTotal(), 0);
}


//extern "C" __declspec(dllexport) void RunTests() {
//	testing::InitGoogleTest();
//	RUN_ALL_TESTS();
//}