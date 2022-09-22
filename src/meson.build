# projectの定義
project('gui-base', 'cpp',
        default_options: ['b_lto_threads=8','cpp_std=c++20','default_library=static','warning_level=3'])

# SDL2に依存する
sdl2_dep = dependency('sdl2')
sdl2_image_dep = dependency('sdl2_image')
sdl2_mixer_dep = dependency('sdl2_mixer')
sdl2_ttf_dep = dependency('sdl2_ttf')
libpng = dependency('libpng')
ogg=dependency('ogg')
vorbis=dependency('vorbis')
freetype2=dependency('freetype2')
# コンパイラによってコンパイルオプションを変更する
if meson.get_compiler('cpp').get_id() == 'gcc'
  extra_args = []
else
  extra_args = []
endif

# 実行ファイル
executable('main', 'main.cpp',
           win_subsystem: 'windows',
           dependencies: [sdl2_dep,sdl2_image_dep,sdl2_mixer_dep,sdl2_ttf_dep,libpng,ogg,vorbis,freetype2])

