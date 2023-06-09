#ifndef TRANSACTIONDISCOUNTS_PROVIDER_H
#define TRANSACTIONDISCOUNTS_PROVIDER_H

#include <ostream>

/**
 * @brief Enum for provider types
 */
enum class Provider {
    LP,
    MR,
    EnumSize // for iterating over enum
};

/**
 * @brief Converts string to Provider
 * @param provider string to be converted
 * @return Provider
 */
Provider getProviderFromString(const std::string &provider);

/**
 * @brief Operator for printing provider to ostream
 * @param os output stream
 * @param provider provider to be printed
 * @return std::ostream reference
 */
std::ostream &operator<<(std::ostream &os, const Provider &provider);

#endif //TRANSACTIONDISCOUNTS_PROVIDER_H
