#ifndef TRANSACTIONDISCOUNTS_MONTHLYDISCOUNTINFO_H
#define TRANSACTIONDISCOUNTS_MONTHLYDISCOUNTINFO_H

#include <map>
#include "../shipping/PackageSize.h"
#include "../shipping/Provider.h"

class MonthlyDiscountInfo {
private:
    double usedDiscount;
    std::map<PackageSize, int> sizesCount;
    std::map<Provider, int> providersCount;
public:
    // default constructor
    MonthlyDiscountInfo();

    double getUsedDiscount() const;

    void setUsedDiscount(double discount);

    int getSizesCount(PackageSize size) const;

    int getProvidersCount(Provider provider) const;

    /**
     * Increments count of packages with given size
     * @param size Package size to increment count for
     */
    void incrementSizesCount(PackageSize size);

    /**
     * Increments count of packages with given provider
     * @param provider Provider to increment count for
     */
    void incrementProvidersCount(Provider provider);
};

#endif //TRANSACTIONDISCOUNTS_MONTHLYDISCOUNTINFO_H
