#include "Application.h"

int main() {
    TransactionPrinter printer;
    ShippingOptionRepository shippingRepo;
    TransactionRepository transactionRepo;

    Application app(printer, shippingRepo, transactionRepo);
    app.run();
    return 0;
}
