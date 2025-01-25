#include "gtest/gtest.h"
#include "cProcessOrder.h"
#include "../ProductsLib/cProducts.h"

class cProcessOrderTest : public ::testing::Test {
protected:
    cProcessOrder order; // Create an instance of cProcessOrder for testing

    // Example product for testing
    cProducts* validProduct = new cProducts(1, "Test Product", "A product for testing", 10, 100.0);
    cProducts* outOfStockProduct = new cProducts(2, "Out of Stock Product", "This product is out of stock", 0, 150.0);
    cProducts* discountProduct = new cProducts(3, "Discount Product", "Product with discount", 5, 200.0, 0.80);

    // Clean up dynamically allocated memory
    void TearDown() override {
        delete validProduct;
        delete outOfStockProduct;
        delete discountProduct;
    }
};

// Test adding a product to the cart
TEST_F(cProcessOrderTest, AddToCart_ValidProduct) {
    order.AddToCart(validProduct);
    ASSERT_EQ(order.orderItems.size(), 1);
    EXPECT_EQ(order.orderItems[0]->productID, validProduct->productID);
}

// Test calculating order total without any items
TEST_F(cProcessOrderTest, CalculateOrderTotal_EmptyCart) {
    double total = order.CalculateOrderTotal();
    EXPECT_EQ(total, 0.0);
}

// Test calculating order total with valid items
TEST_F(cProcessOrderTest, CalculateOrderTotal_ValidCart) {
    order.AddToCart(validProduct);
    order.orderQty = 1; // Set quantity for calculation
    double total = order.CalculateOrderTotal();
    EXPECT_EQ(total, validProduct->productPrice * order.orderQty * order.orderTax * order.orderDiscount);
}

// Test calculating order total with multiple items
TEST_F(cProcessOrderTest, CalculateOrderTotal_MultipleItems) {
    order.AddToCart(validProduct);
    order.AddToCart(discountProduct);
    order.orderQty = 1; // Set quantity for calculation
    double total = order.CalculateOrderTotal();
    double expectedTotal = (validProduct->productPrice * order.orderQty * order.orderTax * order.orderDiscount) +
        (discountProduct->productPrice * order.orderQty * order.orderTax * discountProduct->productDiscount);
    EXPECT_EQ(total, expectedTotal);
}

// Test adding an out-of-stock product
TEST_F(cProcessOrderTest, AddToCart_OutOfStockProduct) {
    order.AddToCart(outOfStockProduct);
    EXPECT_EQ(order.orderItems.size(), 1);
    EXPECT_EQ(order.orderItems[0]->productID, outOfStockProduct->productID);
    EXPECT_EQ(order.orderItems[0]->productQty, outOfStockProduct->productQty);
}
