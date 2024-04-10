/* Drawing polygons using Convex Shapes */

#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;

int main()
{
    RenderWindow window(VideoMode(850, 450), "Drawing Shapes");

    sf::ConvexShape polygon(5);

    polygon.setPoint(0, sf::Vector2f(170.0f, 40.0f));
    polygon.setPoint(1, sf::Vector2f(550.0f, 240.0f));
    polygon.setPoint(2, sf::Vector2f(490.0f, 350.0f));
    polygon.setPoint(3, sf::Vector2f(200.0f, 420.0f));
    polygon.setPoint(4, sf::Vector2f(90.0f, 350.0f));

    polygon.setFillColor(sf::Color(255, 195, 0));
    polygon.setOutlineColor(sf::Color::White);
    polygon.setOutlineThickness(-2.0f);

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();
                cout << "Window closed successfully!" << endl;
            }
        }

        window.clear(sf::Color::Red);
        window.draw(polygon);
        window.display();
    }

    return 0;
}

