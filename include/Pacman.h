#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Pacman : public sf::CircleShape {
public:
    Pacman(const std::string& texturePath, float radius) :
            sf::CircleShape(radius) {
        texture.loadFromFile(texturePath);
        setTexture(&texture);
        setPosition(initialPosition);
    };
    sf::CircleShape createTarget (const float&);
    void updatePacman(float elapsedTime);
    void setTarget(sf::Vector2f new_target);
    void setPath(const std::vector <sf::Vector2f>& path);
private:
    const float speed = 150.f;
    sf::Texture texture;
    sf::Vector2f target = {-1.0, -1.0};
    sf::Vector2f endTarget = {-1.0, -1.0};
    sf::Vector2f initialPosition = {0.0, 0.0};
    std::vector <sf::Vector2f> path;
    void checkTarget(const sf::Vector2f& newPosition);
};

