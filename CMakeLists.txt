# CMake version
cmake_minimum_required(VERSION 3.25)

# Project name and version
project(TransactionDiscounts VERSION 1.0)

# C++ standard
set(CMAKE_CXX_STANDARD 17)

# Including directories
include_directories(src/common src/discount src/io src/shipping src/shipping/shippingOption src/transaction src/validation)

# Fetching Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Adding source files
file(GLOB_RECURSE SOURCES "*.cpp")
list(FILTER SOURCES EXCLUDE REGEX "CMakeFiles")

enable_testing()

# Adding executable
add_executable(TransactionDiscounts ${SOURCES})

# Adding Google Test library
target_link_libraries(TransactionDiscounts gtest_main)
#add_test(NAME tests/test_example COMMAND TransactionDiscounts)
