#include "Transaction.h"

Transaction::Transaction(): date(Date()) {}

Transaction::Transaction(const Date &date) : date(date) {}

bool Transaction::isEmpty() {
    return this->date == Date();
}

const Date &Transaction::getDate() const {
    return this->date;
}

void Transaction::setDate(const Date &date) {
    this->date = date;
}


