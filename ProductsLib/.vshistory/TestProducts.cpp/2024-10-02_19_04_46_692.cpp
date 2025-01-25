#include "pch.h"
#include "../include/gtest/gtest.h"
#include "cProducts.h"

class cProductsTest : testing::Test {
	cProducts* goodProduct;
	cProducts* badProduct;

	virtual void SetUp() override {
		goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 1.0, true);
		badProduct = new cProducts(420, "Bad Product", "Bad Description", -1, 27.99, 1.0, false);
	}

	virtual void TearDown() override {
		delete goodProduct;
		delete badProduct;
	}
};

TEST_F(cProductsTest, SetAvailability_GoodProduct) {
	SetUp();
	EXPECT_FALSE(goodProduct->SetAvailability(false));
}

TEST_F(cProductsTest, SetAvailability_BadProduct) {
	cProducts* badProduct = new cProducts(420, "Bad Product", "Bad Description", -1, 27.99, 1.0, false);

	EXPECT_TRUE(badProduct->SetAvailability(true));
}

TEST_F(cProductsTest, SetProductQty_BadProduct) {
	cProducts* badProduct = new cProducts(420, "Bad Product", "Bad Description", -1, 27.99, 1.0, false);

	EXPECT_EQ(badProduct->SetProductQty(3), 3);
}

TEST_F(cProductsTest, SetProductQty_GoodProduct) {
	cProducts* goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 1.0, true);

	EXPECT_EQ(goodProduct->SetProductQty(99), 99);
}

TEST_F(cProcProductsTestducts, SetPrice_GoodProduct) {
	cProducts* goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 1.0, true);

	EXPECT_EQ(goodProduct->SetPrice(99.99), 99.99);
}