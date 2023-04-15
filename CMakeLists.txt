cmake_minimum_required(VERSION 3.25)
project(TransactionDiscounts VERSION 1.0)

# C++ standard
set(CMAKE_CXX_STANDARD 17)

# Including directories
include_directories(src)

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

# Adding source files from src directory
file(GLOB_RECURSE SOURCES "*.cpp")
list(FILTER SOURCES EXCLUDE REGEX "CMakeFiles")

# Adding executable
add_executable(TransactionDiscounts ${SOURCES})

# Adding Google Test library to the project
target_link_libraries(TransactionDiscounts gtest_main)

# Adding tests
enable_testing()

add_executable(
        test_example
        tests/test_example.cpp
)

target_link_libraries(
        test_example
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_example)
