#ifndef TRANSACTIONDISCOUNTS_IDATAREPOSITORY_H
#define TRANSACTIONDISCOUNTS_IDATAREPOSITORY_H


template<typename T>
class IDataRepository {
public:
    virtual ~IDataRepository() = default;

    virtual bool exists(const T& item) = 0;
    virtual void add(const T& item) = 0;
    virtual void remove(const T& item) = 0;
    virtual void update(const T& item) = 0;
};


#endif //TRANSACTIONDISCOUNTS_IDATAREPOSITORY_H