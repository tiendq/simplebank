cmake_minimum_required(VERSION 3.12)
project(tests)

set(MAIN_TARGET_NAME tests)

file(GLOB SOURCE_TEST LIST_DIRECTORIES false CONFIGURE_DEPENDS "*.cpp")
file(GLOB SOURCE_CPP LIST_DIRECTORIES false CONFIGURE_DEPENDS "../*.cpp")
file(GLOB SOURCE_HEADER LIST_DIRECTORIES false CONFIGURE_DEPENDS "../*.h")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wcast-qual -Wconversion -Weffc++ -Wold-style-cast -Wpedantic -Wshadow-all")

add_executable(${MAIN_TARGET_NAME} ${SOURCE_TEST} ${SOURCE_CPP} ${SOURCE_HEADER})

find_package(Boost REQUIRED program_options unit_test_framework)
target_include_directories(${MAIN_TARGET_NAME} PRIVATE ${Boost_INCLUDE_DIRS})

target_compile_features(${MAIN_TARGET_NAME} PRIVATE cxx_std_14)
target_compile_definitions(${MAIN_TARGET_NAME} PRIVATE "BOOST_UNIT_TEST=1")
target_compile_definitions(${MAIN_TARGET_NAME} PRIVATE "BOOST_TEST_DYN_LINK=1")
target_include_directories(${MAIN_TARGET_NAME} PRIVATE "..")
target_link_libraries(${MAIN_TARGET_NAME}
  PRIVATE Boost::program_options
  PRIVATE Boost::unit_test_framework
)
