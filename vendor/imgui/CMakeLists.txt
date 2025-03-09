file(GLOB IMGUI_SRC imgui/*.cpp)
set(IMGUI_INCLUDES imgui rlImGui)

if(ENABLE_IM_NODES)
	list(APPEND IMGUI_SRC imnodes/imnodes.cpp)
	list(APPEND IMGUI_INCLUDES imnodes)
endif()

if(ENABLE_IM_PLOT)
	list(APPEND IMGUI_SRC implot/implot.cpp  implot/implot_demo.cpp  implot/implot_items.cpp)
	list(APPEND IMGUI_INCLUDES implot)
endif()


add_library(imgui STATIC
	${IMGUI_SRC}
	rlImGui/rlImGui.cpp
)
target_include_directories(imgui PUBLIC ${IMGUI_INCLUDES})
target_link_libraries(imgui PUBLIC raylib)










