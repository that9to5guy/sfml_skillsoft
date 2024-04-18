/* Tracking Mouse Actions in SFML */
#include <iostream>
#include "ClickObj.h"

using std::cout;
using std::endl;

int main()
{
    ClickObj clickObjects;

    if (!clickObjects.init_game()) {
		std::cout << "Unable to load game assets" << std::endl;
		return -1;
	}

    sf::RenderWindow window(sf::VideoMode(950, 540), "Click Objects", sf::Style::Titlebar | sf::Style::Close);

    sf::Image game_icon;
    game_icon.loadFromFile("../assets/clickMouse.png");
    window.setIcon(game_icon.getSize().x, game_icon.getSize().y, game_icon.getPixelsPtr());

    sf::Texture bgTexture;
    if(!bgTexture.loadFromFile("../assets/Background/Background_Blue.png")) {
        cout << "Error loading texture file!" << endl;
        return EXIT_FAILURE;
    }
    sf::Sprite area_sprite;
    area_sprite.setTexture(bgTexture);
    area_sprite.setScale(sf::Vector2f(0.5, 0.5f));

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                
                cout << "Window closed successfully!" << endl;
            }            
        }

        window.clear(sf::Color::Black);
        window.draw(area_sprite);
        window.display();
    }
    return 0;
}
