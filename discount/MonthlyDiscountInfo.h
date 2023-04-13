#ifndef TRANSACTIONDISCOUNTS_MONTHLYDISCOUNTINFO_H
#define TRANSACTIONDISCOUNTS_MONTHLYDISCOUNTINFO_H

struct MonthlyDiscountInfo {
    double usedDiscount;
    std::map<PackageSize, int> sizesCount;

    // default constructor
    MonthlyDiscountInfo() : usedDiscount(0) {}
};

#endif //TRANSACTIONDISCOUNTS_MONTHLYDISCOUNTINFO_H
