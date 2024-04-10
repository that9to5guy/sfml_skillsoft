#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;

int main()
{
    RenderWindow window(VideoMode(850, 450), "Animation");

    sf::Texture torch_texture;
    if(!torch_texture.loadFromFile("texture/torch_sprite.jpg")) {
        cout << "Error loading texture file!" << endl;
        return EXIT_FAILURE;
    }

    sf::Sprite torch_sprite;
    torch_sprite.setTexture(torch_texture);
    
    sf::Vector2u torch_sprite_size = torch_texture.getSize();
    sf::IntRect irect(0, 0, torch_sprite_size.x/7, torch_sprite_size.y);
    torch_sprite.setTextureRect(irect);

    torch_sprite.setPosition(sf::Vector2f(320, 0));

    sf::Clock clock;

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {

            switch (event.type) {
                case Event::Closed:
                    window.close();
                    cout << "Window closed successfully!" << endl;
                    break;
                default:
                    break;
            }
        }

        if (clock.getElapsedTime().asSeconds() > 0.1f) {
            if (irect.left >= 6 * (torch_sprite_size.x/7)) {
                irect.left = 0;
            } else {
                irect.left += (torch_sprite_size.x/7);
            }
            torch_sprite.setTextureRect(irect);
            clock.restart();
        }

        window.clear(sf::Color(44, 27, 19, 255));
        window.draw(torch_sprite);
        window.display();    
    }

    return 0;
}

