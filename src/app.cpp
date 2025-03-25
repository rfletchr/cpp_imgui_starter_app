#include "app.hpp"
#include "raylib.h"
#include "rlImGui.h"
#include <exception>
#include <iostream>

namespace App
{

void Exec(
    WindowSettings* settings,
    bool (*loop_func)(void),
    void (*init)(void),
    void (*shutdown)(void))
{

  static bool already_running = false;
  if (already_running)
  {
    std::cerr << "Critical: Exec should only be called once per process." << std::endl;
    std::terminate();
  }
  already_running = true;

  InitWindow(settings);

  if (init != nullptr)
  {
    init();
  }

  while (!WindowShouldClose())
  {
    if (loop_func())
    {
      break;
    }
  }

  if (shutdown != nullptr)
  {
    shutdown();
  }

  CloseWindow();
}

void InitWindow(WindowSettings* window_settings)
{

  WindowSettings settings;
  if (window_settings != nullptr)
  {
    settings = *window_settings;
  }

  SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
  ::InitWindow(settings.width, settings.height, settings.title.c_str());
  SetTargetFPS(settings.target_fps);
  rlImGuiSetup(settings.dark_theme);
}

bool WindowShouldClose() { return ::WindowShouldClose(); }

void BeginFrame()
{
  BeginDrawing();
  ClearBackground(DARKGRAY);

  rlImGuiBegin();
}

void EndFrame()
{
  rlImGuiEnd();
  EndDrawing();
}

void CloseWindow()
{
  rlImGuiShutdown();
  ::CloseWindow();
}

} // namespace App
