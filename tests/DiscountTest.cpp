#include <gtest/gtest.h>
#include "shipping/PackageSize.h"
#include "shipping/shippingOption/ShippingOption.h"
#include "discount/DiscountService.h"
#include "shipping/shippingOption/ShippingOptionRepository.h"

/**
 * This is a test for the DiscountService class
 */

/**
 * @brief Mocks a transaction
 * @return mocked transaction
 */
ShippingTransaction mockTransaction(PackageSize size, double price, Provider provider) {
    Date date = Date(1, 1, 2020);

    ShippingOption shippingOption(provider, size, price);
    return {date, shippingOption};
}

/**
 * @brief Mocks a repository for shipping options
 * @return Shipping option repository
 */
ShippingOptionRepository mockRepository() {
    ShippingOptionRepository repo;
    repo.add(ShippingOption(Provider::LP, PackageSize::S, 1.50));
    repo.add(ShippingOption(Provider::LP, PackageSize::M, 4.90));
    repo.add(ShippingOption(Provider::LP, PackageSize::L, 6.90));

    repo.add(ShippingOption(Provider::MR, PackageSize::S, 2.00));
    repo.add(ShippingOption(Provider::MR, PackageSize::M, 3.00));
    repo.add(ShippingOption(Provider::MR, PackageSize::L, 4.00));
    return repo;
}

DiscountService mockDiscountService() {
    ShippingOptionRepository repo = mockRepository();
    double minSmallPackagePrice = repo.findLowestPriceForSize(PackageSize::S);

    DiscountService discountService(10.0);
    discountService.setMinSmallPackagePrice(minSmallPackagePrice);
    return discountService;
}

TEST(DiscountTest, CalculateDiscountForTransaction) {
    DiscountService discountService = mockDiscountService();
    ShippingTransaction t1 = mockTransaction(PackageSize::L, 6.90, Provider::LP);
    ShippingTransaction t2 = mockTransaction(PackageSize::L, 6.90, Provider::LP);
    ShippingTransaction t3 = mockTransaction(PackageSize::L, 6.90, Provider::LP);
    ShippingTransaction t4 = mockTransaction(PackageSize::S, 4.00, Provider::LP);
    ShippingTransaction t5 = mockTransaction(PackageSize::S, 4.00, Provider::LP);

    double discount1 = discountService.calcDiscountForTransaction(t1);
    double discount2 = discountService.calcDiscountForTransaction(t2);
    double discount3 = discountService.calcDiscountForTransaction(t3);
    double discount4 = discountService.calcDiscountForTransaction(t4);
    double discount5 = discountService.calcDiscountForTransaction(t5);

    // Every third large package provided by LP is free
    ASSERT_DOUBLE_EQ(discount1, 0.0);
    ASSERT_DOUBLE_EQ(discount2, 0.0);
    ASSERT_DOUBLE_EQ(discount3, 6.90); // The third large package by LP should be free

    // Transaction of small package is adjusted to the lowest price for small size in the shipping repository
    double expectedSmallPackageDiscount = 4.00 - 1.50; // 4.00 (transaction price) - 1.50 (lowest small package price)
    ASSERT_DOUBLE_EQ(discount4, expectedSmallPackageDiscount);

    // The last transaction should get the remaining available discount
    double remainingDiscount = 10.0 - (discount1 + discount2 + discount3 + discount4);
    ASSERT_DOUBLE_EQ(discount5, remainingDiscount);
}


TEST(DiscountTest, ApplyDiscountToTransaction) {
    DiscountService discountService;
    ShippingTransaction transaction = mockTransaction(PackageSize::S, 10.0, Provider::LP);

    double discount = 8.2;
    DiscountService::applyDiscountToTransaction(transaction, discount);

    EXPECT_DOUBLE_EQ(transaction.getShippingOption().getPrice(), 1.8);
}