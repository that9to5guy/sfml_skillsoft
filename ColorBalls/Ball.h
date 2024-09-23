// Header for Ball class
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

class Ball {
public:
    Ball(float radius = 20.f);

    void draw(sf::RenderWindow& window);

private:
    sf::CircleShape shape;

    static std::vector<sf::Color> colors;
};
