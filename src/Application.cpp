#include <iomanip>
#include <utility>
#include "Application.h"
#include "discount/DiscountService.h"

Application::Application(std::unique_ptr<ShippingOptionRepository> &shippingRepo,
                         DiscountService &discountService,
                         IAttributeValidator &attributeValidator,
                         std::string inputFilePath)
        : shippingRepo(shippingRepo),
          discountService(discountService),
          attributeValidator(attributeValidator),
          inputFilePath(std::move(inputFilePath)){}

void Application::initialize() {
    // this could be also read from a file / database / etc.
    this->shippingRepo->add(ShippingOption(Provider::LP, PackageSize::S, 1.50));
    this->shippingRepo->add(ShippingOption(Provider::LP, PackageSize::M, 4.90));
    this->shippingRepo->add(ShippingOption(Provider::LP, PackageSize::L, 6.90));

    this->shippingRepo->add(ShippingOption(Provider::MR, PackageSize::S, 2.00));
    this->shippingRepo->add(ShippingOption(Provider::MR, PackageSize::M, 3.00));
    this->shippingRepo->add(ShippingOption(Provider::MR, PackageSize::L, 4.00));

    double minSmallPackagePrice = this->shippingRepo->findLowestPriceForSize(PackageSize::S);
    this->discountService.setMinSmallPackagePrice(minSmallPackagePrice);
}

std::string Application::readInputFilePath() {
    return this->inputFilePath;
}

std::vector<std::string> Application::readInputFile(std::string &inputFilePath) {
    Reader reader(inputFilePath);
    return reader.readLines();
}

void handleInvalidTransactionInput(const std::vector<std::string>& lineTokens) {
    for(auto &token: lineTokens) {
        std::cout << token << " ";
    }
    std::cout << "Ignored" << std::endl;
}

ShippingTransaction Application::buildTransactionFromUserInputLine(std::string &line) {
    // split the line into tokens (date, provider, package size)
    std::vector<std::string> transactionTokens = Reader::tokenize(line, ' ');

    // validation
    if(!this->attributeValidator.areValidTypeAttributes(transactionTokens)) {
        handleInvalidTransactionInput(transactionTokens);
        return {};
    }

    std::string provider = transactionTokens[2];
    std::string packageSize = transactionTokens[1];
    ShippingOption shippingOption = this->shippingRepo->findFromString(provider, packageSize);

    Date date = Date::buildDateFromString(transactionTokens[0]);

    // create a transaction object
    return {date, shippingOption};
}

double Application::applyDiscount(ShippingTransaction &transaction) {
    double discount = this->discountService.calcDiscountForTransaction(transaction);
    DiscountService::applyDiscountToTransaction(transaction, discount);

    return discount;
}

void Application::printTransactionAndDiscount(ShippingTransaction &transaction, double discount) {
    std::cout << transaction;
    // print the discount with 2 decimal places or "-" if the discount is 0
    std::stringstream ss;
    if (discount == 0.0) {
        ss << "-";
    } else {
        ss << std::fixed << std::setprecision(2) << discount;
    }
    std::cout << ss.str() << std::endl;
}

void Application::run() {
    initialize();

    // read the input file path - this could be also read from a config file
    std::string path = this->readInputFilePath();

    // read the input file
    std::vector<std::string> lines = this->readInputFile(path);

    for (auto &line: lines) {
        ShippingTransaction transaction = buildTransactionFromUserInputLine(line);
        // if the transaction is invalid, skip it
        if(!transaction.isEmpty()) {
            double discount = applyDiscount(transaction);
            printTransactionAndDiscount(transaction, discount);
            // we could also save the discounted transaction to a database here
        }
    }
}
