#ifndef TRANSACTIONDISCOUNTS_SHIPPINGOPTIONHASH_H
#define TRANSACTIONDISCOUNTS_SHIPPINGOPTIONHASH_H

#include "ShippingOption.h"
#include <functional>

/**
 * @brief Hash function for ShippingOption
 */
struct ShippingOptionHash {
    /**
     * @brief Hash function for ShippingOption
     * @param s shipping option to hash
     * @return hash of the shipping option
     */
    std::size_t operator()(const ShippingOption &s) const;
};


#endif //TRANSACTIONDISCOUNTS_SHIPPINGOPTIONHASH_H
