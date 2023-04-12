#include "Provider.h"

std::ostream& operator<<(std::ostream& os, const Provider& provider) {
    switch (provider) {
        case Provider::LP:
            os << "LP";
            break;
        case Provider::MR:
            os << "MR";
            break;
        default:
            os.setstate(std::ios_base::failbit);
    }
    return os;
}