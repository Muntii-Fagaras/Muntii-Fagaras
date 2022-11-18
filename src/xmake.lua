add_rules("mode.debug", "mode.release")

add_requires("libsdl","libsdl_image","libsdl_mixer","libsdl_ttf")

target("main")
    set_kind("binary")
    add_files("main.cpp","stdafx.cpp","class/*.cpp")
    add_packages("libsdl","libsdl_image","libsdl_mixer","libsdl_ttf")
    add_links("SDL2")
    set_pcxxheader("stdafx.h")
    set_languages("c17", "cxx20")
