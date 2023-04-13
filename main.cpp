#include "Application.h"

int main() {
    ShippingOptionRepository shippingRepo;
    TransactionRepository transactionRepo;

    Application app(shippingRepo, transactionRepo);
    app.run();
    return 0;
}
