#include "TransactionRepository.h"

TransactionRepository::TransactionRepository() {}

bool TransactionRepository::exists(const Transaction &item) {
    return this->transactions.count(item);
}

void TransactionRepository::add(const Transaction &item) {
    // we do not care about duplicates as set does not allow duplicates
    this->transactions.insert(item);
}

void TransactionRepository::remove(const Transaction &item) {
    // we do not care about non-existing items
    if(this->exists(item)) {
        this->transactions.erase(item);
    }
}

void TransactionRepository::update(const Transaction &item) {
    // we do not care about non-existing items
    if(this->exists(item)) {
        // remove the old item and add the new one
        this->transactions.erase(item);
        this->transactions.insert(item);
    }
}

std::vector<Transaction> TransactionRepository::getAll() {
    // copy the set to a vector and return
    std::vector<Transaction> result;
    std::copy(this->transactions.begin(), this->transactions.end(), std::back_inserter(result));
    return result;
}

