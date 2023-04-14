#include <iomanip>
#include "Application.h"
#include "discount/DiscountService.h"

Application::Application(ShippingOptionRepository &shippingRepo, DiscountService &discountService)
    : shippingRepo(shippingRepo), discountService(discountService) {}

void Application::initialize() {
    // this could be also read from a file / database / etc.
    this->shippingRepo.add(ShippingOption(Provider::LP, PackageSize::S, 1.50));
    this->shippingRepo.add(ShippingOption(Provider::LP, PackageSize::M, 4.90));
    this->shippingRepo.add(ShippingOption(Provider::LP, PackageSize::L, 6.90));

    this->shippingRepo.add(ShippingOption(Provider::MR, PackageSize::S, 2.00));
    this->shippingRepo.add(ShippingOption(Provider::MR, PackageSize::M, 3.00));
    this->shippingRepo.add(ShippingOption(Provider::MR, PackageSize::L, 4.00));

    double minSmallPackagePrice = this->shippingRepo.findLowestPriceForSize(PackageSize::S);
    this->discountService.setMinSmallPackagePrice(minSmallPackagePrice);
}

std::string Application::readInputFilePath() {
    std::string path;
    std::cout << "Enter the path to the input file:" << std::endl;
    std::cin >> path;
    return path;
}

std::vector<std::string> Application::readInputFile(std::string &inputFilePath) {
    Reader reader(inputFilePath);
    return reader.readLines();
}

Transaction Application::buildTransactionFromUserInputLine(std::string &line) {
    Reader reader;
    // split the line into tokens (date, provider, package size)
    std::vector<std::string> transactionTokens = reader.tokenize(line, ' ');
    // todo: validation!
    std::string provider = transactionTokens[2];
    std::string packageSize = transactionTokens[1];
    ShippingOption shippingOption = this->shippingRepo.findFromString(provider, packageSize);

    // Split the date into tokens (year, month, day) & create a Date object
    std::vector<std::string> dateTokens = reader.tokenize(transactionTokens[0], '-');
    int year = std::stoi(dateTokens[0]);
    int month = std::stoi(dateTokens[1]);
    int day = std::stoi(dateTokens[2]);

    Date date = Date(day, month, year);

    // create a transaction object
    return {date, shippingOption};
}

double Application::applyDiscount(Transaction &transaction) {
    double discount = this->discountService.calcDiscountForTransaction(transaction);
    DiscountService::applyDiscountToTransaction(transaction, discount);

    return discount;
}

void Application::printTransactionAndDiscount(Transaction &transaction, double discount) {
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

    // todo: validation!
    // do this for valid lines
    for (auto &line: lines) {
        Transaction transaction = buildTransactionFromUserInputLine(line);
        double discount = applyDiscount(transaction);
        printTransactionAndDiscount(transaction, discount);
        // we could also save the discounted transaction to a database here
    }
}
