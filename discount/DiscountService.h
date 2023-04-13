#ifndef TRANSACTIONDISCOUNTS_DISCOUNTSERVICE_H
#define TRANSACTIONDISCOUNTS_DISCOUNTSERVICE_H


#include <map>
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
     * @brief Checks if large package is free
     * @param transaction Transaction to check
     * @return true if large package is free
     */
    bool isFreeLargePackage(ShippingOption &shippingOption, MonthlyDiscountInfo &info);

    /**
     * @brief Calculates discount for given transaction
     * @param transaction Transaction to calculate discount for
     * @return discount
     */
    double calcDiscountForTransaction(Transaction &transaction);

    double calcDiscountBasedOnSize(ShippingOption &shippingOption, MonthlyDiscountInfo &info);

    /**
     * Calculates discount for small package
     * @param shippingOption Shipping option to calculate discount for
     * @return discount
     */
    double calcDiscountForSmallPackage(ShippingOption &shippingOption);

    double calcDiscountForLargePackage(ShippingOption &option, MonthlyDiscountInfo &info);

    /**
     * @brief Checks if discount cap is reached
     * @param monthKey Key of month to check
     * @return true if discount cap is reached
     */
    bool isDiscountCapReached(MonthlyDiscountInfo &info);

    /**
     * @brief Applies discount to transaction
     * @param transaction Transaction to apply discount to
     * @param discount discount to be applied
     */
    void applyDiscountToTransaction(Transaction &transaction, double discount);
public:
    DiscountService(double minSmallPackagePrice, double maxMonthlyDiscount);

    /**
     * @brief Calculates and applies discount to a transaction
     * @param transaction Transaction to apply usedDiscount to
     * @param discount Discount to apply
     * @return pair of transaction and discount
     */
    std::pair<Transaction, double> manageTransactionDiscount(Transaction &transaction);

};


#endif //TRANSACTIONDISCOUNTS_DISCOUNTSERVICE_H