#include "Application.h"

int main() {
    ShippingOptionRepository shippingRepo;

    Application app(shippingRepo);
    app.run();
    return 0;
}
