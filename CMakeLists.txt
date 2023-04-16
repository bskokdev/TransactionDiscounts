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

# Adding source files from src directory, excluding main.cpp and tests
file(GLOB_RECURSE SOURCES "src/*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

# Removing CMakeFiles from the list of source files
list(FILTER SOURCES EXCLUDE REGEX "CMakeFiles")

# Creating a library from the source files
add_library(transaction_lib STATIC ${SOURCES})

# Adding executable of the project
add_executable(TransactionDiscounts src/main.cpp)

# Linking the library to the main executable
target_link_libraries(TransactionDiscounts transaction_lib gtest_main)

# Adding tests
enable_testing()

# Detecting test files in the tests directory
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")

# Include the GoogleTest module
include(GoogleTest)

# Adding test executables and linking the library and Google Test
foreach(test_source ${TEST_SOURCES})
    get_filename_component(test_name ${test_source} NAME_WE)
    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name} transaction_lib GTest::gtest_main)
    gtest_discover_tests(${test_name})
endforeach()
