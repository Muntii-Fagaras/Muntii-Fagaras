add_rules("mode.debug", "mode.release")

add_requires("libsdl")

target("main")
    set_kind("binary")
    add_files("main.cpp")
    add_packages("libsdl")
    add_links("sdl2")