#include "ShippingOptionHash.h"

std::size_t ShippingOptionHash::operator()(const ShippingOption &s) const {
    std::size_t h1 = std::hash<Provider>{}(s.getProvider());
    std::size_t h2 = std::hash<PackageSize>{}(s.getSize());
    std::size_t h3 = std::hash<double>{}(s.getPrice());

    // Combine the hashes (example hash combination)
    return h1 ^ (h2 << 1) ^ (h3 << 2);
}