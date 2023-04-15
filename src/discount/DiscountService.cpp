#include "DiscountService.h"

DiscountService::DiscountService(double maxMonthlyDiscount) : maxMonthlyDiscount(maxMonthlyDiscount) {
    // default
    this->minSmallPackagePrice = INT_MAX;
}

double DiscountService::calcDiscountForTransaction(Transaction &transaction) {
    std::string currentMonth = transaction.getDate().getMonthYear();

    // If the month is not in the map, create a new MonthlyDiscountInfo for that month
    if (!this->discountTracker.count(currentMonth)) {
        this->discountTracker[currentMonth] = MonthlyDiscountInfo(this->maxMonthlyDiscount);
    }

    MonthlyDiscountInfo &info = this->discountTracker[currentMonth];

    ShippingOption shippingOption = transaction.getShippingOption();
    info.incrementMonthlyCounters(shippingOption.getSize(), shippingOption.getProvider());

    double discount = calcDiscountBasedOnSize(shippingOption, info);
    // validate discount if not greater than available discount amount
    applyDiscountToAvailableAmount(info, discount);

    return discount;
}

void DiscountService::applyDiscountToAvailableAmount(MonthlyDiscountInfo &info, double &discount) {
    double availableDiscount = info.getAvailableDiscount();

    if (discount > availableDiscount) {
        discount = availableDiscount;
        info.setAvailableDiscount(0.0);
    } else {
        info.decreaseAvailableDiscount(discount);
    }
}

double DiscountService::calcDiscountBasedOnSize(ShippingOption &shippingOption, MonthlyDiscountInfo &info) {
    switch (shippingOption.getSize()) {
        case PackageSize::S:
            return this->calcDiscountForSmallPackage(shippingOption);
        case PackageSize::L:
            return calcDiscountForLargePackage(shippingOption, info);
        default:
            return 0.0;
    }
}

double DiscountService::calcDiscountForSmallPackage(ShippingOption &shippingOption) const {
    if (shippingOption.getSize() == PackageSize::S) {
        if (shippingOption.getPrice() >= this->minSmallPackagePrice) {
            return shippingOption.getPrice() - this->minSmallPackagePrice;
        }
    }
    return 0.0;
}

double DiscountService::calcDiscountForLargePackage(ShippingOption &shippingOption, MonthlyDiscountInfo &info) {
    if (shippingOption.getSize() == PackageSize::L && info.getLargeLpPackagesCount() == 3) {
        return shippingOption.getPrice();
    }
    return 0.0;
}

void DiscountService::applyDiscountToTransaction(Transaction &transaction, double discount) {
    transaction.updateShippingPrice(transaction.getShippingOption().getPrice() - discount);
}

void DiscountService::setMinSmallPackagePrice(double minSmallPackagePrice) {
    this->minSmallPackagePrice = minSmallPackagePrice;
}

DiscountService::DiscountService() : maxMonthlyDiscount(0.0), minSmallPackagePrice(INT_MAX) {}
