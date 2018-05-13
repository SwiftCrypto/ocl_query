cmake_minimum_required(VERSION 3.1)
project(ocl_query)

add_executable(ocl_query source/platform.cpp)

# Intel SDK takes priority
if (NOT "$ENV{INTELOCLSDKROOT}" STREQUAL "")
	if (${CMAKE_VS_PLATFORM_NAME} STREQUAL "x64")
		set(OpenCL_LIBRARIES "$ENV{INTELOCLSDKROOT}/lib/x64/OpenCL.lib")
	elseif (${CMAKE_VS_PLATFORM_NAME} STREQUAL "Win32")
		set(OpenCL_LIBRARIES "$ENV{INTELOCLSDKROOT}/lib/x86/OpenCL.lib")
	endif ()

else ()
	find_package(OpenCL REQUIRED)
endif ()
	message(${OpenCL_LIBRARIES})
	
	#get_cmake_property(_variableNames VARIABLES)
	#list (SORT _variableNames)
	#foreach (_variableName ${_variableNames})
	#	message(STATUS "${_variableName}=${${_variableName}}")
	#endforeach ()

include_directories(${OpenCL_INCLUDE_DIRS})
target_link_libraries(ocl_query ${OpenCL_LIBRARIES})
message(${OpenCL_LIBRARIES})


