# 貢献の方法

## このプロジェクトのビルド方法

### Linux編

Linuxでのビルド方法についてご紹介します。  
本項目では、Arch Linuxをベースに解説します。  

[Building a simple SDL2 app from scratch](https://mesonbuild.com/GuiTutorial.html)を参考に構築します。  
1. まずはビルドに必要な**meson,gcc,gdb**をインストールします。

```shell
$ sudo pacman -S meson gcc gdb
```

2. 任意のディレクトリへ移動して

```shell
$ git clone https://github.com/312k/
$ cd gui-base/src
```

として、本プロジェクトをクローンします。そして、クローンしたディレクトリへ移動します。

3. mesonはSDL2をWrapDBによって依存関係をダウンロードできるので、subprojectsにSDL2をダウンロードします。

```shell
$ mkdir subprojects
$ meson wrap install sdl2
```

4. ビルド先のディレクトリを準備します。

```shell
$ meson setup builddir
```

5. プロジェクトをコンパイルします。

```shell
$ meson compile -C builddir
```

### Windows 11編
