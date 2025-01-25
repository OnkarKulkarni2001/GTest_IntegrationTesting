#include "gtest/gtest.h"
#include "cProcessOrder.h"
#include "../ProductsLib/cProducts.h"

void Test_AddToCart_ValidProduct() {
    cProcessOrder order;
    cProducts* product = new cProducts("Test Product", "A sample product", 10.0, true);
    order.AddToCart(product);
    assert(order.orderItems.size() == 1); // Good case: Product added successfully
    delete product; // Clean up
}

void Test_AddToCart_NullProduct() {
    cProcessOrder order;
    order.AddToCart(nullptr);
    assert(order.orderItems.size() == 0); // Bad case: Should not add null product
}

void Test_CalculateOrderTotal_NoItems() {
    cProcessOrder order;
    assert(order.CalculateOrderTotal() == 0.0); // Good case: Total should be zero
}

void Test_CalculateOrderTotal_WithItems() {
    cProcessOrder order;
    cProducts* product = new cProducts("Test Product", "A sample product", 10.0, true);
    order.AddToCart(product);
    order.orderQty = 2; // 2 items in the order
    assert(order.CalculateOrderTotal() == 21.13); // Good case: Check total calculation
    delete product; // Clean up
}

void Test_CalculateOrderTotal_NegativeQuantity() {
    cProcessOrder order;
    cProducts* product = new cProducts("Test Product", "A sample product", 10.0, true);
    order.AddToCart(product);
    order.orderQty = -1; // Bad case: Negative quantity
    assert(order.CalculateOrderTotal() >= 0.0); // Total should not be negative
    delete product; // Clean up
}