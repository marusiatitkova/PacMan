#include <iostream>
#include "../include/Maze.h"

Maze::Maze() {
    width = FIELD_MAZE[0].size();
    height = FIELD_MAZE.size();
    setCells();
}

size_t Maze::getWidth() const {
    return width;
}

size_t Maze::getHeight() const {
    return height;
}

const std::vector<std::vector<Cell>> &Maze::getCells() const {
    return cells;
}

void Maze::setCells() {
    cells.resize(width);
    for (size_t x = 0; x < width; x++) {
        cells[x].resize(height);
        for (size_t y = 0; y < height; y++) {
            cells[x][y].setPosition(x * blockSize, y * blockSize);
            if (cells[x][y].isWall(FIELD_MAZE[y][x])){
                cells[x][y].setFillColor(sf::Color(52, 93, 199));
            }
            if (cells[x][y].holdsPacman(FIELD_MAZE[y][x])) {
                pacmanPosition = {x * blockSize, y * blockSize};
            }
        }
    }
}

float Maze::getBlockSize() const {
    return blockSize;
}

const sf::Vector2f &Maze::getPacmanPosition() const {
    return pacmanPosition;
}

Cell Maze::getCellbyPosition(const sf::Vector2f& pos) {
    for (size_t x = 0; x < width; x++) {
        for (size_t y = 0; y < height; y++) {
            if (cells[x][y].getPosition() == pos) {
                return cells[x][y];
            }
        }
    }
    std::cerr << "Cell not found " << pos.x << " " << pos.y << std::endl;
    return Cell();
}


