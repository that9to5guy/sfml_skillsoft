/* Simulating Hues & Colors*/
#include "hues.h"

int main()
{
    huesColor hueC;
    if(!hueC.init_simu()) {
        std::cout << "Unable to load game objects" << std::endl;
		return -1;
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "Hues & Colors", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    while(window.isOpen())
    {
        window.clear();
        hueC.update_hue();
        hueC.draw_window(window);
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
