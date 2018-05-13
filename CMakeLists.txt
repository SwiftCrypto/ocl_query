cmake_minimum_required(VERSION 3.1)
project(ocl_query)

add_executable(ocl_query source/platform.cpp)

find_package(OpenCL REQUIRED)
#message(${OpenCL_INCLUDE_DIRS})
include_directories(${OpenCL_INCLUDE_DIRS})
target_link_libraries(ocl_query ${OpenCL_LIBRARIES})


