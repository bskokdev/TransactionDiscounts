#include "Application.h"

Application::Application(TransactionPrinter &printer, ShippingOptionRepository &shippingRepo)
        : printer(printer), shippingRepo(shippingRepo) {}

void Application::run() {
    initialize();

    // read the input file path - this could be also read from a config file
    std::string path;
    std::cout << "enter the path to the input file:" << std::endl;
    std::cin >> path;

    // read the input file
    Reader reader(path);
    std::vector<std::string> lines = reader.readLines();

    // validation etc.
}

void Application::initialize() {
    // this could be also read from a file / database / etc.
    shippingRepo.add(ShippingOption(Provider::MR, PackageSize::S, 10));
    shippingRepo.add(ShippingOption(Provider::MR, PackageSize::M, 20));
    shippingRepo.add(ShippingOption(Provider::LP, PackageSize::L, 30));
}

