debug: git_submodules build_debug
  build/debug/cpp_app

configure_debug:
  cmake --preset debug

build_debug: configure_debug
  cmake --build --preset debug


git_submodules:
  git submodule init
  git submodule update --recursive





