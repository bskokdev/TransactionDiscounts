#include "MonthlyDiscountInfo.h"

MonthlyDiscountInfo::MonthlyDiscountInfo() : usedDiscount(0) {
    // Initialize the map with 0 for each package size
    for(int i = 0; i < static_cast<int>(PackageSize::EnumSize); i++) {
        this->sizesCount[static_cast<PackageSize>(i)] = 0;
    }

    // Initialize the map with 0 for each provider
    for(int i = 0; i < static_cast<int>(Provider::EnumSize); i++) {
        this->providersCount[static_cast<Provider>(i)] = 0;
    }
}

double MonthlyDiscountInfo::getUsedDiscount() const {
    return this->usedDiscount;
}

void MonthlyDiscountInfo::setUsedDiscount(double discount) {
    this->usedDiscount = discount;
}

int MonthlyDiscountInfo::getSizesCount(PackageSize size) const {
    return this->sizesCount.at(size);
}

void MonthlyDiscountInfo::incrementSizesCount(PackageSize size) {
    this->sizesCount[size]++;
}

int MonthlyDiscountInfo::getProvidersCount(Provider provider) const {
    return this->providersCount.at(provider);
}

void MonthlyDiscountInfo::incrementProvidersCount(Provider provider) {
    this->providersCount[provider]++;
}


