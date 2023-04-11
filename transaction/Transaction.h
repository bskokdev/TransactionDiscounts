#ifndef TRANSACTIONDISCOUNTS_TRANSACTION_H
#define TRANSACTIONDISCOUNTS_TRANSACTION_H


#include "../common/Date.h"
#include "../shipping/shippingOption/ShippingOption.h"

/**
 * @brief Class representing a transaction in the system
 */
class Transaction {
private:
    Date date;
    ShippingOption shippingOption;
public:
    /**
     * @brief Constructor for Transaction
     * @param date date of the transaction
     * @param shippingOption shipping option of the transaction
     */
    Transaction(const Date& date, const ShippingOption& shippingOption);

    // Getters and setters
    const Date &getDate() const;

    void setDate(const Date &date);

    const ShippingOption &getShippingOption() const;

    void setShippingOption(const ShippingOption &shippingOption);

    // todo: implement following: ==, < operators, hash function
};


#endif //TRANSACTIONDISCOUNTS_TRANSACTION_H
