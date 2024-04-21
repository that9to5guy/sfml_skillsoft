/* Generating Basic Shapes & Bounds */
#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Circle Shape Polygons", sf::Style::Titlebar | sf::Style::Close);

    sf::Image game_icon;
    game_icon.loadFromFile("../abstractImg.png");
    window.setIcon(game_icon.getSize().x, game_icon.getSize().y, game_icon.getPixelsPtr());

    sf::CircleShape circle(5.0f);
    circle.setOrigin(sf::Vector2f(5.f, 5.f));
    circle.setPosition(sf::Vector2f(300.0f, 300.0f));
    circle.setFillColor(sf::Color::Red);
    // circle.setOutlineColor(sf::Color::White);
    // circle.setOutlineThickness(1.0f);

    sf::RectangleShape square;
    square.setSize(sf::Vector2f(400.f, 400.0f));
    square.setPosition(sf::Vector2f(300.0f, 300.0f));
    square.setOrigin(sf::Vector2f(200.0f, 200.0f));
    square.setFillColor(sf::Color::Transparent);
    square.setOutlineColor(sf::Color::White);
    square.setOutlineThickness(-5.0f);

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(circle);
        window.draw(square);
		window.display();
    }

    return 0;
}
