#include "Application.h"

int main() {
    ShippingOptionRepository shippingRepo;
    DiscountService discountService(10);
    TransactionValidator transactionValidator;

    Application app(shippingRepo, discountService, transactionValidator);
    app.run();
    return 0;
}
