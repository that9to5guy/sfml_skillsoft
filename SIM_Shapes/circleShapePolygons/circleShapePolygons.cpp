/* Generating Basic Shapes & Bounds */
#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Circle Shape Polygons", sf::Style::Titlebar | sf::Style::Close);

    sf::Image game_icon;
    game_icon.loadFromFile("../abstractImg.png");
    window.setIcon(game_icon.getSize().x, game_icon.getSize().y, game_icon.getPixelsPtr());

    sf::CircleShape circle(50.0f);
    sf::CircleShape triangle(50.0f, 3);
    sf::CircleShape square(50.0f, 4);
    sf::CircleShape pentagon(50.0f, 5);

    circle.setPosition(sf::Vector2f(100.0f, 100.0f));
    triangle.setPosition(sf::Vector2f(300.0f, 100.0f));
    square.setPosition(sf::Vector2f(500.0f, 100.0f));
    pentagon.setPosition(sf::Vector2f(700.0f, 100.0f));

    circle.setFillColor(sf::Color::Magenta);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(2.0f);

    triangle.setFillColor(sf::Color::Yellow);
    triangle.setOutlineColor(sf::Color::White);
    triangle.setOutlineThickness(2.0f);

    square.setFillColor(sf::Color::Green);
    square.setOutlineColor(sf::Color::White);
    square.setOutlineThickness(2.0f);

    pentagon.setFillColor(sf::Color::Blue);
    pentagon.setOutlineColor(sf::Color::White);
    pentagon.setOutlineThickness(2.0f);

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
        window.draw(triangle);
        window.draw(square);
        window.draw(pentagon);
		window.display();
    }

    return 0;
}