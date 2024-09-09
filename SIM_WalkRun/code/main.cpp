#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;

int main()
{
    RenderWindow window(VideoMode(300, 300), "Animation");

    sf::Texture character_texture;
    if(!character_texture.loadFromFile("../assets/WalkRun.png")) {
        cout << "!! Error loading Characters !!" << endl;
        return EXIT_FAILURE;
    }
    
    sf::Sprite char_sprite;
    char_sprite.setTexture(character_texture);

    sf::Vector2u sprite_sheet_size = character_texture.getSize();
    sf::IntRect irectChar(0, sprite_sheet_size.y/3, sprite_sheet_size.x/8, sprite_sheet_size.y/3);
    char_sprite.setTextureRect(irectChar);
    char_sprite.setPosition(sf::Vector2f(100, 50));

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
            cout << clock.getElapsedTime().asSeconds() << endl;
            if (irectChar.left >= 7 * (sprite_sheet_size.x/8)) {
                irectChar.left = 0;
            } else {
                irectChar.left += (sprite_sheet_size.x/8);
            }
            char_sprite.setTextureRect(irectChar);
            clock.restart();
        }

        window.clear(sf::Color(50,120,50,255));
        window.draw(char_sprite);
        window.display(); 
    }

    return 0;
}