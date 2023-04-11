#include "ShippingOptionRepository.h"

ShippingOptionRepository::ShippingOptionRepository() {}

ShippingOptionRepository &ShippingOptionRepository::getInstance() {
    static ShippingOptionRepository instance;
    return instance;
}

bool ShippingOptionRepository::exists(const ShippingOption &shippingOption) {
    return this->shippingOptions.count(shippingOption);
}

void ShippingOptionRepository::add(const ShippingOption &shippingOption) {
    // set does not allow duplicates -> no need to check if exists
    this->shippingOptions.insert(shippingOption);
}

void ShippingOptionRepository::remove(const ShippingOption &shippingOption) {
    if(this->exists(shippingOption)) {
        this->shippingOptions.erase(shippingOption);
    }
}

void ShippingOptionRepository::update(const ShippingOption &shippingOption) {
    // replace the old shipping option with the new one
    if(this->exists(shippingOption)) {
        this->shippingOptions.erase(shippingOption);
        this->shippingOptions.insert(shippingOption);
    }
}
