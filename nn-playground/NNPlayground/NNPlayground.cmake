include(${CMAKE_CURRENT_LIST_DIR}/NNPlayground.srcs.cmake)

add_library(NNPlayground STATIC ${SOURCES})
target_include_directories(NNPlayground PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Include)

target_link_libraries(NNPlayground PUBLIC spng::spng_static PUBLIC onnxruntime::onnxruntime)