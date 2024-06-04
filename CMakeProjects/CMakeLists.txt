cmake_minimum_required(VERSION 3.10)

project(LinkedListProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(IntroLib/IntroLib.cmake)

if (BUILD_TESTING)
    include(IntroLibTest/IntroLibTest.cmake)
endif()