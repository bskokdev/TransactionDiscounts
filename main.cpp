#include "Application.h"

int main() {
    ShippingOptionRepository shippingRepo;
    DiscountService discountService(10);

    Application app(shippingRepo, discountService);
    app.run();
    return 0;
}
