#include "PackageSize.h"

PackageSize getPackageSizeFromString(const std::string &packageSize) {
    if(packageSize == "S") {
        return PackageSize::S;
    } else if(packageSize == "M") {
        return PackageSize::M;
    } else if(packageSize == "L") {
        return PackageSize::L;
    } else {
        throw std::invalid_argument("Invalid package size");
    }
}

std::ostream& operator<<(std::ostream& os, const PackageSize& packageSize) {
    switch (packageSize) {
        case PackageSize::L:
            os << "L";
            break;
        case PackageSize::M:
            os << "M";
            break;
        case PackageSize::S:
            os << "S";
            break;
        default:
            os.setstate(std::ios_base::failbit);
    }
    return os;
}