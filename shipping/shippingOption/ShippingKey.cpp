#include "ShippingKey.h"

ShippingKey::ShippingKey(Provider provider, PackageSize size) {
    ShippingKey::provider = provider;
    ShippingKey::size = size;
}

bool ShippingKey::operator==(const ShippingKey &other) const {
    return provider == other.provider && size == other.size;
}

Provider ShippingKey::getProvider() const {
    return provider;
}

void ShippingKey::setProvider(Provider provider) {
    ShippingKey::provider = provider;
}

PackageSize ShippingKey::getSize() const {
    return size;
}

void ShippingKey::setSize(PackageSize size) {
    ShippingKey::size = size;
}

