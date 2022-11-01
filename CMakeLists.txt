cmake_minimum_required(VERSION 3.13.0)
project(main VERSION 0.0.1)

find_package(raylib CONFIG REQUIRED)

include_directories(include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(main src/main.cpp)

if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug") 
	target_link_options(main PRIVATE "/SUBSYSTEM:WINDOWS" "/ENTRY:mainCRTStartup")
endif()

target_link_libraries(main raylib)