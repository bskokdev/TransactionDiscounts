#ifndef TRANSACTIONDISCOUNTS_APPLICATION_H
#define TRANSACTIONDISCOUNTS_APPLICATION_H


#include "shipping/shippingOption/ShippingOptionRepository.h"

#include <string>
#include <iostream>
#include "io/Reader.h"
#include "transaction/Transaction.h"
#include "discount/DiscountService.h"
#include "validation/TransactionValidator.h"

/**
 * @brief Class representing the application
 */
class Application {
private:
    ShippingOptionRepository &shippingRepo;
    TransactionValidator &transactionValidator;
    DiscountService &discountService;

    /**
     * @brief Read input file path from user
     * @return input file path
     */
    static std::string readInputFilePath();

    /**
     * @brief Read input file to vector of strings
     * @param inputFilePath file path
     * @return vector of lines
     * @deprecated This method will not used anymore
     */
     // todo: remove this method & move file path to arguments in main()
    static std::vector<std::string> readInputFile(std::string &inputFilePath);

    /**
     * @brief Create a Transaction object from an input line
     * @param line input line
     * @details has a side-effect of printing the invalid input line
     * @return Transaction object
     */
    Transaction buildTransactionFromUserInputLine(std::string &line);

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
    static void printTransactionAndDiscount(Transaction &transaction, double discount);

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
    Application(ShippingOptionRepository &shippingRepo,
                DiscountService &discountService,
                TransactionValidator &transactionValidator);

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
