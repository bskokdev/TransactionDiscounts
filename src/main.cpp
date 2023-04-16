#include "Application.h"

int main(int argc, char *argv[]) {
    std::string inputFilePath = argv[1];
    if(inputFilePath.empty()) {
        std::cout << "Please provide a file path as argument" << std::endl;
        return 1;
    }

    ShippingOptionRepository shippingRepo;
    DiscountService discountService(10);
    TransactionValidator transactionValidator;

    Application app(shippingRepo, discountService, transactionValidator, inputFilePath);
    app.run();
    return 0;
}
