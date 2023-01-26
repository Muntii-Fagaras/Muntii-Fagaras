MAKEFLAGS=-j8
MAKEFLAGS+= --no-builtin-rules
.PHONY: all gui-base clean

.SUFFIXES:	#サフィックス無効
CC_gcc:=g++ #g++でビルドする
CC_clang:=clang++ #clang++でビルドする

CFLAGS:= -ggdb3 #デバッグ情報最大化(GDB用)
CFLAGS:= -Wall #エラーを全部出す
CFLAGS+= -Wextra #追加の警告オプション
CFLAGS+= -Wcast-align #ポインタのキャスト
CFLAGS+= -Wdouble-promotion #floatからdouble
CFLAGS+= -Wconversion #暗黙的方変換
CFLAGS+= -Weffc++ #Effective C++
CFLAGS+= -Wfloat-equal #浮動小数点の比較
CFLAGS+= -Wlogical-op #正しい論理演算子
CFLAGS+= -Wmissing-declarations #前にないグローバル関数
CFLAGS+= -Wmissing-include-dirs #存在しないinclude
CFLAGS+= -Wold-style-cast #C風のキャストの防止
CFLAGS+= -Wswitch-default #default文の矯正
CFLAGS+= -Wunsafe-loop-optimizations #ループのオーバーフロー
CFLAGS+= -Wshadow #シャドウイング

CFLAGS+= -std=c++17 #C++17でビルドする
CFLAGS+= -pipe #パイプ処理でコンパイル

# 実行中
WORKINGFLAGS:= -ftrapv #オーバーフロー
WORKINGFLAGS+= -fstack-protector-all #領域外アクセス


INC_DIR := -I library/SDL2/include #インクルードするディレクトリ
INC_DIR+= -L library/SDL2/lib 
INC_DIRC := -I library/SDL2_C/include #インクルードするディレクトリ
INC_DIRC+= -L library/SDL2_C/lib 

TARGET = Muntii-Fagaras #実行ファイルの名前

SRCS:=	stdafx.cpp
SRCS+=	class/*.cpp
SRCS+=  main.cpp
SRCS+=  class/Control/*.cpp
SRCS+=  class/Tile/*.cpp

DEFINE=SDL_MAIN_HANDLED 

LDFLAGS:= -lSDL2main -lSDL2 -lSDL2_ttf  -lSDL2_mixer -lSDL2_image -mwindows

$(TARGET):
	g++-11 -o Muntii-Fagaras -std=c++17  -pipe  stdafx.cpp class/*.cpp class/Control/*.cpp  class/Tile/*.cpp main.cpp -lSDL2main -lSDL2 -lSDL2_ttf  -lSDL2_mixer -lSDL2_image   -DSDL_MAIN_HANDLED
	
C_drive:
	windres icon.rc -O coff -o icon.res	
	$(CC_gcc) -o Muntii-Fagaras  $(CFLAGS) $(SRCS) $(INC_DIRC) $(LDFLAGS) $(WORKINGFLAGS) -D$(DEFINE) -D _GLIBCXX_DEBUG icon.res