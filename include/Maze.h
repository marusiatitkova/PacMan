#pragma once

#include "Cell.h"
#include "Pacman.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

static const std::vector<std::string> FIELD_MAZE = {{" ####################### "},
                                                    {" #          #          # "},
                                                    {" # ## ##### # ##### ## # "},
                                                    {" #                     # "},
                                                    {" # ## # ######### # ## # "},
                                                    {" #    #     #     #    # "},
                                                    {" #### ##### # ##### #### "},
                                                    {"    # #           # #    "},
                                                    {"##### # # ## ## # # #####"},
                                                    {"        # # P # #        "},
                                                    {"##### # # ##### # # #####"},
                                                    {"    # #           # #    "},
                                                    {" #### # ######### # #### "},
                                                    {" #          #          # "},
                                                    {" # ## ##### # ##### ## # "},
                                                    {" #  #               #  # "},
                                                    {" ## # # ######### # #  # "},
                                                    {" #    #     #     #    # "},
                                                    {" # ####### ### ####### # "},
                                                    {" # #     #     #     # # "},
                                                    {" # # ### ## # ## ### # # "},
                                                    {" # # #      #      # # # "},
                                                    {" # # # #### # #### # # # "},
                                                    {" #          #          # "},
                                                    {" ####################### "}};

class Maze {
public:
    Maze();
    size_t getWidth() const;
    size_t getHeight() const;
    const std::vector<std::vector<Cell>>& getCells() const;
    void setCells();
    float getBlockSize() const;
    const sf::Vector2f &getPacmanPosition() const;
    Cell getCellbyPosition(const sf::Vector2f& pos);

private:
    size_t width{0};
    size_t height{0};
    std::vector<std::vector<Cell>> cells;
    sf::Vector2f pacmanPosition;
    const float blockSize = Cell().getBlockSize();
};


