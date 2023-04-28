# ShippingTransaction Discounts Module

This C++ module allows you to apply discounts to transactions provided in the input file.
The discounts are applied in the order they are provided in the input file.
The discounts are applied to the transactions in the order they are provided in the input file.

## Prerequisites

* C++17 compatible compiler (g++ works)
* CMake

## Building the project

1. Clone the repository: `git clone https://github.com/skokcmd/TransactionDiscounts.git`
2. Open a terminal and navigate to the project root directory.
3. Create a build directory by running: `mkdir build` 
4. navigate to the build directory using: `cd build`.
5. Run CMake to generate the build files: `cmake ..` or `cmake -G "MinGW Makefiles" ..` (on Windows if using MinGW)
6. Build the project: `make` or `cmake --build .`
7. Run the tests: `ctest`

## Running the Project

After building the project, the `transaction_discounts` executable (or `transaction_discounts.exe` on Windows) will be created in the `build` directory.
Run the executable to start the program. 

`./transaction_discounts ../input.txt` (Unix)

`./transaction_discounts.exe ../input.txt` (Windows)

The executable is run in the build directory, so the input file must be provided as a relative path from the build directory.
