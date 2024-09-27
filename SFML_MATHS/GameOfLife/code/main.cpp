/* main of game of life */

#include "gameoflife.h"

int main()
{
    GameOfLife conway;

    if (!conway.init_game()) {
		std::cout << "Unable to load game assets" << std::endl;
		return -1;
	}

    sf::RenderWindow window(sf::VideoMode(800, 600), "Game Of Life", sf::Style::Titlebar | sf::Style::Close);

    sf::Image game_icon;
    game_icon.loadFromFile("../assets/Grass-control.png");
    window.setIcon(game_icon.getSize().x, game_icon.getSize().y, game_icon.getPixelsPtr());

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if(event.type == sf::Event::MouseButtonPressed) {
                conway.click_sound();
            }
        }

        window.clear();
		conway.draw_windows(window);
		window.display();
    }

    return 0;
}