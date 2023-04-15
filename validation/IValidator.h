#ifndef TRANSACTIONDISCOUNTS_IVALIDATOR_H
#define TRANSACTIONDISCOUNTS_IVALIDATOR_H


template <typename T>
class IValidator {
public:
    virtual bool isValid(T value) = 0;
};


#endif //TRANSACTIONDISCOUNTS_IVALIDATOR_H
