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

TEST(cProcessOrderTest, AddToCart_GoodProduct) {
	cProcessOrder order;
	cProducts* goodProduct = new cProducts(101, "Good Product", "Good Description", 69, 69.69, 0.0, true);
	EXPECT_EQ(order.AddToCart(goodProduct), order.IsAddedToCart(goodProduct));
}

TEST(cProcessOrderTest, AddToCart_BadProduct) {
	cProcessOrder order;
	cProducts* badProduct = new cProducts(420, "Bad Product", "Bad Description", 24, 27.99, 0.0, false);
	EXPECT_EQ(order.AddToCart(badProduct), order.IsAddedToCart(badProduct));
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}