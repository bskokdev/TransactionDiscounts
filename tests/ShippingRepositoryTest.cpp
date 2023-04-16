#include <gtest/gtest.h>
#include "shipping/shippingOption/ShippingOptionRepository.h"

/**
 * This is a test for the ShippingOptionRepository class
 */

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

TEST(ShippingRepositoryTest, FindLowestPriceForSize) {
    ShippingOptionRepository repo = mockRepository();
    double lowestPriceSmall = repo.findLowestPriceForSize(PackageSize::S);
    double lowestPriceMedium = repo.findLowestPriceForSize(PackageSize::M);
    double lowestPriceLarge = repo.findLowestPriceForSize(PackageSize::L);

    ASSERT_DOUBLE_EQ(lowestPriceSmall, 1.50);
    ASSERT_DOUBLE_EQ(lowestPriceMedium, 3.00);
    ASSERT_DOUBLE_EQ(lowestPriceLarge, 4.00);
}

TEST(ShippingRepositoryTest, FindShippingOptionFromString) {
    ShippingOptionRepository repo = mockRepository();

    ShippingOption option1 = repo.findFromString("LP", "S");
    ASSERT_EQ(option1.getProvider(), Provider::LP);
    ASSERT_EQ(option1.getSize(), PackageSize::S);
    ASSERT_DOUBLE_EQ(option1.getPrice(), 1.50);

    ShippingOption option2 = repo.findFromString("MR", "M");
    ASSERT_EQ(option2.getProvider(), Provider::MR);
    ASSERT_EQ(option2.getSize(), PackageSize::M);
    ASSERT_DOUBLE_EQ(option2.getPrice(), 3.00);
}

TEST(ShippingRepositoryTest, FindFromProviderAndPackageSize) {
    ShippingOptionRepository repo = mockRepository();

    ShippingOption option1 = repo.findFromProviderAndPackageSize(Provider::LP, PackageSize::S);
    ShippingOption expectedOption1 = ShippingOption(Provider::LP, PackageSize::S, 1.50);
    ASSERT_EQ(option1, expectedOption1);

    ShippingOption option2 = repo.findFromProviderAndPackageSize(Provider::MR, PackageSize::M);
    ShippingOption expectedOption2 = ShippingOption(Provider::MR, PackageSize::M, 3.00);
    ASSERT_EQ(option2, expectedOption2);
}