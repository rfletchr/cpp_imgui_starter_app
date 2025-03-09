project(cpp_app)
cmake_minimum_required(VERSION 3.28.3)

set(SUPPRESS_VENDOR_WARNINGS ON CACHE BOOL "suppress vendor warnings?")

option(ENABLE_IM_NODES "enable ImNodes" ON)
option(ENABLE_IM_PLOT "enable ImPlot" ON)

add_subdirectory(vendor/raylib)
add_subdirectory(vendor/imgui)

# suppress warnings from vendor libraries. 
if(SUPPRESS_VENDOR_WARNINGS)
	target_compile_options(imgui PRIVATE -w)
	target_compile_options(raylib PRIVATE -w)
endif()

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib imgui)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
