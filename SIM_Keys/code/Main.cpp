/* Tracking Keys Actions in SFML */
#include <iostream>
#include "KeysSim.h"

using std::cout;
using std::endl;

int main()
{
    KeysSim inKey01;

    if (!inKey01.init_game()) {
		std::cout << "Unable to load game assets" << std::endl;
		return -1;
	}

    sf::RenderWindow window(sf::VideoMode(800, 600), "Doppler Effect", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Image game_icon;
    game_icon.loadFromFile("../asset/UI-116.png");
    window.setIcon(game_icon.getSize().x, game_icon.getSize().y, game_icon.getPixelsPtr());

    while(window.isOpen())
    {
        window.clear(sf::Color(50,100,200,0));
		inKey01.draw_windows(window);
		window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if(event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down
                    || event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Left) {
                        cout << "Arrow Key pressed" << endl;
                        inKey01.play_sound(2);
                    } else if (event.key.code == sf::Keyboard::Backspace) {
                        cout << "Backspace pressed" << endl;
                        inKey01.play_sound(0);
                    } else if (event.key.code == sf::Keyboard::Space) {
                        cout << "Space pressed" << endl;
                        inKey01.play_sound(1);
                    }
                    else if(event.key.code >= 0 && event.key.code <= 25 ) {
                        cout << "Alphabets pressed : " << event.key.code << endl;
                        inKey01.play_sound(4);
                    }
            }
        }
    }

    return 0;
}
