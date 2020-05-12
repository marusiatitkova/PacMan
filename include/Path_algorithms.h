#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include "Maze.h"

enum class Direction {
    UP,
    DOWN,
    RIGHT,
    LEFT
};

struct Statistics;

template<>
constexpr bool std::less<sf::Vector2f>::operator()(const sf::Vector2f& lhs, const sf::Vector2f& rhs) const {
    if(lhs.x == rhs.x) {
        return lhs.y < rhs.y;
    }
    return lhs.x < rhs.x;
}

class Path_algorithms {
public:
    Path_algorithms() = default;
    Path_algorithms(const size_t&, const size_t&, Maze* _maze);

    std::vector<sf::Vector2f> dfs(const sf::Vector2f& start, const sf::Vector2f& end);
    std::vector<sf::Vector2f> bfs(const sf::Vector2f& start, const sf::Vector2f& end);
    std::vector<sf::Vector2f> greedy(const sf::Vector2f& start, const sf::Vector2f& end);
    std::vector<sf::Vector2f> a_star(const sf::Vector2f& start, const sf::Vector2f& end);
    static void showPath(const std::vector <sf::Vector2f>& path);
    std::vector<sf::Vector2f> getPath(const sf::Vector2f& from, const sf::Vector2f& to);
private:
    size_t width;
    size_t height;
    Maze *maze;
    std::vector<sf::Vector2f> convertPathToCells(const std::vector<sf::Vector2f>& path);
    sf::Vector2f convertCoordinatesToMaze (const sf::Vector2f& cur);
    std::vector<sf::Vector2f> getNeighbours(const sf::Vector2f& cur);
    bool canMove(const sf::Vector2f& to);
    bool dfs_recursion(const sf::Vector2f& from, const sf::Vector2f& to, std::map<sf::Vector2f, bool>& pathPoint_to_isVisited,
            std::vector <sf::Vector2f>& path, Statistics& dfsStat);
    static int heuristic (const sf::Vector2f& from, const sf::Vector2f& to);
    static std::vector<sf::Vector2f> getPathByParent(std::vector<std::vector<sf::Vector2f>> parent, const sf::Vector2f& start, const sf::Vector2f& end);
    std::map<Direction, sf::Vector2f> neighboursMoves = {{Direction::UP, {0, 1}},
                                                         {Direction::DOWN, {0, -1}},
                                                         {Direction::RIGHT, {1, 0}},
                                                         {Direction::LEFT, {-1, 0}}};
};



