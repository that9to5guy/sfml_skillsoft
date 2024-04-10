/* Drawing Line using rectangle*/

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

    sf::RectangleShape line;
    line.setPosition(sf::Vector2f(200.0f, 100.0f));
    line.setSize(sf::Vector2f(300.0f, 3.0f));
    line.setFillColor(sf::Color(255, 195, 0));

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();
                cout << "Window closed successfully!" << endl;
            }
        }

        window.clear(sf::Color::Red);
        window.draw(line);
        window.display();
    }

    return 0;
}

