#ifndef TRANSACTIONDISCOUNTS_APPLICATION_H
#define TRANSACTIONDISCOUNTS_APPLICATION_H


#include "shipping/shippingOption/ShippingOptionRepository.h"
#include "transaction/TransactionPrinter.h"

#include <string>
#include <iostream>
#include "io/Reader.h"
#include "transaction/TransactionRepository.h"

/**
 * @brief Class representing the application
 */
class Application {
private:
    TransactionPrinter& printer;
    ShippingOptionRepository& shippingRepo;
    TransactionRepository& transactionRepo;
public:
    /**
     * @brief Constructor with dependencies
     * @details The dependencies are injected via constructor
     * @param printer TransactionPrinter instance
     * @param shippingRepo ShippingOptionRepository instance
     */
    Application(TransactionPrinter &printer, ShippingOptionRepository &shippingRepo, TransactionRepository &transactionRepo);

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
