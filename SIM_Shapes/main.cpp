/* Generating Basic Shapes & Bounds */
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using std::cout;
using std::endl;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Basic Shapes", sf::Style::Titlebar | sf::Style::Close);

    sf::Image game_icon;
    game_icon.loadFromFile("abstractImg.png");
    window.setIcon(game_icon.getSize().x, game_icon.getSize().y, game_icon.getPixelsPtr());

    sf::CircleShape circle(50.f);
    circle.setPosition(sf::Vector2f(50.f, 50.f));
    circle.setFillColor(sf::Color::Red);
    circle.setOrigin(sf::Vector2f(50.f, 50.f));
    // circle.setOutlineColor(sf::Color::White);
    // circle.setOutlineThickness(2.0f);
    cout << circle.getGlobalBounds().left << " - " << circle.getGlobalBounds().top << " - " 
         << circle.getGlobalBounds().width << " - " <<  circle.getGlobalBounds().height << endl;
    cout << circle.getRadius() << endl;
    cout << "Origin   : " << circle.getOrigin().x << "-" << circle.getOrigin().y << endl;
    cout << "Position : " << circle.getPosition().x << " " << circle.getPosition().y << endl;
    cout << circle.getPointCount() << endl;
    cout << circle.getPoint(0).x << "-" << circle.getPoint(0).y << endl;

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
		window.display();
    }

    return 0;
}
