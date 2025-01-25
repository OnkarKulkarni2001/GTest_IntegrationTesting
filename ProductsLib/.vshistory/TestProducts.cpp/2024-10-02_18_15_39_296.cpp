#include "pch.h"
#include "../include/gtest/gtest.h"
#include "cProducts.h"

TEST(cProducts, SetAvailability_GoodProduct) {
	cProducts* goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 1.0, true);
	
	EXPECT_FALSE(goodProduct->SetAvailability(false));
}

TEST(cProducts, SetAvailability_BadProduct) {
	cProducts* badProduct = new cProducts(420, "Bad Product", "Bad Description", -1, 27.99, 1.0, false);

	EXPECT_TRUE(badProduct->SetAvailability(true));
}

TEST(cProducts, SetProductQty_BadProduct) {
	cProducts* badProduct = new cProducts(420, "Bad Product", "Bad Description", -1, 27.99, 1.0, false);

	EXPECT_EQ(badProduct->SetProductQty(3), 3);
}

TEST(cProducts, SetAvailability_GoodProduct) {
	cProducts* goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 1.0, true);

	EXPECT_EQ(goodProduct->SetProductQty(99), 99);
}

TEST(cProducts, SetPrice_GoodProduct) {
	cProducts* goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 1.0, true);

	EXPECT_EQ(goodProduct->SetPrice(99.99), 99.99);
}