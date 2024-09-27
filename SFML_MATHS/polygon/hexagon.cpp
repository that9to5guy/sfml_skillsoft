/* Drawing polygons using Convex Shapes */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

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

    sf::ConvexShape polygons;
    polygons.setPointCount(6);

    float radius = 100;
    float angle = M_PI / 3;

    for (int i = 0; i < 6; ++i)
    {
        float x = radius * std::cos(i * angle);
        float y = radius * std::sin(i * angle);
        polygons.setPoint(i, sf::Vector2f(x, y));
    }

    // Set the position of the hexagon in the center of the window
    polygons.setPosition(400, 300); // Assuming window size is 800x600
    polygons.setFillColor(sf::Color::Green); // Set the color of the hexagon

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(polygons);
        window.display();
    }

    return 0;
}