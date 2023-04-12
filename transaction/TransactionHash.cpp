#include "TransactionHash.h"

std::size_t TransactionHash::operator()(const Transaction &t) const {
    // Hashing the date
    std::size_t date_hash = std::hash<int>{}(t.getDate().getDay()) ^
                            (std::hash<int>{}(t.getDate().getMonth()) << 1) ^
                            (std::hash<int>{}(t.getDate().getYear()) << 2);

    // Hashing the shipping option
    std::size_t shipping_option_hash = std::hash<int>{}(static_cast<int>(t.getShippingOption().getProvider())) ^
                                       (std::hash<int>{}(static_cast<int>(t.getShippingOption().getSize())) << 1) ^
                                       (std::hash<double>{}(t.getShippingOption().getPrice()) << 2);
    // Combining the hashes
    return date_hash ^ (shipping_option_hash << 1);
}
