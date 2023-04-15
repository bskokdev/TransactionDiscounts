#include "ShippingOptionRepository.h"

bool ShippingOptionRepository::exists(const ShippingOption &shippingOption) {
    return this->shippingOptions.count({shippingOption.getProvider(), shippingOption.getSize()});
}

void ShippingOptionRepository::add(const ShippingOption &shippingOption) {
    // add the shipping option to the map
    ShippingKey key = ShippingKey(shippingOption.getProvider(), shippingOption.getSize());
    this->shippingOptions[key] = shippingOption;
}

void ShippingOptionRepository::remove(const ShippingOption &shippingOption) {
    if (this->exists(shippingOption)) {
        // remove the shipping option from the map
        this->shippingOptions.erase({shippingOption.getProvider(), shippingOption.getSize()});
    } else {
        throw std::invalid_argument("Shipping option does not exist");
    }
}

void ShippingOptionRepository::update(const ShippingOption &shippingOption) {
    // find the shipping option and overwrite it via key
    ShippingKey key = ShippingKey(shippingOption.getProvider(), shippingOption.getSize());
    this->shippingOptions[key] = shippingOption;
}

std::vector<ShippingOption> ShippingOptionRepository::getAll() {
    // convert the map to a vector
    std::vector<ShippingOption> options;
    for (auto &[key, option]: this->shippingOptions) {
        options.push_back(option);
    }
    return options;
}

ShippingOption ShippingOptionRepository::findFromString(const std::string &provider, const std::string &packageSize) {
    // convert the strings to enums
    Provider providerEnum = getProviderFromString(provider);
    PackageSize packageSizeEnum = getPackageSizeFromString(packageSize);

    return this->findFromProviderAndPackageSize(providerEnum, packageSizeEnum);
}

ShippingOption ShippingOptionRepository::findFromProviderAndPackageSize(Provider provider, PackageSize packageSize) {
    ShippingKey key = ShippingKey(provider, packageSize);
    if (this->shippingOptions.count(key)) {
        return this->shippingOptions[key];
    }
    throw std::invalid_argument("No shipping option found");
}

double ShippingOptionRepository::findLowestPriceForSize(PackageSize packageSize) {
    double lowestPrice = INT_MAX;
    for (auto &[key, option]: this->shippingOptions) {
        if (option.getSize() == packageSize) {
            if (option.getPrice() < lowestPrice) {
                lowestPrice = option.getPrice();
            }
        }
    }
    return lowestPrice;
}

