project(cpp_app)
cmake_minimum_required(VERSION 3.30)

add_subdirectory(vendor/raylib)
add_subdirectory(vendor/imgui)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib imgui)


