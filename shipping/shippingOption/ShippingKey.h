#ifndef TRANSACTIONDISCOUNTS_SHIPPINGKEY_H
#define TRANSACTIONDISCOUNTS_SHIPPINGKEY_H


#include "../Provider.h"
#include "../PackageSize.h"

/**
 * @brief Class representing a key for a shipping option in the shipping repository
 * @details The key is a combination of the provider and the package size
 */
class ShippingKey {
private:
    Provider provider;
    PackageSize size;

public:
    // Constructors
    ShippingKey() = default;

    ShippingKey(Provider provider, PackageSize size);

    // getters and setters
    Provider getProvider() const;

    void setProvider(Provider provider);

    PackageSize getSize() const;

    void setSize(PackageSize size);

    // == operator for ShippingKey
    bool operator==(const ShippingKey &other) const;
};

// Custom hash function for the ShippingKey
struct ShippingKeyHash {
    std::size_t operator()(const ShippingKey &key) const {
        return std::hash<int>()(static_cast<int>(key.getProvider())) ^
               (std::hash<int>()(static_cast<int>(key.getSize())) << 1);
    }
};


#endif //TRANSACTIONDISCOUNTS_SHIPPINGKEY_H
