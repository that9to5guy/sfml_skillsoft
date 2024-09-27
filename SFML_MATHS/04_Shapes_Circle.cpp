/* Drawing & Resizing the Circle */


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

//    circle.setPosition(sf::Vector2f(100.0f, 100.0f));
    circle.setFillColor(sf::Color::Magenta);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(5.0f);

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    circle.setRadius(circle.getRadius() * 1.2);
                } else if (event.mouseButton.button == sf::Mouse::Right) {
                    circle.setRadius(circle.getRadius() / 1.2);
                }
            }

            if (event.type == Event::Closed) {
                window.close();
                cout << "Window closed successfully!" << endl;
            }
        }

        window.clear(sf::Color::Red);
        window.draw(circle);
        window.display();
    }

    return 0;
}

