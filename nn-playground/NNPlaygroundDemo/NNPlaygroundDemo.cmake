include(${CMAKE_CURRENT_LIST_DIR}/NNPlaygroundDemo.srcs.cmake)

add_executable(NNPlaygroundDemo ${SOURCES})

target_include_directories(NNPlaygroundDemo PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../NNPlayground/Include)
target_link_libraries(NNPlaygroundDemo PRIVATE NNPlayground)
