cmake_minimum_required(VERSION 3.25)
project(TransactionDiscounts)

set(CMAKE_CXX_STANDARD 17)

add_executable(TransactionDiscounts main.cpp shipping/Provider.h shipping/PackageSize.h common/Date.h common/Date.cpp shipping/shippingOption/ShippingOption.h shipping/shippingOption/ShippingOption.cpp shipping/shippingOption/ShippingOptionRepository.cpp shipping/shippingOption/ShippingOptionRepository.h common/IDataRepository.h transaction/Transaction.cpp transaction/Transaction.h io/Reader.cpp io/Reader.h shipping/Provider.cpp shipping/PackageSize.cpp Application.cpp Application.h discount/DiscountService.cpp discount/DiscountService.h discount/MonthlyDiscountInfo.h discount/MonthlyDiscountInfo.cpp shipping/shippingOption/ShippingKey.cpp shipping/shippingOption/ShippingKey.h)
