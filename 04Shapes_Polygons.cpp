/* Drawing Shapes using Circle Class */

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

    sf::CircleShape circle(100.0f);
    sf::CircleShape triangle(100.0f, 3);
    sf::CircleShape square(100.0f, 4);
    sf::CircleShape polygon(100.0f, 5);

    circle.setPosition(sf::Vector2f(100.0f, 100.0f));
    triangle.setPosition(sf::Vector2f(250.0f, 100.0f));
    square.setPosition(sf::Vector2f(400.0f, 100.0f));
    polygon.setPosition(sf::Vector2f(550.0f, 100.0f));

    circle.setFillColor(sf::Color::Magenta);
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(2.0f);

    triangle.setFillColor(sf::Color::Yellow);
    triangle.setOutlineColor(sf::Color::Black);
    triangle.setOutlineThickness(2.0f);

    square.setFillColor(sf::Color::Green);
    square.setOutlineColor(sf::Color::Black);
    square.setOutlineThickness(2.0f);

    polygon.setFillColor(sf::Color::Blue);
    polygon.setOutlineColor(sf::Color::Black);
    polygon.setOutlineThickness(2.0f);

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();
                cout << "Window closed successfully!" << endl;
            }
        }

        window.clear(sf::Color::Red);
        window.draw(circle);
        window.draw(triangle);
        window.draw(square);
        window.draw(polygon);
        window.display();
    }

    return 0;
}

