cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ocl_query)

add_executable(ocl_query source/platform.cpp)
#target_compile_features(ocl_query PUBLIC cxx_std_11)

# Intel SDK takes priority
if (NOT "$ENV{INTELOCLSDKROOT}" STREQUAL "")
    message(STATUS "Found Intel OpenCL SDK at '$ENV{INTELOCLSDKROOT}'")
    set(OpenCL_INCLUDE_DIRS "$ENV{INTELOCLSDKROOT}/include")
    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(OpenCL_LIBRARIES "$ENV{INTELOCLSDKROOT}/lib/x64/OpenCL.lib")
    else ()
        set(OpenCL_LIBRARIES "$ENV{INTELOCLSDKROOT}/lib/x86/OpenCL.lib")
    endif ()
else ()
	find_package(OpenCL REQUIRED)
endif ()
message(STATUS ${OpenCL_LIBRARIES})
#get_target_property(CXX_STANDARD_REQUIRED ocl_query CXX_STANDARD_REQUIRED) 
#get_target_property(CXX_STANDARD ocl_query CXX_STANDARD) 
#message(STATUS ${CXX_STANDARD})
#message(STATUS ${CXX_STANDARD_REQUIRED})
#message(STATUS ${CMAKE_CXX_STANDARD})
	
#find_package(OpenCL REQUIRED)
#get_cmake_property(_variableNames VARIABLES)
#list (SORT _variableNames)
#foreach (_variableName ${_variableNames})
#	message(STATUS "${_variableName}=${${_variableName}}")
#endforeach ()

include_directories(${OpenCL_INCLUDE_DIRS})
target_link_libraries(ocl_query ${OpenCL_LIBRARIES})


