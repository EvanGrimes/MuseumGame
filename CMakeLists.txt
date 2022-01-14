cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_CXX_FLAGS "-static-libgcc -static-libstdc++ -static")

add_compile_options(-Wall -Wextra -static-libgcc -static-libstdc++)

project(MuseumGame)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(MuseumGame Launcher.cpp Game.cpp Game.h TitleScreen.cpp TitleScreen.h Assets.cpp Assets.h GameState.cpp GameState.h Map.h Map.cpp MapReader.cpp MapReader.h BattleManager.cpp BattleManager.h Battles/MonaBattle.cpp Battles/MonaBattle.h Battles/StarryBattle.cpp Battles/StarryBattle.h Battles/ScreamBattle.cpp Battles/ScreamBattle.h Battles/PipeBattle.cpp Battles/PipeBattle.h Battles/AGothicBattle.cpp Battles/AGothicBattle.h Battles/EarGirlBattle.cpp Battles/EarGirlBattle.h Battles/WaveBattle.cpp Battles/WaveBattle.h Battles/AppleBattle.cpp Battles/AppleBattle.h Battles/GeorgeBattle.cpp Battles/GeorgeBattle.h Battles/FarmManBattle.cpp Battles/FarmManBattle.h)

target_link_libraries(MuseumGame PRIVATE raylib winmm)
