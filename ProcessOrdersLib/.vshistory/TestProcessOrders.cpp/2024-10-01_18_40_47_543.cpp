#include "pch.h"
#include "gtest/gtest.h"
#include "cProcessOrder.h"
#include "../ProductsLib/cProducts.h"

TEST(cProcessOrder, AddToCart_GoodProduct) {
	cProcessOrder order;
	cProducts* goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 1.0, true);

	EXPECT_TRUE(order.AddToCart(goodProduct));
	EXPECT_TRUE(order.IsAddedToCart(goodProduct));
}

TEST(cProcessOrder, AddToCart_BadProduct) {
	cProcessOrder order;
	cProducts* badProduct = new cProducts(420, "Bad Product", "Bad Description", 24, 27.99, 1.0, false);

	EXPECT_FALSE(order.AddToCart(badProduct));
	EXPECT_FALSE(order.IsAddedToCart(badProduct));
}

TEST(cProcessOrder, CalculateOrderTotal_GoodProduct) {
	cProcessOrder order;
	cProducts* goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 1.0, true);
	order.AddToCart(goodProduct);
	order.orderQty = 5;

	EXPECT_EQ(order.CalculateOrderTotal(), 4618.6699049999988);
}

TEST(cProcessOrder, CalculateOrderTotal_DiscountedProduct) {
	cProcessOrder order;
	cProducts* discountedProduct = new cProducts(20, "Discounted Product", "Cheaper than usual", 10, 129.99, 0.9, true);
	order.AddToCart(discountedProduct);

	EXPECT_EQ(order.CalculateOrderTotal(), 1123.6985549999999);
}

TEST(cProcessOrder, CalculateOrderTotal_BadProduct) {
	cProcessOrder order;
	cProducts* badProduct = new cProducts(420, "Bad Product", "Bad Description", 24, 27.99, 1.0, false);
	order.AddToCart(badProduct);

	EXPECT_EQ(order.CalculateOrderTotal(), 0);
}


extern "C" __declspec(dllexport) void RunTests() {
	testing::InitGoogleTest();
	RUN_ALL_TESTS();
}