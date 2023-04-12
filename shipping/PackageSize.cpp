#include "PackageSize.h"

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