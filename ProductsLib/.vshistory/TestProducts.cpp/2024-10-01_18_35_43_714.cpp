#include "pch.h"
#include "../include/gtest/gtest.h"
#include "cProducts.h"

TEST(cProducts, SetAvailability_GoodProduct) {
	cProducts* goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 1.0, true);
	
	EXPECT_FALSE(goodProduct->SetAvailability(false));
}

TEST(cProducts, SetAvailability_BadProduct) {
	cProducts* goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 1.0, true);

	EXPECT_FALSE(goodProduct->SetAvailability(false));
}