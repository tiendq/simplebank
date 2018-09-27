Simple Bank
===========
Simple Bank is a command-line tool implemented with modern C++ stack (STL, Boost, unit test, CMake. LevelDB). This project was inspired by the project [Bank Management](https://github.com/smokindinesh/Mini-Project-in-C) implemented in C programming language.

## Features
* Build with CMake
* LevelDB database
* Logging with Boost.Log
* Unit testing with Boost.Test

## Prerequisites
* [Boost](https://www.boost.org/)
* [CMake](https://cmake.org/)

## Build
Configure the project build with the following command to create the build directory with the configuration.

```
mkdir build; cd build  # Create a build directory.
cmake ..               # Configure the project.
cmake --build .        # Build all default targets.
```

If you don't want `cd` :), you can also use below command to create `build` folder from project folder:

```
cmake -H. -Bbuild      # H for source directory, B for build directory
```

Tien Do (tiendq).
