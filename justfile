debug: build_debug
  build/debug/cpp_app

configure_debug:
  cmake --preset debug

build_debug: configure_debug
  cmake --build --preset debug





