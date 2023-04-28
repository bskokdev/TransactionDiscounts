#ifndef TRANSACTIONDISCOUNTS_APPLICATION_H
#define TRANSACTIONDISCOUNTS_APPLICATION_H


#include "shipping/shippingOption/ShippingOptionRepository.h"

#include <string>
#include <iostream>
#include <memory>
#include "io/Reader.h"
#include "transaction/ShippingTransaction.h"
#include "discount/DiscountService.h"
#include "validation/ShippingTransactionValidator.h"

/**
 * @brief Class representing the application
 */
class Application {
private:
    std::unique_ptr<ShippingOptionRepository> &shippingRepo;
    IAttributeValidator &attributeValidator;
    DiscountService &discountService;
    std::string inputFilePath;

    /**
     * @brief Read input file path
     * @return input file path
     */
    std::string readInputFilePath();

    /**
     * @brief Read input file to vector of strings
     * @param inputFilePath file path
     * @return vector of lines
     */
    static std::vector<std::string> readInputFile(std::string &inputFilePath);

    /**
     * @brief Create a Transaction object from an input line
     * @param line input line
     * @details has a side-effect of printing the invalid input line
     * @return Transaction object
     */
    ShippingTransaction buildTransactionFromUserInputLine(std::string &line);

    /**
     * @brief Apply discount on the transaction and return the discount
     * @param transaction Transaction object
     * @return discount
     */
    double applyDiscount(ShippingTransaction &transaction);

    /**
     * @brief Print the transaction and discount
     * @param transaction Transaction object
     * @param discount discount
     */
    static void printTransactionAndDiscount(ShippingTransaction &transaction, double discount);

public:
    /**
     * @brief Default constructor
     */
    Application() = delete;

    /**
     * @brief Constructor with dependencies
     * @details The dependencies are injected via constructor
     * @param shippingRepo ShippingOptionRepository instance
     * @param discountService DiscountService instance
     */
    Application(std::unique_ptr<ShippingOptionRepository> &shippingRepo,
                DiscountService &discountService,
                IAttributeValidator &attributeValidator,
                std::string inputFilePath);

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
