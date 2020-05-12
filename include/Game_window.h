#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Pacman.h"
#include "Maze.h"
#include "Path_algorithms.h"


class GameWindow : public sf::RenderWindow {
public:
    GameWindow(size_t width, size_t height, const std::string& title) :
            sf::RenderWindow(sf::VideoMode(width, height), title) {
        setFramerateLimit(MAX_FPS);
    }
    void handleEvents();
    void render();
    void setPacman (Pacman *pacman_) {
        pacman = pacman_;
        pacman->setPosition(maze->getPacmanPosition());
    }
    void setMaze (Maze *maze_) {
        maze = maze_;
    }
    void setPathAlgorithms() {
        pathAlgorithms = Path_algorithms(maze->getWidth(), maze->getHeight(), maze);
    }
    void drawMaze();

private:
    const unsigned MAX_FPS = 60;
    Pacman *pacman = nullptr;
    Maze *maze = nullptr;
    Path_algorithms pathAlgorithms{};
    bool drawTarget = false;
};


