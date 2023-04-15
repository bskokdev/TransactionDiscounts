#include "MonthlyDiscountInfo.h"

MonthlyDiscountInfo::MonthlyDiscountInfo() : availableDiscount(0), largeLpPackagesCount(0) {}

MonthlyDiscountInfo::MonthlyDiscountInfo(double availableDiscount)
        : availableDiscount(availableDiscount), largeLpPackagesCount(0) {
}

void MonthlyDiscountInfo::incrementMonthlyCounters(PackageSize size, Provider provider) {
    // If the package is large and the provider is LP, increment the count
    // here we could also increment the count for other package sizes and providers
    if (size == PackageSize::L && provider == Provider::LP) {
        this->largeLpPackagesCount++;
    }
}

void MonthlyDiscountInfo::decreaseAvailableDiscount(double discount) {
    this->availableDiscount -= discount;
}

double MonthlyDiscountInfo::getAvailableDiscount() const {
    return this->availableDiscount;
}

void MonthlyDiscountInfo::setAvailableDiscount(double availableDiscount) {
    this->availableDiscount = availableDiscount;
}

int MonthlyDiscountInfo::getLargeLpPackagesCount() const {
    return this->largeLpPackagesCount;
}
