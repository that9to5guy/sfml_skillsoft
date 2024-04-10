#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;

int rock_yaxis = 50;

int main()
{
    RenderWindow window(VideoMode(600, 600), "Animation");

    sf::Texture character_texture;
    if(!character_texture.loadFromFile("../assets/chars.png")) {
        cout << "!! Error loading Characters !!" << endl;
        return EXIT_FAILURE;
    }
    sf::Vector2u sprite_sheet_size = character_texture.getSize();
    
    sf::Sprite rock_sprite;
    rock_sprite.setTexture(character_texture);
    sf::Sprite paper_sprite;
    paper_sprite.setTexture(character_texture);
    sf::Sprite scissor_sprite;
    scissor_sprite.setTexture(character_texture);
 
    sf::IntRect irectRock(40, 0, sprite_sheet_size.x/3, sprite_sheet_size.y);
    rock_sprite.setTextureRect(irectRock);
    sf::IntRect irectPaper(80, 0, sprite_sheet_size.x/3, sprite_sheet_size.y);
    paper_sprite.setTextureRect(irectPaper);
    sf::IntRect irectScissor(0, 0, sprite_sheet_size.x/3, sprite_sheet_size.y);
    scissor_sprite.setTextureRect(irectScissor);

    rock_sprite.setPosition(sf::Vector2f(80, rock_yaxis));
    paper_sprite.setPosition(sf::Vector2f(280, rock_yaxis));
    scissor_sprite.setPosition(sf::Vector2f(480, rock_yaxis));

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

        if (rock_yaxis < 560 && clock.getElapsedTime().asSeconds() > 0.01f) {
            cout << clock.getElapsedTime().asSeconds() << endl;
            rock_sprite.setPosition(sf::Vector2f(80, rock_yaxis++));
            paper_sprite.setPosition(sf::Vector2f(280, rock_yaxis++));
            scissor_sprite.setPosition(sf::Vector2f(480, rock_yaxis++));
            clock.restart();
        }

        window.clear(sf::Color(104,144,168,255));
        window.draw(rock_sprite);
        window.draw(paper_sprite);
        window.draw(scissor_sprite);
        window.display(); 
    }

    return 0;
}