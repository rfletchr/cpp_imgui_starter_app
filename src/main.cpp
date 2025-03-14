#include "imnodes.h"
#include "raylib.h"
#include "imgui.h"
#include "rlImGui.h"
#include "implot.h"

int main()
{

  SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
  InitWindow(1920, 1080, "CPP App");
  SetTargetFPS(60);
  rlImGuiSetup(true);
  ImNodes::CreateContext();
  ImPlot::CreateContext();

  bool showDemoWindow = true;

  ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(DARKGRAY);

    rlImGuiBegin();

    ImGui::DockSpaceOverViewport(0, NULL, ImGuiDockNodeFlags_PassthruCentralNode);

    ImGui::ShowDemoWindow(&showDemoWindow);
    ImPlot::ShowDemoWindow();

    rlImGuiEnd();
    EndDrawing();
  }
  ImNodes::DestroyContext();
  ImPlot::DestroyContext();
  rlImGuiShutdown();

  CloseWindow();

  return 0;
}
