#ifndef TRANSACTIONDISCOUNTS_MONTHLYDISCOUNTINFO_H
#define TRANSACTIONDISCOUNTS_MONTHLYDISCOUNTINFO_H

#include <map>
#include "../shipping/PackageSize.h"
#include "../shipping/Provider.h"

class MonthlyDiscountInfo {
private:
    double availableDiscount;
    int largeLpPackagesCount;
public:
    // default constructor
    MonthlyDiscountInfo();

    explicit MonthlyDiscountInfo(double availableDiscount);

    /**
     * Increments count of packages with given size
     * @param size Package size to increment count for
     * @param provider Provider of package
     */
    void incrementMonthlyCounters(PackageSize size, Provider provider);

    /**
     * Decreases available discount by given amount
     * @param discount
     */
    void decreaseAvailableDiscount(double discount);

    // getters and setters
    double getAvailableDiscount() const;

    void setAvailableDiscount(double availableDiscount);

    int getLargeLpPackagesCount() const;


};

#endif //TRANSACTIONDISCOUNTS_MONTHLYDISCOUNTINFO_H
