#include "../include/Pacman.h"
#include <cmath>
#include <iostream>

sf::CircleShape Pacman::createTarget(const float& radius) {
    sf::CircleShape targetShape(radius);
    targetShape.setFillColor(sf::Color::Green);
    targetShape.setPosition(endTarget);
    return targetShape;
}

void Pacman::updatePacman(float elapsedTime) {
    if (target == sf::Vector2f{-1, -1}) {
        return;
    }

    float step = speed * elapsedTime;
    sf::Vector2f currentPosition = {getPosition().x, getPosition().y};
    sf::Vector2f direction = target - currentPosition;
    float distance = sqrtf((direction.x * direction.x) + (direction.y * direction.y));
    sf::Vector2f unitVector(direction.x / distance, direction.y / distance);
    if (distance < 1.f) {
        checkTarget(currentPosition + direction);
        move (direction);
    } else {
        checkTarget(currentPosition + unitVector * step);
        move(unitVector * step);
    }
}

void Pacman::setTarget(sf::Vector2f new_target) {
    endTarget = new_target;
}

void Pacman::setPath(const std::vector<sf::Vector2f> &path) {
    this->path = path;
    if (!this->path.empty()) {
        target = this->path.front();
        this->path.erase(this->path.begin());
    }
}

void Pacman::checkTarget(const sf::Vector2f& newPosition) {
    if (newPosition == target) {
        if (!path.empty()) {
            target = path.front();
            path.erase(path.begin());
        } else {
            target = {-1, -1};
        }
    }
}







