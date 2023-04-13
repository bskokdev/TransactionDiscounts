#include "Application.h"

Application::Application(ShippingOptionRepository &shippingRepo, TransactionRepository &transactionRepo)
        : shippingRepo(shippingRepo), transactionRepo(transactionRepo) {}

void Application::run() {
    initialize();

    // read the input file path - this could be also read from a config file
    std::string path;
    std::cout << "enter the path to the input file:" << std::endl;
    std::cin >> path;

    // read the input file
    Reader reader(path);
    std::vector<std::string> lines = reader.readLines();

    // validation & discounts
}

void Application::initialize() {
    // this could be also read from a file / database / etc.
    this->shippingRepo.add(ShippingOption(Provider::MR, PackageSize::S, 10));
    this->shippingRepo.add(ShippingOption(Provider::MR, PackageSize::M, 20));
    this->shippingRepo.add(ShippingOption(Provider::LP, PackageSize::L, 30));
}

