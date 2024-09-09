/* Generating Circles from Circumferences */
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using std::cout;
using std::endl;

#define BALLS 36

class circleCir {
    private:
        sf::SoundBuffer click_buffer;
        sf::Sound       click_sound;

        sf::RectangleShape square;
        sf::FloatRect      sqBounds;

        sf::CircleShape circle[BALLS];
        sf::FloatRect   cirBounds[BALLS];

        float velocitX[BALLS];
        float velocitY[BALLS];
        double theta_deg[BALLS];
        double theta_rad[BALLS];

        unsigned int r;
        unsigned int g;
        unsigned int b;
        bool isCollided;
        bool load_sound();
        bool load_square();
        bool load_circle();

    public:
        bool init_simu();

        void move_circle(int n);
        void check_collision(int n);

        void draw_window(sf::RenderWindow& window);
};
