#pragma once
#include <string>
#include <utility>

namespace App
{

struct WindowSettings
{
  int         width = 1920;
  int         height = 1080;
  std::string title = "New Window";
  bool        dark_theme = true;
  int         target_fps = 60;
};

void Exec(
    WindowSettings* settings,
    bool (*loop_func)(void),
    void (*init)(void),
    void (*shutdown)(void));

void InitWindow(WindowSettings* settings = nullptr);
bool WindowShouldClose();
void BeginFrame();
void EndFrame();
void CloseWindow();
} // namespace App
