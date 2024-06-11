include(${CMAKE_CURRENT_LIST_DIR}/IntroLib.srcs.cmake)

add_library(IntroLib STATIC ${SOURCES})
target_include_directories(IntroLib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Include)