#include "../include/Cell.h"

Cell::Cell() {
    setSize(sf::Vector2f{blockSize, blockSize});
    setFillColor(sf::Color(40, 40, 40));
}

float Cell::getBlockSize() const {
    return blockSize;
}

bool Cell::isWall(const char& symbol) {
    if (symbol == '#') {
        wall = true;
    }
    return symbol == '#';
}

bool Cell::holdsPacman(const char& symbol) {
    return symbol == 'P';
}

bool Cell::cellStatus() {
    return wall;
}


