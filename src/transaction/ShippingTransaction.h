#ifndef TRANSACTIONDISCOUNTS_SHIPPINGTRANSACTION_H
#define TRANSACTIONDISCOUNTS_SHIPPINGTRANSACTION_H


#include "../common/Date.h"
#include "../shipping/shippingOption/ShippingOption.h"
#include "Transaction.h"

/**
 * @brief Class representing a transaction in the system
 */
class ShippingTransaction : public Transaction {
private:
    ShippingOption shippingOption;
public:
    /**
     * @brief Default constructor for ShippingTransaction
     */
    ShippingTransaction();

    /**
     * @brief Constructor for ShippingTransaction
     * @param date Date of transaction
     * @param shippingOption Shipping option of the transaction
     */
    ShippingTransaction(const Date &date, const ShippingOption &shippingOption);

    bool isEmpty() override;

    ShippingOption getShippingOption();

    void updateShippingPrice(double newPrice);

    // operators
    bool operator<(const ShippingTransaction &other) const;

    bool operator==(const ShippingTransaction &other) const;

    /**
     * @brief Overload of the << operator for Transaction
     * @param os output stream
     * @param transaction Transaction to be printed
     * @return reference to the output stream
     */
    friend std::ostream &operator<<(std::ostream &os, ShippingTransaction &transaction);
};


#endif //TRANSACTIONDISCOUNTS_SHIPPINGTRANSACTION_H
