#include 
#include "cProcessOrder.h"
#include "../ProductsLib/cProducts.h"

// Test Fixture for cProcessOrder
class ProcessOrderTest : public ::testing::Test {
protected:
    void SetUp() override {
        order = new cProcessOrder(1, 1.13, 0.85);  // orderID, tax, discount
        product1 = new cProducts(101, "Laptop", "Gaming laptop", 5, 1500.00, 0.10, true);
        product2 = new cProducts(102, "Mouse", "Wireless mouse", 20, 50.00, 0.05, true);
    }

    void TearDown() override {
        delete order;
        delete product1;
        delete product2;
    }

    cProcessOrder* order;
    cProducts* product1;
    cProducts* product2;
};

// Good case: Add product to cart
TEST_F(ProcessOrderTest, AddToCart) {
    order->AddToCart(product1);
    ASSERT_EQ(order->GetOrderQty(), 1);
}

// Bad case: CalculateOrderTotal with empty cart
TEST_F(ProcessOrderTest, CalculateOrderTotal_EmptyCart) {
    ASSERT_EQ(order->CalculateOrderTotal(), 0.0);  // Expect total to be 0
}

// Good case: Calculate total order cost
TEST_F(ProcessOrderTest, CalculateOrderTotal) {
    order->AddToCart(product1);
    order->AddToCart(product2);
    double expectedTotal = (1500.00 + 50.00) * 0.85 * 1.13;
    ASSERT_DOUBLE_EQ(order->CalculateOrderTotal(), expectedTotal);
}

// Good case: Get Order ID
TEST_F(ProcessOrderTest, GetOrderID) {
    ASSERT_EQ(order->GetOrderID(), 1);
}

// Bad case: Add null product to cart
TEST_F(ProcessOrderTest, AddNullProduct) {
    cProducts* nullProduct = nullptr;
    ASSERT_THROW(order->AddToCart(nullProduct), std::invalid_argument);  // Expect throw
}
