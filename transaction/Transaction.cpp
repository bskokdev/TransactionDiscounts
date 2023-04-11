#include "Transaction.h"

Transaction::Transaction(const Date &date, const ShippingOption &shippingOption) : date(date),
                                                                                   shippingOption(shippingOption) {}
const Date &Transaction::getDate() const {
    return date;
}

void Transaction::setDate(const Date &date) {
    Transaction::date = date;
}

const ShippingOption &Transaction::getShippingOption() const {
    return shippingOption;
}

void Transaction::setShippingOption(const ShippingOption &shippingOption) {
    Transaction::shippingOption = shippingOption;
}
