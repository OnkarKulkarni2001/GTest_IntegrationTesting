#include "gtest/gtest.h"
#include "cProcessOrder.h"
#include "../ProductsLib/cProducts.h"

// Test Fixture for cProcessOrder
class cProcessOrderTest : public ::testing::Test {
protected:
    cProcessOrder* order;

    void SetUp() override {
        order = new cProcessOrder();
    }

    void TearDown() override {
        delete order;
    }
};

// Test: Adding a valid product to the cart
TEST_F(cProcessOrderTest, AddToCart_ValidProduct) {
    cProducts* product = new cProducts("Test Product", "A sample product", 10.0, true);
    order->AddToCart(product);
    EXPECT_EQ(order->orderItems.size(), 1); // Good case: Product added successfully
    delete product; // Clean up
}

// Test: Adding a null product to the cart
TEST_F(cProcessOrderTest, AddToCart_NullProduct) {
    order->AddToCart(nullptr);
    EXPECT_EQ(order->orderItems.size(), 0); // Bad case: Should not add null product
}

// Test: Calculate order total with no items
TEST_F(cProcessOrderTest, CalculateOrderTotal_NoItems) {
    EXPECT_EQ(order->CalculateOrderTotal(), 0.0); // Good case: Total should be zero
}

// Test: Calculate order total with items
TEST_F(cProcessOrderTest, CalculateOrderTotal_WithItems) {
    cProducts* product = new cProducts("Test Product", "A sample product", 10.0, true);
    order->AddToCart(product);
    order->orderQty = 2; // 2 items in the order
    EXPECT_NEAR(order->CalculateOrderTotal(), 21.13, 0.01); // Good case: Check total calculation
    delete product; // Clean up
}

// Test: Calculate order total with negative quantity
TEST_F(cProcessOrderTest, CalculateOrderTotal_NegativeQuantity) {
    cProducts* product = new cProducts("Test Product", "A sample product", 10.0, true);
    order->AddToCart(product);
    order->orderQty = -1; // Bad case: Negative quantity
    EXPECT_GE(order->CalculateOrderTotal(), 0.0); // Total should not be negative
    delete product; // Clean up
}