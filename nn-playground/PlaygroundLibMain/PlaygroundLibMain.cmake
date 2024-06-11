include(${CMAKE_CURRENT_LIST_DIR}/PlaygroundLibMain.srcs.cmake)

find_package(SPNG REQUIRED)

add_executable(PlaygroundLibMain ${SOURCES})

target_link_libraries(PlaygroundLibMain PRIVATE PlaygroundLib)

enable_testing()