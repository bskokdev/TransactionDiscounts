#ifndef TRANSACTIONDISCOUNTS_PACKAGESIZE_H
#define TRANSACTIONDISCOUNTS_PACKAGESIZE_H

#include <ostream>

/**
 * @brief Enum for package sizes
 */
enum class PackageSize {
    S,
    M,
    L,
    EnumSize // size of enum for iteration purposes
};

/**
 * @brief Converts string to PackageSize
 * @param packageSize string to be converted
 * @return PackageSize
 */
PackageSize getPackageSizeFromString(const std::string &packageSize);

/**
 * @brief Operator for printing package size to ostream
 * @param os output stream
 * @param packageSize PackageSize to be printed
 * @return std::ostream reference
 */
std::ostream &operator<<(std::ostream &os, const PackageSize &packageSize);

#endif //TRANSACTIONDISCOUNTS_PACKAGESIZE_H
