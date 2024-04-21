/* Generating Basic Shapes & Bounds */
#include "boxObj.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Circle Shape Polygons", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Image game_icon;
    game_icon.loadFromFile("../abstractImg.png");
    window.setIcon(game_icon.getSize().x, game_icon.getSize().y, game_icon.getPixelsPtr());

    boxObj object;
    if(!object.init_simu()) {
        std::cout << "Unable to load game objects" << std::endl;
		return -1;
    }

    while(window.isOpen())
    {
        window.clear(sf::Color(0,0,30,255));
        object.draw_window(window);
		window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        for(int i=0;i<BALLS;i++) {
            object.move_circle(i);
        }
    }

    return 0;
}
