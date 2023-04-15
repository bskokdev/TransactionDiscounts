#ifndef TRANSACTIONDISCOUNTS_IATTRIBUTEVALIDATOR_H
#define TRANSACTIONDISCOUNTS_IATTRIBUTEVALIDATOR_H


/**
 * @brief Interface for attribute validators
 */
class IAttributeValidator {
public:
    /**
     * @brief Checks if the attributes are valid
     * @param attributes string to validate attributes within
     * @return true if the value is valid, false otherwise
     */
    virtual bool isValid(std::string attributes) = 0;
};


#endif //TRANSACTIONDISCOUNTS_IATTRIBUTEVALIDATOR_H
