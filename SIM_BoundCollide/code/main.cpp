/* Basic Bounding boxes & collisions */
#include <iostream>
#include "BoundCollide.h"

using std::cout;
using std::endl;

int main()
{
    BoundCollide boco;
    if (!boco.init_game()) {
		std::cout << "Unable to load game assets" << std::endl;
		return -1;
	}

    sf::RenderWindow window(sf::VideoMode(1000, 600), "Bounding & Collision", sf::Style::Titlebar | sf::Style::Close);

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
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                // cout << "Mouse position: " << event.mouseButton.x << ", " << event.mouseButton.y << endl;
                boco.click_sound();
                boco.update_sprites();
                cout << "Global Bounds Sprites" << endl;
                for(int j=0;j<5;j++) {
                    sf::FloatRect gloBou = boco.check_sprite(j).getGlobalBounds();
                    cout << gloBou.left << " " << gloBou.top << " " << gloBou.width << " " << gloBou.height << endl;
                }
            }
        }

    }

    return 0;
}
