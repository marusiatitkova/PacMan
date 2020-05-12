cmake_minimum_required(VERSION 3.15)
project(PacMan)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS window graphics audio system REQUIRED)
add_executable(PacMan
        src/main.cpp
        src/Pacman.cpp include/Pacman.h
        src/Game_window.cpp include/Game_window.h
        src/Maze.cpp include/Maze.h
        src/Cell.cpp include/Cell.h
        src/Path_algorithms.cpp include/Path_algorithms.h)
target_link_libraries(PacMan sfml-graphics sfml-audio sfml-window sfml-system)