#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;

int main()
{
    RenderWindow window(VideoMode(850, 450), "Transformations");

    sf::RectangleShape rectangle(sf::Vector2f(200.0f, 100.0f));
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setOutlineThickness(2.0f);
    rectangle.setPosition(sf::Vector2f(50.0f, 50.0f));

    sf::Texture fiery;
    if (!fiery.loadFromFile("texture/fiery.jpeg", sf::IntRect(0, 0, 800, 800))) {
        cout << "Error loading fiery texture file!" << endl;
        return -1;
    }

    rectangle.setTexture(&fiery);

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {

            switch (event.type) {
                case Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Right) {
                        rectangle.move(10.0f, 5.0f);
                    } else if (event.mouseButton.button == sf::Mouse::Left) {
                        rectangle.move(-10.0f, -5.0f);
                    }
                    break;
                case Event::Closed:
                    window.close();
                    cout << "Window closed successfully!" << endl;
                    break;
                default:
                    break;
            }
        }

        window.clear(sf::Color::White);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}

