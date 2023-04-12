#ifndef TRANSACTIONDISCOUNTS_APPLICATION_H
#define TRANSACTIONDISCOUNTS_APPLICATION_H


#include "shipping/shippingOption/ShippingOptionRepository.h"
#include "transaction/TransactionPrinter.h"

#include <string>
#include <iostream>
#include "io/Reader.h"

/**
 * @brief Class representing the application
 */
class Application {
private:
    TransactionPrinter& printer;
    ShippingOptionRepository& shippingRepo;
public:
    /**
     * @brief Constructor with dependencies
     * @details The dependencies are injected via constructor
     * @param printer TransactionPrinter instance
     * @param shippingRepo ShippingOptionRepository instance
     */
    Application(TransactionPrinter &printer, ShippingOptionRepository &shippingRepo);

    /**
     * @brief Run the application
     */
    void run();

    /**
     * @brief Initialize the application with ShoppingOptions
     */
    void initialize();
};


#endif //TRANSACTIONDISCOUNTS_APPLICATION_H
