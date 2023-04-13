#ifndef TRANSACTIONDISCOUNTS_TRANSACTIONHASH_H
#define TRANSACTIONDISCOUNTS_TRANSACTIONHASH_H


#include "Transaction.h"
#include <functional>

/**
 * @brief Hash function for Transaction class
 */
struct TransactionHash {
    /**
     * @brief Hash function for Transaction class
     * @param t transaction to hash
     * @return hash of the transaction
     */
    std::size_t operator()(const Transaction &t) const;
};


#endif //TRANSACTIONDISCOUNTS_TRANSACTIONHASH_H
