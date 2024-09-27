/* Drawing polygons using Convex Shapes */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>

using std::cout;
using std::endl;

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;

// Define M_PI if it's not defined
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

int main()
{
    RenderWindow window(VideoMode(800, 600), "P O L Y G O N S");

    // Seed the random number generator
    srand(time(NULL));

    float radius = 25.f;
    sf::CircleShape circle(radius);
    circle.setOrigin(radius,radius);
    circle.setFillColor(sf::Color::Green);
    circle.setOutlineColor(sf::Color::White);
    // circle.setOutlineThickness(5.0f);
    circle.setPosition(400.f,300.f);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // Set a random position for the circle
        circle.setPosition(rand() % 800, rand() % 600); // Adjust the range as needed

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();

        // Pause for a bit
        sf::sleep(sf::seconds(0.25));
    }

    return 0;
}