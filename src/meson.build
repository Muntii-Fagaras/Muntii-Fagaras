# projectの定義
project('gui-base', 'cpp',
        default_options: ['b_lto_threads=8','cpp_std=c++20','warning_level=3'])

# SDL2に依存する
sdl2_dep = dependency('sdl2',disabler: true)
sdl2_image_dep = dependency('sdl2_image',disabler: true)
sdl2_mixer_dep = dependency('sdl2_mixer',disabler: true)
sdl2_ttf_dep = dependency('sdl2_ttf',disabler: true)
libpng = dependency('libpng',disabler: true)
ogg=dependency('ogg',disabler: true)
zlib=dependency('zlib',disabler: true)
vorbis=dependency('vorbis',disabler: true)
freetype2=dependency('freetype2',disabler: true)
# コンパイラによってコンパイルオプションを変更する
if meson.get_compiler('cpp').get_id() == 'gcc'
  extra_args = ['-lSDL2_ttf','lSDL2main','-lSDL2']
else
  extra_args = ['/U USING_GENERATED_CONFIG_H']
endif

# 実行ファイル
executable('main', 'main.cpp',
           win_subsystem: 'windows',
           dependencies: [sdl2_dep,sdl2_image_dep,sdl2_mixer_dep,sdl2_ttf_dep,libpng,ogg,vorbis,freetype2,zlib])

