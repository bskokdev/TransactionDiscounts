#ifndef TRANSACTIONDISCOUNTS_SHIPPINGOPTIONREPOSITORY_H
#define TRANSACTIONDISCOUNTS_SHIPPINGOPTIONREPOSITORY_H

#include <unordered_set>
#include <stdexcept>
#include "ShippingOption.h"
#include "../../common/IDataRepository.h"
#include "ShippingOptionHash.h"

/**
 * @brief Class representing a repository for shipping options
 * @details This class is a singleton
 */
class ShippingOptionRepository : public IDataRepository<ShippingOption> {
private:
    std::vector<ShippingOption> shippingOptions;
    ShippingOptionRepository();
    ~ShippingOptionRepository() override = default;

    // delete copy constructor and assignment operator
    ShippingOptionRepository(const ShippingOptionRepository&) = delete;
    ShippingOptionRepository& operator=(const ShippingOptionRepository&) = delete;
public:
    static ShippingOptionRepository &getInstance();

    // IDataRepository methods
    bool exists(const ShippingOption& shippingOption) override;
    void add(const ShippingOption& shippingOption) override;
    void remove(const ShippingOption& shippingOption) override;
    void update(const ShippingOption& shippingOption) override;
    std::vector<ShippingOption> getAll() override;
};


#endif //TRANSACTIONDISCOUNTS_SHIPPINGOPTIONREPOSITORY_H
