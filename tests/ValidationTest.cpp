#include <gtest/gtest.h>
#include "validation/TransactionValidator.h"

TEST(ValidationTest, ValidAttributes) {
    std::vector<std::string> attributes = {"2020-01-12", "S", "LP"};
    TransactionValidator transactionValidator;
    EXPECT_TRUE(transactionValidator.areValid(attributes));
}

TEST(ValidationTest, InvalidNumberOfAttributes) {
    std::vector<std::string> attributes = {"2020-01-01", "S", "LP", "extra"};
    TransactionValidator transactionValidator;
    EXPECT_FALSE(transactionValidator.areValid(attributes));
}

TEST(ValidationTest, InvalidProvider) {
    std::vector<std::string> attributes = {"2020-01-01", "S"};
    TransactionValidator transactionValidator;
    EXPECT_FALSE(transactionValidator.areValid(attributes));
}

TEST(ValidationTest, InvalidDates) {
    TransactionValidator transactionValidator;

    std::vector<std::string> attributes1 = {"2020-13-01", "S", "MR"};
    EXPECT_FALSE(transactionValidator.areValid(attributes1));

    std::vector<std::string> attributes2 = {"2020-01-33", "S", "MR"};
    EXPECT_FALSE(transactionValidator.areValid(attributes2));
}

TEST(ValidationTest, InvalidPackageSize) {
    std::vector<std::string> attributes = {"2020-01-01", "XL", "MR"};
    TransactionValidator transactionValidator;
    EXPECT_FALSE(transactionValidator.areValid(attributes));
}
