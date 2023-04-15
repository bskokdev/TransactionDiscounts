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
     * @brief Default constructor for Transaction
     */
    Transaction() = default;
    /**
     * @brief Constructor for Transaction
     * @param date date of the transaction
     * @param shippingOption shipping option of the transaction
     */
    Transaction(const Date &date, const ShippingOption &shippingOption);

    bool isEmpty();

    // Getters and setters
    const Date &getDate() const;

    void setDate(const Date &date);

    const ShippingOption getShippingOption();

    void updateShippingPrice(double newPrice);

    void setShippingOption(const ShippingOption &shippingOption);

    // operators
    bool operator<(const Transaction &other) const;

    bool operator==(const Transaction &other) const;

    /**
     * @brief Overload of the << operator for Transaction
     * @param os output stream
     * @param transaction Transaction to be printed
     * @return reference to the output stream
     */
    friend std::ostream &operator<<(std::ostream &os, Transaction &transaction);
};


#endif //TRANSACTIONDISCOUNTS_TRANSACTION_H
