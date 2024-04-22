/* Simulating Hues & Colors*/
#pragma once
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

#define BALLS 72

class huesColor {
    private:
        sf::RectangleShape square;
        sf::FloatRect      sqBounds;

        sf::CircleShape circle[BALLS];
        sf::FloatRect   cirBounds[BALLS];

        unsigned int r,g,b;
        float c,x,m,hue;

        float velocitX[BALLS];
        float velocitY[BALLS];
        double theta_deg[BALLS];
        double theta_rad[BALLS];

        bool flag;
        unsigned int count;
        sf::Vector3i rgb[360];

        bool load_square();
        bool load_circle();
        void create_rgbVector(int i);
    public:
        bool init_simu();
        void update_hue();
        void draw_window(sf::RenderWindow& window);
};
