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

    sf::RenderWindow window(sf::VideoMode(950, 540), "Click The Buttons", sf::Style::Titlebar | sf::Style::Close);

    sf::Image game_icon;
    game_icon.loadFromFile("../assets/clickMouse.png");
    window.setIcon(game_icon.getSize().x, game_icon.getSize().y, game_icon.getPixelsPtr());

    while(window.isOpen())
    {
        window.clear(sf::Color::White);
		clickObjects.draw_windows(window);
		window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                cout << "Window closed successfully!" << endl;
            }
            if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f posi = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    cout << posi.x << " = " << posi.y <<endl;
                    clickObjects.buttonPress(window.mapPixelToCoords(sf::Mouse::getPosition(window)), window);
				}
			}
        }
    }
    return 0;
}
