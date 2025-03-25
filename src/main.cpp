#include "imnodes.h"
#include "imgui.h"
#include "implot.h"
#include "app.hpp"

void init()
{
  ImNodes::CreateContext();
  ImPlot::CreateContext();
  ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
}

bool loop()
{
  static bool show_demo_window = true;
  static bool should_close = false;

  App::BeginFrame();

  ImGui::DockSpaceOverViewport(0, NULL, ImGuiDockNodeFlags_PassthruCentralNode);

  ImGui::ShowDemoWindow(&show_demo_window);
  ImPlot::ShowDemoWindow();

  App::EndFrame();

  return should_close;
};

void shutdown()
{
  ImNodes::DestroyContext();
  ImPlot::DestroyContext();
}

int main()
{

  App::WindowSettings settings = {.width = 640, .height = 480};
  App::Exec(&settings, loop, init, shutdown);

  return 0;
}
