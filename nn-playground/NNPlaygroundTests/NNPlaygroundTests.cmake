include(${CMAKE_CURRENT_LIST_DIR}/NNPlaygroundTests.srcs.cmake)

find_package(SPNG REQUIRED)
find_package(GTest REQUIRED)

add_executable(NNPlaygroundTests ${SOURCES})

target_link_libraries(NNPlaygroundTests PRIVATE NNPlayground PRIVATE GTest::gtest_main)

enable_testing()
include( GoogleTest )
gtest_discover_tests(NNPlaygroundTests)