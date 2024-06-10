include(${CMAKE_CURRENT_LIST_DIR}/PlaygroundLibMain.srcs.cmake)

find_package(SPNG REQUIRED)

add_executable(PlaygroundLibMain ${SOURCES})
target_link_libraries(PlaygroundLibMain spng::spng_static PlaygroundLib)

enable_testing()