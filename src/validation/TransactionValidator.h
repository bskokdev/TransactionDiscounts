#ifndef TRANSACTIONDISCOUNTS_TRANSACTIONVALIDATOR_H
#define TRANSACTIONDISCOUNTS_TRANSACTIONVALIDATOR_H


#include <string>
#include <vector>
#include "IAttributeValidator.h"

/**
 * @brief Class representing a validator for simple transactions
 * @details This class is used to validate format of transactions
 */
class TransactionValidator : public IAttributeValidator {
public:
    /**
     * @brief Default constructor for TransactionValidator
     */
    TransactionValidator() = default;

    /**
     * @brief Checks if attributes in the vector are valid
     * @param attributes vector of strings to validate attributes within
     * @return true if the value is valid, false otherwise
     * @see IAttributeValidator::areValidTypeAttributes
     */
    bool areValidTypeAttributes(std::vector<std::string> attributes) override;
};


#endif //TRANSACTIONDISCOUNTS_TRANSACTIONVALIDATOR_H
