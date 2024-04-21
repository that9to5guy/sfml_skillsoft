/* Generating Basic Shapes & Bounds */
#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Basic Shapes", sf::Style::Titlebar | sf::Style::Close);

    sf::Image game_icon;
    game_icon.loadFromFile("abstractImg.png");
    window.setIcon(game_icon.getSize().x, game_icon.getSize().y, game_icon.getPixelsPtr());

    sf::CircleShape circle(50.f);
    circle.setPosition(sf::Vector2f(50.f, 50.f));
    circle.setFillColor(sf::Color::Red);
    circle.setOrigin(sf::Vector2f(50.f, 50.f));
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(-2.0f);
    cout << circle.getGlobalBounds().left << " - " << circle.getGlobalBounds().top << " - " 
         << circle.getGlobalBounds().width << " - " <<  circle.getGlobalBounds().height << endl;
    cout << circle.getRadius() << endl;
    cout << "Origin   : " << circle.getOrigin().x << "-" << circle.getOrigin().y << endl;
    cout << "Position : " << circle.getPosition().x << " " << circle.getPosition().y << endl;
    cout << circle.getPointCount() << endl;
    cout << circle.getPoint(0).x << "-" << circle.getPoint(0).y << endl;

    sf::ConvexShape convexShape(6);
    convexShape.setFillColor(sf::Color(255, 195, 0));
    convexShape.setOutlineColor(sf::Color::White);
    convexShape.setOutlineThickness(-2.0f);
    convexShape.setPoint(0, sf::Vector2f(170.0f, 40.0f));
    convexShape.setPoint(1, sf::Vector2f(550.0f, 240.0f));
    convexShape.setPoint(2, sf::Vector2f(490.0f, 350.0f));
    convexShape.setPoint(3, sf::Vector2f(200.0f, 420.0f));
    convexShape.setPoint(4, sf::Vector2f(90.0f, 350.0f));
    convexShape.setPoint(5, sf::Vector2f(190.0f, 300.0f));

    sf::RectangleShape rectangle;
    rectangle.setPosition(sf::Vector2f(500.0f, 100.0f));
    rectangle.setSize(sf::Vector2f(125.0f, 50.0f));
    rectangle.setFillColor(sf::Color(0, 195, 85));
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(-2.0f);

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                cout << "LEFT : " << event.mouseButton.x << ", " << event.mouseButton.y << endl;
                circle.setPosition(event.mouseButton.x,event.mouseButton.y);
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
                cout << "RIGHT: " << event.mouseButton.x << ", " << event.mouseButton.y << endl;
                rectangle.setPosition(event.mouseButton.x,event.mouseButton.y);
            }
            else if (event.type == sf::Event::MouseWheelScrolled) {
                cout << "Wheel Scroll : " << event.mouseWheelScroll.delta << endl;
            }
        }

        window.clear(sf::Color::Black);
        window.draw(convexShape);
        window.draw(rectangle);
        window.draw(circle);
		window.display();
    }

    return 0;
}
