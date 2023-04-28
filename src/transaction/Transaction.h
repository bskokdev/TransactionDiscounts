#ifndef TRANSACTIONDISCOUNTS_TRANSACTION_H
#define TRANSACTIONDISCOUNTS_TRANSACTION_H


#include "common/Date.h"

class Transaction {
protected:
    Date date;
public:
    /**
     * @brief Default constructor for Transaction
     */
    Transaction();

    /**
     * @brief Constructor for Transaction
     * @param date Date of transaction
     */
    explicit Transaction(const Date &date);

    /*
     * @brief Checks if transaction is empty
     */
    virtual bool isEmpty();

    // Getters and setters
    const Date &getDate() const;

    void setDate(const Date &date);
};


#endif //TRANSACTIONDISCOUNTS_TRANSACTION_H
