#include "Application.h"

int main() {
    TransactionPrinter printer;
    ShippingOptionRepository shippingRepo;

    Application app(printer, shippingRepo);
    app.run();
    return 0;
}
