cmake_minimum_required(VERSION 3.12)
project(simplebank)

message(STATUS "Building for ${CMAKE_SYSTEM_NAME} system")

set(CMAKE_BUILD_TYPE Debug)
message(STATUS "${CMAKE_BUILD_TYPE} build configuration is detected")

set(MAIN_TARGET_NAME sb)
file(GLOB SOURCE_CPP LIST_DIRECTORIES false CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB SOURCE_HEADER LIST_DIRECTORIES false CONFIGURE_DEPENDS "src/*.h")

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR "${CMAKE_SOURCE_DIR}/build/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wcast-qual -Wconversion -Weffc++ -Wold-style-cast -Wpedantic -Wshadow-all")

add_subdirectory(libs/fmt)
add_subdirectory(libs/SQLiteCpp)
add_subdirectory(src/tests)
add_executable(${MAIN_TARGET_NAME} ${SOURCE_CPP} ${SOURCE_HEADER})

find_package(Boost REQUIRED program_options)
target_include_directories(${MAIN_TARGET_NAME} PRIVATE ${Boost_INCLUDE_DIRS})

target_compile_features(${MAIN_TARGET_NAME} PRIVATE cxx_std_14)

target_link_libraries(${MAIN_TARGET_NAME}
  PRIVATE Boost::program_options
  PRIVATE SQLiteCpp
  PRIVATE sqlite3
)
