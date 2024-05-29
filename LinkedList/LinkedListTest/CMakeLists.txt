include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(LinkedListTests ${CMAKE_CURRENT_SOURCE_DIR}/LinkedListTest.cpp)
target_link_libraries(LinkedListTests gtest_main LinkedList)

enable_testing()

add_test(NAME LinkedListTests COMMAND LinkedListTests)