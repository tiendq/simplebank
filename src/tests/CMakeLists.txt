cmake_minimum_required(VERSION 3.12)
project(tests)

set(MAIN_TARGET_NAME tests)
set(PROJECT_SOURCES
  ../Account.cpp
  ../Bank.cpp
  ../Database.cpp
  ../Commander.cpp
  ../SQL.cpp
  ../Transaction.cpp
  main.cpp
  Account.cpp
  Bank.cpp
  Database.cpp
  Commander.cpp
  SQL.cpp
  Transaction.cpp
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wcast-qual -Wconversion -Weffc++ -Wold-style-cast -Wpedantic -Wshadow-all")

add_executable(${MAIN_TARGET_NAME} ${PROJECT_SOURCES})

target_compile_features(${MAIN_TARGET_NAME} PRIVATE cxx_std_14)
target_compile_definitions(${MAIN_TARGET_NAME} PRIVATE "BOOST_TEST_DYN_LINK=1")
target_include_directories(${MAIN_TARGET_NAME} PRIVATE "..")
target_link_libraries(${MAIN_TARGET_NAME}
  PRIVATE boost_program_options
  PRIVATE boost_unit_test_framework
)
