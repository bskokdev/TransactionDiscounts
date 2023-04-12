cmake_minimum_required(VERSION 3.25)
project(TransactionDiscounts)

set(CMAKE_CXX_STANDARD 17)

add_executable(TransactionDiscounts main.cpp shipping/Provider.h shipping/PackageSize.h common/Date.h common/Date.cpp shipping/shippingOption/ShippingOption.h shipping/shippingOption/ShippingOption.cpp shipping/shippingOption/ShippingOptionRepository.cpp shipping/shippingOption/ShippingOptionRepository.h common/IDataRepository.h shipping/shippingOption/ShippingOptionHash.cpp shipping/shippingOption/ShippingOptionHash.h transaction/Transaction.cpp transaction/Transaction.h transaction/TransactionHash.cpp transaction/TransactionHash.h io/Reader.cpp io/Reader.h io/IPrinter.h transaction/TransactionPrinter.cpp transaction/TransactionPrinter.h shipping/Provider.cpp shipping/PackageSize.cpp)
