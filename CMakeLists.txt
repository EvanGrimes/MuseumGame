cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_CXX_FLAGS "-static-libgcc -static-libstdc++ -static")

add_compile_options(-Wall -Wextra -static-libgcc -static-libstdc++)
#add_compile_options(-Wpedantic -Wno-unknown-pragmas -Wno-type-limits)

project(MuseumGame)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(MuseumGame Launcher.cpp Game.cpp Game.h TitleScreen.cpp TitleScreen.h Assets.cpp Assets.h)

target_link_libraries(MuseumGame PRIVATE raylib winmm)
