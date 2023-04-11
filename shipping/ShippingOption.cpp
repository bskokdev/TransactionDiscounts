#include "ShippingOption.h"

ShippingOption::ShippingOption(Provider provider, PackageSize size, double price) : provider(provider), size(size),
                                                                                    price(price) {}

Provider ShippingOption::getProvider() const {
    return provider;
}

void ShippingOption::setProvider(Provider provider) {
    ShippingOption::provider = provider;
}

PackageSize ShippingOption::getSize() const {
    return size;
}

void ShippingOption::setSize(PackageSize size) {
    ShippingOption::size = size;
}

double ShippingOption::getPrice() const {
    return price;
}

void ShippingOption::setPrice(double price) {
    ShippingOption::price = price;
}
