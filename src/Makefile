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

CFLAGS+= -std=c++20 #C++23でビルドする
CFLAGS+= -pipe #パイプ処理でコンパイル

# 実行中
WORKINGFLAGS:= -ftrapv #オーバーフロー
WORKINGFLAGS+= -fstack-protector-all #領域外アクセス


INC_DIR := -I library/SDL2/include #インクルードするディレクトリ
INC_DIR+= -L library/SDL2/lib 
INC_DIRC := -I library/SDL2_C/include #インクルードするディレクトリ
INC_DIRC+= -L library/SDL2_C/lib 

TARGET = gui-base #実行ファイルの名前

SRCS:=	stdafx.cpp
SRCS+=	class/*.cpp
SRCS+= main.cpp

DEFINE=SDL_MAIN_HANDLED 

LDFLAGS:= -Wl,-Bstatic -lSDL2main -lSDL2 -lSDL2_ttf  -lSDL2_mixer  \
-lSDL2_image -Wl,-Bdynamic -luser32 -lgdi32 -lwinmm -ldxguid 
LDFLAGS+=   -mwindows -lm -lpthread  -ole64  \
-lgdi32 -lsetupapi -lhid -lole32  -limm32 -lversion -lwinmm  \
-lshell32 -limagehlp -ldinput8 -ldxguid -ldxerr8 -luser32 -l oleaut32 -luuid \
-lrpcrt4 -static -static-libgcc -static-libstdc++ -lstdc++ \
-lwinpthread -lpthread

$(TARGET):
	g++-11 -o gui-base  -Wall  -Wextra  -Wcast-align  -Wdouble-promotion  -Wconversion  -Weffc++  -Wfloat-equal  -Wlogical-op  -Wmissing-declarations  -Wmissing-include-dirs  -Wold-style-cast  -Wswitch-default  -Wunsafe-loop-optimizations  -Wshadow  -std=c++20  -pipe  stdafx.cpp class/*.cpp main.cpp -lSDL2main -lSDL2 -lSDL2_ttf  -lSDL2_mixer -lSDL2_image   -DSDL_MAIN_HANDLED
	
C_drive:
	windres icon.rc -O coff -o icon.res	
	$(CC_gcc) -o gui-base  $(CFLAGS) $(SRCS) $(INC_DIRC) $(LDFLAGS) $(WORKINGFLAGS) -D$(DEFINE) -D _GLIBCXX_DEBUG icon.res
	mv le64.exe gui-base.exe > nul
C_drive_clang:
	$(CC_clang) -o gui-base  $(CFLAGS) $(SRCS) $(INC_DIRC) $(LDFLAGS) $(WORKINGFLAGS) -D$(DEFINE) -D _GLIBCXX_DEBUG
	move le64.exe gui-base.exe > nul

C_drive_Clion:
	windres icon.rc -O coff -o icon.res
	$(CC_gcc) -o gui-base  $(CFLAGS) $(SRCS) $(INC_DIRC) $(LDFLAGS) $(WORKINGFLAGS) -D$(DEFINE) -D _GLIBCXX_DEBUG icon.res
	move le64.exe gui-base.exe > nul
	.\gui-base.exe
all:
	C_drive_Clion
clean:
	del gui-base.exe > nul
