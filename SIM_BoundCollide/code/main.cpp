/* Basic Bounding boxes & collisions */
#include <iostream>
#include "BoundCollide.h"

using std::cout;
using std::endl;

int main()
{
    BoundCollide boco;

    sf::RenderWindow window(sf::VideoMode(650, 500), "Bounding & Collision", sf::Style::Titlebar | sf::Style::Close);

    sf::Image game_icon;
    game_icon.loadFromFile("../assets/collision.png");
    window.setIcon(game_icon.getSize().x, game_icon.getSize().y, game_icon.getPixelsPtr());

    while(window.isOpen())
    {
        window.clear();
		boco.draw_windows(window);
		window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}