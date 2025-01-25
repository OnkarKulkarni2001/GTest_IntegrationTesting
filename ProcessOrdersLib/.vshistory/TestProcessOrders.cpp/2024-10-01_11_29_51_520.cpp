#include "pch.h"
#include "gtest/gtest.h"
#include "cProcessOrder.h"
#include "../ProductsLib/cProducts.h"

class cProcessOrderTest : public ::testing::Test {
public:
	cProcessOrder order;
	cProducts* goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 0.0, true);
	cProducts* badProduct = new cProducts(420, "Bad Product", "Bad Description", 24, 27.99, 0.0, false);
	cProducts* discountedProduct = new cProducts(39, "Discounted Product", "Cheaper than usual", 10, 129.99, 0.9, true);
};

TEST(cProcessOrder::AddToCart, Good_Case) {

}