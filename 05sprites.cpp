/* Creating Sprites using textures*/

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

    sf::Texture sandy;
    if (!sandy.loadFromFile("texture/sandy.jpeg", sf::IntRect(0, 0, 200, 200))) {
        cout << "Error loading sandy texture file!" << endl;
        return -1;
    }

    sf::Sprite sprite_1;
    sprite_1.setPosition(100.0f, 100.0f);
    sprite_1.setTexture(sandy);

    sf::Sprite sprite_2;
    sprite_2.setPosition(310.0f, 100.0f);
    sprite_2.setTexture(sandy);
    sprite_2.setColor(sf::Color::Red);

    sf::Sprite sprite_3;
    sprite_3.setPosition(520.0f, 100.0f);
    sprite_3.setTexture(sandy);
    sprite_3.setColor(sf::Color(255, 0, 0, 128));

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();
                cout << "Window closed successfully!" << endl;
            }
        }

        window.clear(sf::Color::White);
        window.draw(sprite_1);
        window.draw(sprite_2);
        window.draw(sprite_3);
        window.display();
    }

    return 0;
}

