#pragma once

#include <SFML/Graphics.hpp>

class Cell : public sf::RectangleShape{
public:
    Cell();
    bool isWall(const char&);
    static bool holdsPacman(const char&);
    float getBlockSize() const;
    bool cellStatus();
private:
    const float blockSize = 25.f;
    bool wall = false;
};


