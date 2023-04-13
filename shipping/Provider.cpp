#include "Provider.h"

Provider getProviderFromString(const std::string &provider) {
    if(provider == "LP") {
        return Provider::LP;
    } else if(provider == "MR") {
        return Provider::MR;
    } else {
        throw std::invalid_argument("Invalid provider");
    }
}

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