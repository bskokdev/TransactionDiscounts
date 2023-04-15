# Transaction Discounts Module

This C++ module allows you to apply discounts to transactions provided in the input file.
The discounts are applied in the order they are provided in the input file.
The discounts are applied to the transactions in the order they are provided in the input file.

## Prerequisites

* C++17 compatible compiler (g++ works)
* CMake

## Building the project

1. Open a terminal and navigate to the project root directory.
2. Create a build directory by running: `mkdir build` 
3. navigate to the build directory using: `cd build`.
4. Run CMake to generate the build files: `cmake ..` or `cmake -G "MinGW Makefiles" ..` (on Windows if using MinGW)
5. Build the project: `make` or `cmake --build .`
6. Run the tests: `make test` or `ctest`

## Running the Project

After building the project, the `transaction_discounts` executable (or `transaction_discounts.exe` on Windows) will be created in the `build` directory.
Run the executable to start the program. 

`./transaction_discounts` - on Unix systems

`./transaction_discounts.exe` - on Windows