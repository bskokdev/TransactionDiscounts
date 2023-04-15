#ifndef TRANSACTIONDISCOUNTS_IVALIDATOR_H
#define TRANSACTIONDISCOUNTS_IVALIDATOR_H


/**
 * @brief Interface for validators
 * @tparam T type of value to validate
 */
template <typename T>
class IValidator {
public:
    /**
     * @brief Check if the value is valid
     * @param value Value to validate
     * @return true if the value is valid, false otherwise
     */
    virtual bool isValid(T value) = 0;
};


#endif //TRANSACTIONDISCOUNTS_IVALIDATOR_H
