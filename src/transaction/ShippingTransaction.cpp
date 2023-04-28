#include "ShippingTransaction.h"

ShippingTransaction::ShippingTransaction(): Transaction(Date()) {}

ShippingTransaction::ShippingTransaction(const Date &date, const ShippingOption &shippingOption)
: Transaction(date), shippingOption(shippingOption) {}

ShippingOption ShippingTransaction::getShippingOption() {
    return shippingOption;
}

void ShippingTransaction::updateShippingPrice(double newPrice) {
    shippingOption.setPrice(newPrice);
}

bool ShippingTransaction::operator<(const ShippingTransaction &other) const {
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


bool ShippingTransaction::operator==(const ShippingTransaction &other) const {
    return date.getDay() == other.date.getDay() &&
           date.getMonth() == other.date.getMonth() &&
           date.getYear() == other.date.getYear() &&
           shippingOption.getPrice() == other.shippingOption.getPrice() &&
           shippingOption.getSize() == other.shippingOption.getSize() &&
           shippingOption.getProvider() == other.shippingOption.getProvider();
}

std::ostream &operator<<(std::ostream &os, ShippingTransaction &transaction) {
    os << transaction.getDate() << " " << transaction.getShippingOption() << " ";
    return os;
}

bool ShippingTransaction::isEmpty() {
    return this->date == Date() && this->shippingOption.isEmpty();
}



