#include "TransactionValidator.h"

bool TransactionValidator::areValid(std::vector<std::string> attributes) {
    if(attributes.size() != 3) return false;
    if(!Date::isStringValidDate(attributes[0])) return false;
    if(!isPackageSizeStringValid(attributes[1])) return false;
    if(!isProviderStringValid(attributes[2])) return false;

    return true;
}

bool TransactionValidator::isProviderStringValid(const std::string &provider) {
    try {
        getProviderFromString(provider);
        return true;
    } catch (const std::invalid_argument &) {
        return false;
    }
}

bool TransactionValidator::isPackageSizeStringValid(const std::string &packageSize) {
    try {
        getPackageSizeFromString(packageSize);
        return true;
    } catch (const std::invalid_argument &) {
        return false;
    }
}
