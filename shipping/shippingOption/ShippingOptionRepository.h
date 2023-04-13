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

    ShippingOption findFromString(const std::string &provider, const std::string &packageSize);
    ShippingOption findFromProviderAndPackageSize(Provider provider, PackageSize packageSize);
    // IDataRepository methods
    bool exists(const ShippingOption& shippingOption) override;
    void add(const ShippingOption& shippingOption) override;
    void remove(const ShippingOption& shippingOption) override;
    void update(const ShippingOption& shippingOption) override;
    std::vector<ShippingOption> getAll() override;
};


#endif //TRANSACTIONDISCOUNTS_SHIPPINGOPTIONREPOSITORY_H
