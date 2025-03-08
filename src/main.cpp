#include "imnodes.h"
#include "raylib.h"
#include "imgui.h"
#include "rlImGui.h"

int main()
{
  SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
  InitWindow(1920, 1080, "CPP App");
  SetTargetFPS(60);
  rlImGuiSetup(true);
  ImNodes::CreateContext();

  bool showDemoWindow = true;

  ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(DARKGRAY);

    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, GetScreenHeight() * 0.45f, DARKGREEN);

    rlImGuiBegin();

    ImGui::DockSpaceOverViewport(0, NULL, ImGuiDockNodeFlags_PassthruCentralNode);

    ImGui::ShowDemoWindow(&showDemoWindow);

    rlImGuiEnd();
    EndDrawing();
  }
  ImNodes::DestroyContext();
  rlImGuiShutdown();

  CloseWindow();

  return 0;
}
