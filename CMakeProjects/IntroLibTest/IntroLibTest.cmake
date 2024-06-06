include(${CMAKE_CURRENT_LIST_DIR}/IntroLibTest.srcs.cmake)

add_executable(IntroLibTests ${TEST_SOURCES})
target_link_libraries(IntroLibTests gtest_main IntroLib)

enable_testing()
include( GoogleTest )
gtest_discover_tests( IntroLibTests )