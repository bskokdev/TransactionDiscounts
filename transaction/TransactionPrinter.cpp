#include "TransactionPrinter.h"

TransactionPrinter &TransactionPrinter::getInstance() {
    static TransactionPrinter instance;
    return instance;
}

void TransactionPrinter::print(const Transaction &transaction) {
    std::cout << transaction << std::endl;
}

void TransactionPrinter::print(const std::vector<Transaction> &transactions) {
    for (const auto& transaction : transactions) {
        print(transaction);
    }
}

