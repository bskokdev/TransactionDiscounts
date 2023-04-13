#include "DiscountService.h"

DiscountService::DiscountService(double minSmallPackagePrice, double maxMonthlyDiscount)
        : minSmallPackagePrice(minSmallPackagePrice), maxMonthlyDiscount(maxMonthlyDiscount) {}

double DiscountService::calcDiscountForTransaction(Transaction &transaction) {
    std::string currentMonth = transaction.getDate().getMonthYear();
    MonthlyDiscountInfo &info = this->discountTracker[currentMonth];

    ShippingOption shippingOption = transaction.getShippingOption();
    double discount = calcDiscountBasedOnSize(shippingOption, info);

    if (isDiscountCapReached(info)) {
        discount = this->maxMonthlyDiscount - info.usedDiscount;
    } else {
        info.usedDiscount += discount;
    }
    return discount;
}

double DiscountService::calcDiscountBasedOnSize(ShippingOption &shippingOption, MonthlyDiscountInfo &info) {
    switch (shippingOption.getSize()) {
        case PackageSize::S:
            return this->calcDiscountForSmallPackage(shippingOption, info);
        case PackageSize::L:
            return this->calcDiscountForLargePackage(shippingOption, info);
        default:
            return 0.0;
    }
}

double DiscountService::calcDiscountForSmallPackage(ShippingOption &shippingOption, MonthlyDiscountInfo &info) {
    if (shippingOption.getSize() == PackageSize::S) {
        info.sizesCount[shippingOption.getSize()]++;
        if (shippingOption.getPrice() >= this->minSmallPackagePrice) {
            return shippingOption.getPrice() - this->minSmallPackagePrice;
        }
    }
    return 0.0;
}

double DiscountService::calcDiscountForLargePackage(ShippingOption &shippingOption, MonthlyDiscountInfo &info) {
    if(shippingOption.getSize() == PackageSize::L) {
        info.sizesCount[shippingOption.getSize()]++;
        if (isFreeLargePackage(shippingOption, info)) {
            return shippingOption.getPrice();
        }
    }
    return 0.0;
}

bool DiscountService::isFreeLargePackage(ShippingOption &shippingOption, MonthlyDiscountInfo &info) {
    // check if the package is large and the provider is LP
    if (shippingOption.getSize() == PackageSize::L && shippingOption.getProvider() == Provider::LP) {
        // check if there have been already 2 transactions with LP large package in the month of the current transaction
        // if so, return true else return false
        if (info.sizesCount[PackageSize::L] == 2) {
            return true;
        }
    }
    return false;
}

void DiscountService::applyDiscountToTransaction(Transaction &transaction, double discount) {
    transaction.updateShippingPrice(transaction.getShippingOption().getPrice() - discount);
}

bool DiscountService::isDiscountCapReached(MonthlyDiscountInfo &info) {
    return info.usedDiscount >= this->maxMonthlyDiscount;
}
