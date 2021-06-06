cmake_minimum_required(VERSION 3.10)
project(bst)

set (CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE BST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(bst_src ${BST_SRC})
target_include_directories(bst_src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(bst ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(bst bst_src)

file(GLOB_RECURSE BST_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
add_executable(tests ${BST_TEST_SRC})
target_link_libraries(tests bst_src)
target_link_libraries(tests ${CONAN_LIBS})
