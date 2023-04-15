#ifndef TRANSACTIONDISCOUNTS_TRANSACTIONVALIDATOR_H
#define TRANSACTIONDISCOUNTS_TRANSACTIONVALIDATOR_H


#include "../transaction/Transaction.h"
#include "IAttributeValidator.h"

/**
 * @brief Class representing the transaction validator
 * @details This class is used to validate format of transactions
 */
class TransactionValidator : public IAttributeValidator {
public:
    bool isValid(std::vector<std::string> attributes) override;
};


#endif //TRANSACTIONDISCOUNTS_TRANSACTIONVALIDATOR_H
