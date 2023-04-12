#ifndef TRANSACTIONDISCOUNTS_TRANSACTIONPRINTER_H
#define TRANSACTIONDISCOUNTS_TRANSACTIONPRINTER_H

#include <iostream>
#include "Transaction.h"
#include "../io/IPrinter.h"

/**
 * @brief Class for printing transactions
 * @details Implements IPrinter interface
 */
class TransactionPrinter : public IPrinter<Transaction> {
public:
    // constructor
    TransactionPrinter();
    /**
     * @brief Get the instance of TransactionPrinter
     * @return TransactionPrinter reference
     */
    static TransactionPrinter& getInstance();

    /**
     * @brief Print transaction
     * @param transaction Transaction to print
     */
    void print(const Transaction &transaction) override;

    /**
     * @brief Print vector of transactions
     * @param transactions Vector of transactions to print
     */
    void print(const std::vector<Transaction> &transactions) override;
};


#endif //TRANSACTIONDISCOUNTS_TRANSACTIONPRINTER_H