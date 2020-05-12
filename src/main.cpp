#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Pacman.h"
#include "../include/Game_window.h"
#include "../include/Maze.h"


int main() {
    Maze maze;
    GameWindow gameWindow(maze.getWidth() * maze.getBlockSize(), maze.getHeight() * maze.getBlockSize(), "PACMAN GAME");
    Pacman pacman("../resources/pacman.png", maze.getBlockSize()/2.f);
    gameWindow.setMaze(&maze);
    gameWindow.setPacman(&pacman);
    gameWindow.setPathAlgorithms();

    sf::Clock clock;

    while (gameWindow.isOpen())
    {
        gameWindow.handleEvents();
        const float elapsedTime = clock.getElapsedTime().asSeconds();
        clock.restart();
        pacman.updatePacman(elapsedTime);
        gameWindow.render();
    }

    return 0;
}