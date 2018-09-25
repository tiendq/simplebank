Simple Bank
===========
Simple bank management in modern C++ stack (STL, Boost, unit test, CMake).

## Features
* Unit testing with Boost.Test
* Build with CMake

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
cmake -H. -Bbuild
# H indicates source directory
# B indicates build directory
```

Tien Do (tiendq).
