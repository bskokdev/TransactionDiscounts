#ifndef TRANSACTIONDISCOUNTS_DISCOUNTSERVICE_H
#define TRANSACTIONDISCOUNTS_DISCOUNTSERVICE_H


#include <map>
#include <iostream>
#include "../shipping/shippingOption/ShippingOption.h"
#include "MonthlyDiscountInfo.h"
#include "transaction/ShippingTransaction.h"

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
    double calcDiscountForPackage(ShippingOption &shippingOption) const;

    /**
     * Calculates discount for large package
     * @param shippingOption Shipping option to calculate discount for
     * @param info Monthly discount info
     * @return discount
     */
    static double calcDiscountForPackage(ShippingOption &shippingOption, MonthlyDiscountInfo &info);

    /**
     * @brief Applies discount to available amount
     * @param info Monthly discount info
     * @param discount discount to be applied
     */
    static void applyDiscountToAvailableAmount(MonthlyDiscountInfo &info, double &discount);
public:
    /**
     * @brief Default constructor for DiscountService
     */
    DiscountService();

    /**
     * @brief Constructor for DiscountService
     * @param maxMonthlyDiscount maximum monthly discount
     */
    explicit DiscountService(double maxMonthlyDiscount);

    /**
     * @brief Calculates discount for given transaction
     * @param transaction Transaction to calculate discount for
     * @return discount
     */
    double calcDiscountForTransaction(ShippingTransaction &transaction);

    /**
     * @brief Applies discount to transaction
     * @param transaction Transaction to apply discount to
     * @param discount discount to be applied
     */
    static void applyDiscountToTransaction(ShippingTransaction &transaction, double discount);

    // getters and setters
    void setMinSmallPackagePrice(double minSmallPackagePrice);
};


#endif //TRANSACTIONDISCOUNTS_DISCOUNTSERVICE_H