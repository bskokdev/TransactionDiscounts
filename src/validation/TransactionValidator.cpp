#include "TransactionValidator.h"
#include "common/Date.h"

bool TransactionValidator::areValidTypeAttributes(std::vector<std::string> attributes) {
    if(attributes.size() != 1) return false;
    if(!Date::isStringValidDate(attributes[0])) return false;

    return true;
}
