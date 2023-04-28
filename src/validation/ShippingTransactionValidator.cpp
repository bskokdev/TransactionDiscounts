#include "ShippingTransactionValidator.h"

bool ShippingTransactionValidator::areValidTypeAttributes(std::vector<std::string> attributes) {
    if(attributes.size() != 3) return false;
    if(!Date::isStringValidDate(attributes[0])) return false;
    if(!isEnumStringValid<PackageSize>(attributes[1])) return false;
    if(!isEnumStringValid<Provider>(attributes[2])) return false;

    return true;
}

template <typename T>
bool ShippingTransactionValidator::isEnumStringValid(const std::string &enumString) {
    if (enumString.empty()) return false;
    // We use std::is_same to check if T is Provider or PackageSize
    try {
        if(std::is_same<T, Provider>::value) {
            getProviderFromString(enumString);
        } else if(std::is_same<T, PackageSize>::value) {
            getPackageSizeFromString(enumString);
        }
        // No exception was thrown, so the string is valid
        return true;
    } catch (const std::invalid_argument &) {
        return false;
    }
}
