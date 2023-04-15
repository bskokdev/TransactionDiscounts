cmake_minimum_required(VERSION 3.25)
project(TransactionDiscounts)

set(CMAKE_CXX_STANDARD 17)

include_directories(common discount io shipping shipping/shippingOption transaction validation)

file(GLOB_RECURSE SOURCES "*.cpp")
list(FILTER SOURCES EXCLUDE REGEX "CMakeFiles")

add_executable(TransactionDiscounts ${SOURCES})
