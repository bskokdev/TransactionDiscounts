#ifndef TRANSACTIONDISCOUNTS_IPRINTER_H
#define TRANSACTIONDISCOUNTS_IPRINTER_H

#include <vector>

/**
 * @brief Generic interface for printing objects
 * @tparam T
 */
template <typename T>
class IPrinter {
public:
    /**
     * @brief Print the given object
     * @param object
     */
    virtual void print(const T &object) = 0;

    /**
     * @brief Print the given vector of objects
     * @param objects
     */
    virtual void print(const std::vector<T> &objects) = 0;
};


#endif //TRANSACTIONDISCOUNTS_IPRINTER_H
