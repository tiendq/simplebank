cmake_minimum_required(VERSION 3.12.0)
project(simplebank)

message(STATUS "Building for ${CMAKE_SYSTEM_NAME} system")

set(CMAKE_BUILD_TYPE Debug)
message(STATUS "${CMAKE_BUILD_TYPE} build configuration is detected")

set(MAIN_TARGET_NAME sb)
set(PROJECT_SOURCES ./src/main.cpp)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/build/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall")

add_executable(${MAIN_TARGET_NAME} ${PROJECT_SOURCES})

target_compile_features(${MAIN_TARGET_NAME} PRIVATE cxx_std_14)

# target_link_libraries(${MAIN_TARGET_NAME} PRIVATE mathman)
