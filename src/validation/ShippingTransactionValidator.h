#ifndef TRANSACTIONDISCOUNTS_SHIPPINGTRANSACTIONVALIDATOR_H
#define TRANSACTIONDISCOUNTS_SHIPPINGTRANSACTIONVALIDATOR_H


#include "transaction/ShippingTransaction.h"
#include "IAttributeValidator.h"
#include "TransactionValidator.h"

/**
 * @brief Class representing the shipping transaction validator
 * @details This class is used to validate format of ShippingTransactions
 */
class ShippingTransactionValidator : public TransactionValidator {
private:
    /**
     * @brief Checks if a string is a valid provider
     * @tparam T Provider or PackageSize
     * @param enumString provider string
     * @details we take advantage of getProviderFromString throwing an exception if the string is invalid
     * @return true if string is a valid provider
     */
    template<typename T>
    static bool isEnumStringValid(const std::string &enumString);
public:
    /**
     * @brief Default constructor for TransactionValidator
     */
    ShippingTransactionValidator() = default;

    /**
     * @brief Checks if attributes in the vector are valid
     * @param attributes vector of strings to validate attributes within
     * @return true if the value is valid, false otherwise
     * @see IAttributeValidator::areValidTypeAttributes
     */
    bool areValidTypeAttributes(std::vector<std::string> attributes) override;
};


#endif //TRANSACTIONDISCOUNTS_SHIPPINGTRANSACTIONVALIDATOR_H
