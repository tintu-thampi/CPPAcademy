cmake_minimum_required(VERSION 3.10)
project(rational)

set (CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE RATIONAL_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(rational_src ${RATIONAL_SRC})
target_include_directories(rational_src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(rational ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(rational rational_src)

file(GLOB_RECURSE RATIONAL_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
add_executable(tests ${RATIONAL_TEST_SRC})
target_link_libraries(tests rational_src)
target_link_libraries(tests ${CONAN_LIBS})
