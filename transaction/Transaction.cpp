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

bool Transaction::operator<(const Transaction &other) {
    if (date.getYear() != other.date.getYear()) {
        return date.getYear() < other.date.getYear();
    }
    if (date.getMonth() != other.date.getMonth()) {
        return date.getMonth() < other.date.getMonth();
    }
    if (date.getDay() != other.date.getDay()) {
        return date.getDay() < other.date.getDay();
    }
    return shippingOption < other.shippingOption;
}


bool Transaction::operator==(const Transaction &other) const {
    return date.getDay() == other.date.getDay() &&
           date.getMonth() == other.date.getMonth() &&
           date.getYear() == other.date.getYear() &&
           shippingOption.getPrice() == other.shippingOption.getPrice() &&
           shippingOption.getSize() == other.shippingOption.getSize() &&
           shippingOption.getProvider() == other.shippingOption.getProvider();
}

std::ostream &operator<<(std::ostream &os, const Transaction &transaction) {
    os << transaction.date << " " << transaction.shippingOption;
    return os;
}