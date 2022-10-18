MAKEFLAGS=-j8
MAKEFLAGS+= --no-builtin-rules

.SUFFIXES:	#サフィックス無効
CC:=g++ #g++でビルドする

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

CFLAGS+= -std=c++20 #C++23でビルドする
CFLAGS+= -pipe #パイプ処理でコンパイル

INC_DIR := -isystem SDL2/include/SDL2 #インクルードするディレクトリ
#INC_DIR+= SDL2/bin/*.dll

TARGET = gui-base #実行ファイルの名前

SRCS:=	stdafx.cpp
SRCS+=	class/*.cpp
SRCS+= main.cpp

DEFINE=SDL_MAIN_HANDLED 

LDFLAGS:= -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf  -lSDL2_mixer
LDFLAGS+= -mwindows
#LDFLAGS+= -L SDL2/lib -lSDL2main  -L SDL2/bin/SDL2.dll 
$(TARGET):
	$(CC) -o $(TARGET) $(CFLAGS) $(SRCS) $(INC_DIR) $(LDFLAGS) -D$(DEFINE)
