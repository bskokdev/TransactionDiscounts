#include <iomanip>
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

bool ShippingOption::operator==(const ShippingOption &other) const {
    return provider == other.provider &&
           size == other.size &&
           price == other.price;
}

bool ShippingOption::operator<(const ShippingOption &other) const {
    if (provider < other.provider) {
        return true;
    } else if (provider == other.provider) {
        if (size < other.size) {
            return true;
        } else if (size == other.size) {
            return price < other.price;
        }
    }
    return false;
}

/**
 * @brief Overload of the << operator for ShippingOption
 * @param os The output stream
 * @param option The ShippingOption to be printed
 */
std::ostream &operator<<(std::ostream &os, const ShippingOption &option) {
    os << option.getSize() << " " << option.getProvider() << " "
       << std::fixed << std::setprecision(2) << option.getPrice();
    return os;
}
