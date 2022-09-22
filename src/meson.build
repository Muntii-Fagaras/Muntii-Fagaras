# projectの定義
project('gui-base', 'cpp',
        default_options: ['b_lto_threads=8','cpp_std=c++20','default_library=static','warning_level=3'])

# SDL2に依存する
sdl2_dep = dependency('sdl2')

# コンパイラによってコンパイルオプションを変更する
if meson.get_compiler('cpp').get_id() == 'gcc'
  extra_args = []
else
  extra_args = []
endif

# 実行ファイル
executable('main', 'main.cpp',
           win_subsystem: 'windows',
           dependencies: sdl2_dep)

