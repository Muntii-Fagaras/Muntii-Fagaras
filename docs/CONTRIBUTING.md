# 貢献の方法

## このプロジェクトのビルド方法

### xmakeでプロジェクトのビルドをする方法

xmakeを使いビルドします。
[xmake](https://xmake.io/#/)にアクセスし、
```shell
xmake project -k vsxmake
```

### Linux編

Linuxでのビルド方法についてご紹介します。  
本項目では、Arch Linuxをベースに解説します。  

[Building a simple SDL2 app from scratch](https://mesonbuild.com/GuiTutorial.html)を参考に構築します。  

1. まずはビルドに必要な**meson,gcc,gdb**を

```shell
sudo pacman -S meson gcc gdb
```

インストールします。
2. 任意のディレクトリへ移動して

```shell
git clone https://github.com/312k/
cd gui-base/src
```

として、本プロジェクトをクローンします。そして、クローンしたディレクトリへ移動します。
3. mesonはSDL2をWrapDBによって依存関係をダウンロードできるので、

```shell
mkdir subprojects
meson wrap install sdl2
```

subprojectsにSDL2をダウンロードします。
4. ビルド先のディレクトリを

```shell
meson setup builddir
```

準備します。
5. プロジェクトをコンパイルします。

```shell
meson compile -C builddir
```

### Windows 11編

1. Mesonとninjaを

```shell
pip install meson ninja
```

pipからダウンロードします。
2. pipのパスを通していない場合通します。
3. mesonでVisual Studioのsln

```shell
meson setup --backend vs builddir
```

を生成します
4. 生成したファイルから、slnを起動する
