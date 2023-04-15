#ifndef TRANSACTIONDISCOUNTS_TRANSACTIONVALIDATOR_H
#define TRANSACTIONDISCOUNTS_TRANSACTIONVALIDATOR_H


#include "../transaction/Transaction.h"
#include "IAttributeValidator.h"

/**
 * @brief Class representing the transaction validator
 * @details This class is used to validate format of transactions
 */
class TransactionValidator : public IAttributeValidator {
private:
    // These validations could be moved to separate validators (deriving from IAttributeValidator)
    // I decided to keep them here for simplicity and because they are not used anywhere else

    /**
     * @brief Checks if a string is a valid provider
     * @param provider provider string
     * @details we take advantage of getProviderFromString throwing an exception if the string is invalid
     * @return true if string is a valid provider
     */
    static bool isProviderStringValid(const std::string &provider);

    /**
     * @brief Checks if a string is a valid package size
     * @param packageSize package size string
     * @details we take advantage of getPackageSizeFromString throwing an exception if the string is invalid
     * @return true if string is a valid package size
     */
    static bool isPackageSizeStringValid(const std::string &packageSize);
public:
    /**
     * @brief Default constructor for TransactionValidator
     */
    TransactionValidator() = default;

    /**
     * @see IAttributeValidator::areValid
     */
    bool areValid(std::vector<std::string> attributes) override;
};


#endif //TRANSACTIONDISCOUNTS_TRANSACTIONVALIDATOR_H
