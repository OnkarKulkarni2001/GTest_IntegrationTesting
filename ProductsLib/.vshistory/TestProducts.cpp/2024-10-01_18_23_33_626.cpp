#include "pch.h"
#include "../include/gtest/gtest.h"
#include "cProducts.h"

TEST(cProducts, UpdateStock_GoodProduct) {
	cProducts* goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 1.0, true);
	
}