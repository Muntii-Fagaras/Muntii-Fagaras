cmake_minimum_required(VERSION 3.6)

project(MY_APP)

find_library(SDL2 SDL2)

add_library(main SHARED)


target_sources(main PRIVATE class/text.cpp class/font.cpp class/image.cpp class/load_file.cpp class/voice.cpp)

target_link_libraries(main SDL2)

