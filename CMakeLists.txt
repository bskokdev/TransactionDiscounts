cmake_minimum_required(VERSION 3.25)
project(TransactionDiscounts)

set(CMAKE_CXX_STANDARD 17)

add_executable(TransactionDiscounts main.cpp shipping/Provider.h shipping/PackageSize.h common/Date.h common/Date.cpp)
