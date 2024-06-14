cmake_minimum_required(VERSION 3.10)

project(NN-PLAYGROUND VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(NNPlayground/NNPlayground.cmake)

include(NNPlaygroundDemo/NNPlaygroundDemo.cmake)

if (BUILD_TESTING)
    include(NNPlaygroundTests/NNPlaygroundTests.cmake)
endif()