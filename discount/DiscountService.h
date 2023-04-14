#ifndef TRANSACTIONDISCOUNTS_DISCOUNTSERVICE_H
#define TRANSACTIONDISCOUNTS_DISCOUNTSERVICE_H


#include <map>
#include <iostream>
#include "../shipping/shippingOption/ShippingOption.h"
#include "MonthlyDiscountInfo.h"
#include "../transaction/Transaction.h"

/**
 * @brief Class representing a service for discounts
 */
class DiscountService {
private:
    std::map<std::string, MonthlyDiscountInfo> discountTracker;
    double minSmallPackagePrice;
    double maxMonthlyDiscount;

    /**
     * Calculates discount based on size of package
     * @param shippingOption Shipping option to calculate discount for
     * @param info Monthly discount info
     * @return discount
     */
    double calcDiscountBasedOnSize(ShippingOption &shippingOption, MonthlyDiscountInfo &info);

    /**
     * Calculates discount for small package
     * @param shippingOption Shipping option to calculate discount for
     * @return discount
     */
    double calcDiscountForSmallPackage(ShippingOption &shippingOption) const;

    /**
     * Calculates discount for large package
     * @param shippingOption Shipping option to calculate discount for
     * @param info Monthly discount info
     * @return discount
     */
    static double calcDiscountForLargePackage(ShippingOption &shippingOption, MonthlyDiscountInfo &info) ;

    /**
     * @brief Applies discount to available amount
     * @param info Monthly discount info
     * @param discount discount to be applied
     */
    static void applyDiscountToAvailableAmount(MonthlyDiscountInfo &info, double &discount);

public:
    explicit DiscountService(double maxMonthlyDiscount);

    /**
     * @brief Calculates discount for given transaction
     * @param transaction Transaction to calculate discount for
     * @return discount
     */
    double calcDiscountForTransaction(Transaction &transaction);

    /**
     * @brief Applies discount to transaction
     * @param transaction Transaction to apply discount to
     * @param discount discount to be applied
     */
    static void applyDiscountToTransaction(Transaction &transaction, double discount);

    void setMinSmallPackagePrice(double minSmallPackagePrice);
};


#endif //TRANSACTIONDISCOUNTS_DISCOUNTSERVICE_H