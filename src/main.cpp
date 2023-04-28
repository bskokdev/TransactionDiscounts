#include "Application.h"
#include <memory>

int main(int argc, char *argv[]) {
    std::string inputFilePath = argv[1];
    if(inputFilePath.empty()) {
        std::cout << "Please provide a file path as argument" << std::endl;
        return 1;
    }

    // store the repository on the heap
    std::unique_ptr<ShippingOptionRepository> shippingRepo = std::make_unique<ShippingOptionRepository>();
    DiscountService discountService(10);
    ShippingTransactionValidator shippingTransactionValidator;

    Application app(shippingRepo, discountService, shippingTransactionValidator, inputFilePath);
    app.run();
    return 0;
}
