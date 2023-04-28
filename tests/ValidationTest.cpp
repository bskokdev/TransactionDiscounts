#include <gtest/gtest.h>
#include "validation/ShippingTransactionValidator.h"

TEST(ValidationTest, ValidAttributes) {
    std::vector<std::string> attributes = {"2020-01-12", "S", "LP"};
    ShippingTransactionValidator transactionValidator;
    EXPECT_TRUE(transactionValidator.areValidTypeAttributes(attributes));
}

TEST(ValidationTest, InvalidNumberOfAttributes) {
    std::vector<std::string> attributes = {"2020-01-01", "S", "LP", "extra"};
    ShippingTransactionValidator transactionValidator;
    EXPECT_FALSE(transactionValidator.areValidTypeAttributes(attributes));
}

TEST(ValidationTest, InvalidProvider) {
    std::vector<std::string> attributes = {"2020-01-01", "S"};
    ShippingTransactionValidator transactionValidator;
    EXPECT_FALSE(transactionValidator.areValidTypeAttributes(attributes));
}

TEST(ValidationTest, InvalidDates) {
    ShippingTransactionValidator transactionValidator;

    std::vector<std::string> attributes1 = {"2020-13-01", "S", "MR"};
    EXPECT_FALSE(transactionValidator.areValidTypeAttributes(attributes1));

    std::vector<std::string> attributes2 = {"2020-01-33", "S", "MR"};
    EXPECT_FALSE(transactionValidator.areValidTypeAttributes(attributes2));
}

TEST(ValidationTest, InvalidPackageSize) {
    std::vector<std::string> attributes = {"2020-01-01", "XL", "MR"};
    ShippingTransactionValidator transactionValidator;
    EXPECT_FALSE(transactionValidator.areValidTypeAttributes(attributes));
}
