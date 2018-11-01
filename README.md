Simple Bank
===========
Simple Bank is a command-line tool implemented with modern C++ stack (STL, Boost, unit testing, CMake LevelDB). This project was inspired by the project [Bank Management](https://github.com/smokindinesh/Mini-Project-in-C) implemented in C programming language.

## Features
* Build with CMake
* LevelDB database
* Logging with Boost.Log
* Unit testing with Boost.Test

## Bank Functions
* Account management (open, close, list, view)
* Deposit/widthraw cash to/from account
* Transfer fund between accounts
* Transaction log
* Changable interest rate, automatically calculate compound interest

Run program with `--help` for list of available commands and options.

## Prerequisites
* [Boost](https://www.boost.org/)
* [CMake](https://cmake.org/)

## Build
Configure the project build with the following command to create the build directory with the configuration.

```
git clone git@github.com:tiendq/simplebank.git
git submodule update --init

mkdir build; cd build  # Create a build directory.
cmake ..               # Configure the project.
cmake --build .        # Build all default targets.
```

If you don't want `cd` :), you can also use below command to create `build` folder from project folder:

```
cmake -H. -Bbuild      # H for source directory, B for build directory
```

Tien Do (tiendq).
