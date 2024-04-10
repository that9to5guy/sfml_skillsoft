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

    sf::RectangleShape square(sf::Vector2f(150.0f, 150.0f));
    square.setOutlineColor(sf::Color::Black);
    square.setOutlineThickness(2.0f);

    square.setPosition(sf::Vector2f(10.0f, 10.0f));
    square.setScale(2.0f,1.5f);

    sf::Texture fiery;
    if (!fiery.loadFromFile("texture/fiery.jpeg", sf::IntRect(0, 0, 800, 800))) {
        cout << "Error loading fiery texture file!" << endl;
        return -1;
    }

    square.setTexture(&fiery);

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {

            switch (event.type) {
                case Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Right) {
                        square.scale(1.5f,2.0f);
                    } else if (event.mouseButton.button == sf::Mouse::Left) {
                        square.scale(0.667f,0.5f);
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
        window.draw(square);
        window.display();
    }

    return 0;
}

