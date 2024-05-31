include(${CMAKE_CURRENT_LIST_DIR}/LinkedList.srcs.cmake)

add_library(LinkedList STATIC ${SOURCES})
target_include_directories(LinkedList PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Include)