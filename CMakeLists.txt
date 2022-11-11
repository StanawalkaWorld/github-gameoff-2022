cmake_minimum_required(VERSION 3.13.0)
project(main VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(raylib CONFIG REQUIRED)

include_directories(include)
add_executable(main "src/main.cpp" "src/SceneManager.cpp" "src/Scenes/GameScene.cpp" "src/GameObjects/GameObject.cpp")

add_custom_target(copy_assets
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
)
add_dependencies(main copy_assets)

if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug") 
	target_link_options(main PRIVATE "/SUBSYSTEM:WINDOWS" "/ENTRY:mainCRTStartup")
endif()

target_link_libraries(main raylib)