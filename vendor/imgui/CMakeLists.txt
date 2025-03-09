file(GLOB IMGUI_SRC imgui/*.cpp)
file(GLOB IMNODES_SRC imnodes/*.cpp)

add_library(imgui STATIC
	${IMGUI_SRC}
	${IMNODES_SRC}
	rlImGui/rlImGui.cpp
)
target_include_directories(imgui PUBLIC imgui imnodes rlImGui)
target_link_libraries(imgui PUBLIC raylib)










