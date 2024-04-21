/* Generating Basic Shapes & Bounds */
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using std::cout;
using std::endl;

#define BALLS 20

class boxObj {
    private:
        sf::SoundBuffer click_buffer;
        sf::Sound       click_sound;
        
        sf::RectangleShape square;
        sf::CircleShape    circle[BALLS];

        sf::FloatRect sqBounds;
        sf::FloatRect cirBounds[BALLS];

        float velocitX[BALLS];
        float velocitY[BALLS];

        bool load_sound();
        bool load_square();
        bool load_circle();
    
    public:
        bool init_simu();

        void move_circle(int n);
        void check_collision(int n);
        void draw_window(sf::RenderWindow& window);

};
