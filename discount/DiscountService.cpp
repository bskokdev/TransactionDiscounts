#include "DiscountService.h"

DiscountService::DiscountService(double minSmallPackagePrice, double maxMonthlyDiscount)
    : minSmallPackagePrice(minSmallPackagePrice), maxMonthlyDiscount(maxMonthlyDiscount) {}

void DiscountService::manageTransactionDiscount(Transaction &transaction) {
    double discount = calcDiscountForTransaction(transaction);
    applyDiscountToTransaction(transaction, discount);
}

double DiscountService::calcDiscountForTransaction(Transaction &transaction) {
    std::string currentMonth = transaction.getDate().getMonthYear();
    MonthlyDiscountInfo& info = this->discountTracker[currentMonth];

    ShippingOption shippingOption = transaction.getShippingOption();
    double discount = calcDiscountBasedOnSize(shippingOption, info);

    if(isDiscountCapReached(info)) {
        discount = this->maxMonthlyDiscount - info.usedDiscount;
    } else {
        info.usedDiscount += discount;
    }
    return discount;
}

double DiscountService::calcDiscountBasedOnSize(ShippingOption &shippingOption, MonthlyDiscountInfo &info) {
    switch(shippingOption.getSize()) {
        case PackageSize::S:
            return this->calcDiscountForSmallPackage(shippingOption);
        case PackageSize::L:
            return this->calcDiscountForLargePackage(shippingOption, info);
        default:
            return 0.0;
    }
}

double DiscountService::calcDiscountForSmallPackage(ShippingOption &shippingOption) {
    if(shippingOption.getSize() == PackageSize::S) {
        if(shippingOption.getPrice() >= this->minSmallPackagePrice) {
            return shippingOption.getPrice() - this->minSmallPackagePrice;
        }
    }
    return 0.0;
}

double DiscountService::calcDiscountForLargePackage(ShippingOption &option, MonthlyDiscountInfo &info) {
    info.largePackageCount++;
    if(isFreeLargePackage(option, info)) {
        return option.getPrice();
    }
    return 0.0;
}

bool DiscountService::isFreeLargePackage(ShippingOption &shippingOption, MonthlyDiscountInfo &info) {
    // check if the package is large and the provider is LP
    if (shippingOption.getSize() == PackageSize::L && shippingOption.getProvider() == Provider::LP) {
        // check if there have been already 2 transactions with LP large package in the month of the current transaction
        // if so, return true else return false
        if(info.largePackageCount == 2) {
            return true;
        }
    }
    return false;
}

void DiscountService::applyDiscountToTransaction(Transaction &transaction, double discount) {
    transaction.getShippingOption().setPrice(transaction.getShippingOption().getPrice() - discount);
}

bool DiscountService::isDiscountCapReached(MonthlyDiscountInfo &info) {
    return info.usedDiscount >= this->maxMonthlyDiscount;
}
