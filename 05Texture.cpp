/* Applying Texture to a shape */

#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;

int main()
{
    RenderWindow window(VideoMode(850, 450), "Textures and Sprites");

    sf::Image image;

    if (!image.loadFromFile("texture/wavy.jpeg")) {
        cout << "Error loading texture file!" << endl;
        return -1;
    }

    sf::Texture texture;
    texture.loadFromImage(image, sf::IntRect(1000, 1000, 1200, 1200));

    sf::CircleShape circle(200);
    circle.setPosition(sf::Vector2f(200.0f, 30.0f));

    circle.setTexture(&texture);

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();
                cout << "Window closed successfully!" << endl;
            }
        }

        window.clear(sf::Color::White);
        window.draw(circle);
        window.display();
    }

    return 0;
}

