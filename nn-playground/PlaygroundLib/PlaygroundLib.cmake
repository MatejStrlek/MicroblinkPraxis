include(${CMAKE_CURRENT_LIST_DIR}/PlaygroundLib.srcs.cmake)

add_library(PlaygroundLib STATIC ${SOURCES})
target_include_directories(PlaygroundLib PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Include)

target_link_libraries(PlaygroundLib PUBLIC spng::spng_static)