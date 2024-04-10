/* Drawing Rectangle */

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

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(300.0f, 100.0f));

    rectangle.setPosition(sf::Vector2f(425.0f, 200.0f));

    rectangle.setFillColor(sf::Color(0, 255, 0));

    rectangle.setOutlineColor(sf::Color(100, 20, 255));
    rectangle.setOutlineThickness(7.0f);
    // Outline extrudes outside of shape dimensions
    // rectangle.setOutlineThickness(-7.0f);

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();
                cout << "Window closed successfully!" << endl;
            }
        }

        window.clear(sf::Color::Red);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}

