#ifndef TRANSACTIONDISCOUNTS_SHIPPINGOPTION_H
#define TRANSACTIONDISCOUNTS_SHIPPINGOPTION_H


#include "../PackageSize.h"
#include "../Provider.h"

#include <functional>
#include <ostream>


/**
 * @brief Class representing a shipping option
 */
class ShippingOption {
private:
    Provider provider;
    PackageSize size;
    double price;
    bool empty;
public:
    /**
     * @brief Default constructor for ShippingOption
     */
    ShippingOption();
    /**
     * @brief Constructor for ShippingOption
     * @param provider The provider of the shipping option
     * @param size The size of the shipping option
     * @param price The price of the shipping option
     */
    ShippingOption(Provider provider, PackageSize size, double price);

    /**
     * @brief Checks if the shipping option is empty
     * @return true if the shipping option is empty
     */
    bool isEmpty() const;

    // getters and setters
    Provider getProvider() const;

    void setProvider(Provider provider);

    PackageSize getSize() const;

    void setSize(PackageSize size);

    double getPrice() const;

    void setPrice(double price);

    // operators
    // == operator for ShippingOption
    bool operator==(const ShippingOption &other) const;

    // < operator for ShippingOption
    bool operator<(const ShippingOption &other) const;

    /**
     * @brief Overload of the << operator for ShippingOption
     * @param os The output stream
     * @param option The ShippingOption to be printed
     * @return reference to the output stream
     */
    friend std::ostream &operator<<(std::ostream &os, const ShippingOption &option);
};

#endif //TRANSACTIONDISCOUNTS_SHIPPINGOPTION_H
