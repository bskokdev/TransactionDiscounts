#ifndef TRANSACTIONDISCOUNTS_APPLICATION_H
#define TRANSACTIONDISCOUNTS_APPLICATION_H


#include "shipping/shippingOption/ShippingOptionRepository.h"

#include <string>
#include <iostream>
#include "io/Reader.h"
#include "transaction/Transaction.h"

/**
 * @brief Class representing the application
 */
class Application {
private:
    ShippingOptionRepository &shippingRepo;

    /**
     * @brief Read input file path from user
     * @return input file path
     */
    std::string readInputFilePath();

    /**
     * @brief Read input file to vector of strings
     * @param inputFilePath file path
     * @return vector of lines
     */
    std::vector<std::string> readInputFile(std::string &inputFilePath);

    /**
     * @brief Create a Transaction object from an input line
     * @param line input line
     * @return Transaction object
     */
    Transaction createTransaction(std::string &line);

    /**
     * @brief Apply discount on the transaction and return the discount
     * @param transaction Transaction object
     * @return discount
     */
    double applyDiscount(Transaction &transaction);

    /**
     * @brief Print the transaction and discount
     * @param transaction Transaction object
     * @param discount discount
     */
    void printTransactionAndDiscount(Transaction &transaction, double discount);

public:
    /**
     * @brief Constructor with dependencies
     * @details The dependencies are injected via constructor
     * @param shippingRepo ShippingOptionRepository instance
     */
    Application(ShippingOptionRepository &shippingRepo);

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
