#include "Application.h"
#include "discount/DiscountService.h"

Application::Application(ShippingOptionRepository &shippingRepo) : shippingRepo(shippingRepo) {}

void Application::initialize() {
    // this could be also read from a file / database / etc.
    this->shippingRepo.add(ShippingOption(Provider::LP, PackageSize::S, 1.50));
    this->shippingRepo.add(ShippingOption(Provider::LP, PackageSize::M, 4.90));
    this->shippingRepo.add(ShippingOption(Provider::LP, PackageSize::L, 6.90));

    this->shippingRepo.add(ShippingOption(Provider::MR, PackageSize::S, 2.00));
    this->shippingRepo.add(ShippingOption(Provider::MR, PackageSize::M, 3.00));
    this->shippingRepo.add(ShippingOption(Provider::MR, PackageSize::L, 4.00));
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

Transaction Application::createTransaction(std::string &line) {
    Reader reader;
    // split the line into tokens (date, provider, package size)
    std::vector<std::string> transactionTokens = reader.tokenize(line, ' ');
    // todo: validation!
    ShippingOption shippingOption =
            shippingRepo.findFromString(transactionTokens[2], transactionTokens[1]);

    // Split the date into tokens (year, month, day) & create a Date object
    std::vector<std::string> dateTokens = reader.tokenize(transactionTokens[0], '-');
    Date date = Date(
            std::stoi(dateTokens[0]), std::stoi(dateTokens[1]), std::stoi(dateTokens[2]));

    // create a transaction object
    return Transaction(date, shippingOption);
}

double Application::applyDiscount(Transaction &transaction) {
    double lowestPriceForSmallPackage = shippingRepo.findLowestPriceForPackageSize(PackageSize::S);
    DiscountService discountService(lowestPriceForSmallPackage, 10);

    double discount = discountService.calcDiscountForTransaction(transaction);
    discountService.applyDiscountToTransaction(transaction, discount);

    return discount;
}

void Application::printTransactionAndDiscount(Transaction &transaction, double discount) {
    std::cout << transaction;
    std::cout << (discount == 0.0 ? "-" : std::to_string(discount)) << std::endl;
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
        Transaction transaction = createTransaction(line);
        double discount = applyDiscount(transaction);
        printTransactionAndDiscount(transaction, discount);
    }
}
