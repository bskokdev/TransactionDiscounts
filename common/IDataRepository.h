#ifndef TRANSACTIONDISCOUNTS_IDATAREPOSITORY_H
#define TRANSACTIONDISCOUNTS_IDATAREPOSITORY_H


/**
 * @brief Generic interface for data repositories
 * @tparam T
 */
template<typename T>
class IDataRepository {
public:
    virtual ~IDataRepository() = default;

    /**
     * @brief Check if the repository contains the given item
     * @param item
     * @return true if the repository contains the given item
     */
    virtual bool exists(const T &item) = 0;

    /**
     * @brief Add the given item to the repository
     * @param item
     */
    virtual void add(const T &item) = 0;

    /**
     * @brief Remove the given item from the repository
     * @param item
     */
    virtual void remove(const T &item) = 0;

    /**
     * @brief Update the given item in the repository
     * @param item
     */

    virtual void update(const T &item) = 0;

    /**
     * @brief Get all items from the repository
     * @return std::vector<T>
     */
    virtual std::vector<T> getAll() = 0;
};


#endif //TRANSACTIONDISCOUNTS_IDATAREPOSITORY_H