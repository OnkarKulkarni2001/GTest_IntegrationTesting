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
		cProcessOrder order;
	}
};

TEST(cProcessOrdersTestFixture, AddToCart_GoodProduct) {
	cProcessOrder order;
	cProducts* goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 1.0, true);

	EXPECT_TRUE(order.AddToCart(goodProduct));
	EXPECT_TRUE(order.IsAddedToCart(goodProduct));
}

TEST(cProcessOrdersTestFixture, AddToCart_BadProduct) {
	cProcessOrder order;
	cProducts* badProduct = new cProducts(420, "Bad Product", "Bad Description", 24, 27.99, 1.0, false);

	EXPECT_FALSE(order.AddToCart(badProduct));
	EXPECT_FALSE(order.IsAddedToCart(badProduct));
}

TEST(cProcessOrdersTestFixture, CalculateOrderTotal_GoodProduct) {
	cProcessOrder order;
	cProducts* goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 1.0, true);
	order.AddToCart(goodProduct);
	order.orderQty = 5;

	EXPECT_EQ(order.CalculateOrderTotal(), 334.68622499999998);
}

TEST(cProcessOrdersTestFixture, CalculateOrderTotal_DiscountedProduct) {
	cProcessOrder order;
	cProducts* discountedProduct = new cProducts(20, "Discounted Product", "Cheaper than usual", 10, 129.99, 0.9, true);
	order.AddToCart(discountedProduct);
	order.orderQty = 9;

	EXPECT_EQ(order.CalculateOrderTotal(), 1011.3286995);
}

TEST(cProcessOrdersTestFixture, CalculateOrderTotal_BadProduct) {
	cProcessOrder order;
	cProducts* badProduct = new cProducts(420, "Bad Product", "Bad Description", 24, 27.99, 1.0, false);
	order.AddToCart(badProduct);
	order.orderQty = -1;

	EXPECT_EQ(order.CalculateOrderTotal(), 0);
}


extern "C" __declspec(dllexport) void RunTests() {
	testing::InitGoogleTest();
	RUN_ALL_TESTS();
}