#ifndef TRANSACTIONDISCOUNTS_SHIPPINGOPTIONREPOSITORY_H
#define TRANSACTIONDISCOUNTS_SHIPPINGOPTIONREPOSITORY_H

#include <unordered_set>
#include <stdexcept>
#include "ShippingOption.h"
#include "../../common/IDataRepository.h"
#include "ShippingOptionHash.h"

/**
 * @brief Class representing a repository for shipping options
 */
class ShippingOptionRepository : public IDataRepository<ShippingOption> {
private:
    std::vector<ShippingOption> shippingOptions;
public:
    // constructor
    ShippingOptionRepository();

    /**
     * @brief Finds a shipping option from a given provider and package size as strings
     * @param provider string representation of provider
     * @param packageSize string representation of package size
     * @return ShippingOption
     */
    ShippingOption findFromString(const std::string &provider, const std::string &packageSize);

    /**
     * @brief Finds a shipping option from a given provider and package size
     * @param provider
     * @param packageSize
     * @return ShippingOption
     */
    ShippingOption findFromProviderAndPackageSize(Provider provider, PackageSize packageSize);

    /**
     * @brief Finds the lowest price for a given package size
     * @param packageSize Package size to find lowest price for
     * @return double Lowest price
     */
    double findLowestPriceForSize(PackageSize packageSize);

    // IDataRepository methods
    bool exists(const ShippingOption &shippingOption) override;

    void add(const ShippingOption &shippingOption) override;

    void remove(const ShippingOption &shippingOption) override;

    void update(const ShippingOption &shippingOption) override;

    std::vector<ShippingOption> getAll() override;
};


#endif //TRANSACTIONDISCOUNTS_SHIPPINGOPTIONREPOSITORY_H
