#ifndef TRANSACTIONDISCOUNTS_TRANSACTIONREPOSITORY_H
#define TRANSACTIONDISCOUNTS_TRANSACTIONREPOSITORY_H

#include "Transaction.h"
#include "../common/IDataRepository.h"

/**
 * @brief Class for storing transactions
 * @details Implements IDataRepository interface
 */
class TransactionRepository : public IDataRepository<Transaction>{

};


#endif //TRANSACTIONDISCOUNTS_TRANSACTIONREPOSITORY_H
