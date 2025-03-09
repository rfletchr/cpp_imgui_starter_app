# CPP ImGui Starter.
This project provides a simple jumping off point for writing ImGui apps with C++.
Window management is provided by Raylib, which compiles out of the box on most systems.

## Missing Dependencies
In cases where configuration fails due to missing dependencies Raylib provides a guide [here](https://github.com/raysan5/raylib/wiki/raylib-dependencies#platform-specific-dependency-notes).


### Building
The project is configured using CMAKE see `CMakePresets.json`

```
cmake --preset debug
cmake --build --preset debug
build/debug/cpp_app
```


