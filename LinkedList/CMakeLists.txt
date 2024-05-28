cmake_minimum_required(VERSION 3.10)

project(LinkedListProject VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the LinkedList library
add_subdirectory(LinkedList)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
# Prevent GoogleTest from overriding our compiler/linker options
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(LinkedListTests LinkedListTest/LinkedListTest.cpp)
target_link_libraries(LinkedListTests gtest_main LinkedList)

# Include GoogleTest and LinkedList directories
target_include_directories(LinkedListTests PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/LinkedList
  ${googletest_SOURCE_DIR}/include
  ${googletest_BINARY_DIR}
)

enable_testing()

add_test(NAME LinkedListTests COMMAND LinkedListTests)
