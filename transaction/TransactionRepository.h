#ifndef TRANSACTIONDISCOUNTS_TRANSACTIONREPOSITORY_H
#define TRANSACTIONDISCOUNTS_TRANSACTIONREPOSITORY_H

#include <unordered_set>
#include "Transaction.h"
#include "../common/IDataRepository.h"
#include "TransactionHash.h"

/**
 * @brief Class for storing transactions
 * @details Implements IDataRepository interface
 */
class TransactionRepository : public IDataRepository<Transaction>{
private:
    std::unordered_set<Transaction, TransactionHash> transactions;
public:
    TransactionRepository();
    // IDataRepository methods
    bool exists(const Transaction &item) override;

    void add(const Transaction &item) override;

    void remove(const Transaction &item) override;

    void update(const Transaction &item) override;

    std::vector<Transaction> getAll() override;
};


#endif //TRANSACTIONDISCOUNTS_TRANSACTIONREPOSITORY_H
