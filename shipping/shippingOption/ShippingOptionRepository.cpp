#include "ShippingOptionRepository.h"

ShippingOptionRepository::ShippingOptionRepository() {}

bool ShippingOptionRepository::exists(const ShippingOption &shippingOption) {
    for(auto& option : this->shippingOptions) {
        if(option == shippingOption) {
            return true;
        }
    }
    return false;
}

void ShippingOptionRepository::add(const ShippingOption &shippingOption) {
    // set does not allow duplicates -> no need to check if exists
    this->shippingOptions.push_back(shippingOption);
}

void ShippingOptionRepository::remove(const ShippingOption &shippingOption) {
    if(this->exists(shippingOption)) {
        // find the shipping option and remove it using the iterator
        auto it = std::find(this->shippingOptions.begin(), this->shippingOptions.end(), shippingOption);
        this->shippingOptions.erase(it);
    }
}

void ShippingOptionRepository::update(const ShippingOption &shippingOption) {
    // find the shipping option and overwrite it
    if(this->exists(shippingOption)) {
        for(auto& option : this->shippingOptions) {
            if(option == shippingOption) {
                option = shippingOption;
            }
        }
    }
}

std::vector<ShippingOption> ShippingOptionRepository::getAll() {
    return this->shippingOptions;
}

ShippingOption ShippingOptionRepository::findFromString(const std::string &provider, const std::string &packageSize) {
    // convert the strings to enums
    Provider providerEnum = getProviderFromString(provider);
    PackageSize packageSizeEnum = getPackageSizeFromString(packageSize);

    return this->findFromProviderAndPackageSize(providerEnum, packageSizeEnum);
}

ShippingOption ShippingOptionRepository::findFromProviderAndPackageSize(Provider provider, PackageSize packageSize) {
    for(auto& option : this->shippingOptions) {
        if(option.getProvider() == provider && option.getSize() == packageSize) {
            return option;
        }
    }
    throw std::invalid_argument("No shipping option found");
}

double ShippingOptionRepository::findLowestPriceForPackageSize(PackageSize packageSize) {
    double lowestPrice = INT_MAX;
    for(auto& option : this->shippingOptions) {
        if(option.getSize() == packageSize) {
            if(option.getPrice() < lowestPrice) {
                lowestPrice = option.getPrice();
            }
        }
    }
    return lowestPrice;
}

