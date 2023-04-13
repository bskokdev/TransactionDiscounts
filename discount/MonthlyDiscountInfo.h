#ifndef TRANSACTIONDISCOUNTS_MONTHLYDISCOUNTINFO_H
#define TRANSACTIONDISCOUNTS_MONTHLYDISCOUNTINFO_H

struct MonthlyDiscountInfo {
    double usedDiscount;
    int largePackageCount;

    // default constructor
    MonthlyDiscountInfo() : usedDiscount(0), largePackageCount(0) {}
};

#endif //TRANSACTIONDISCOUNTS_MONTHLYDISCOUNTINFO_H
