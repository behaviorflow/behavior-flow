cmake_minimum_required(VERSION 3.16.3)
project(behavior_flow)

set(CMAKE_CXX_STANDARD 11)
set(BF_LIBRARY ${PROJECT_NAME})

add_library(${BF_LIBRARY} src/behavior_flow_graph.cpp)
target_include_directories(${BF_LIBRARY} PUBLIC include)

# Option to build unit tests, default ON
option(BUILD_TESTING "Build the unit tests" ON)

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()