/* Tracking Mouse Actions in SFML */
#include <iostream>
#include "MouseSim.h"

using std::cout;
using std::endl;

int main()
{
    static int on=2;
    static int bn=2;
    static int cn=2;
    static int xn=2;
    MouseSim mouse_sim;

    if (!mouse_sim.init_game()) {
		std::cout << "Unable to load game assets" << std::endl;
		return -1;
	}

    sf::RenderWindow window(sf::VideoMode(650, 500), "Mouse Action", sf::Style::Titlebar | sf::Style::Close);

    sf::Image game_icon;
    game_icon.loadFromFile("../asset/MouseSticker.png");
    window.setIcon(game_icon.getSize().x, game_icon.getSize().y, game_icon.getPixelsPtr());

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Right) {
                        cout << "Right mouse button pressed" << endl;
                        if(on<4) { on++; }
                        if(bn>0) { bn--; }
                    }
                    if (event.mouseButton.button == sf::Mouse::Middle) {
                        cout << "Middle mouse button pressed" << endl;
                    }
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        cout << "Left mouse button pressed" << endl;
                        if(on>0) { on--; }
                        if(bn<4) { bn++; }
                    }
                    cout << "Mouse position: " << event.mouseButton.x << ", " << event.mouseButton.y << endl;
                    mouse_sim.play_sound();
                    break;
                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Right) {
                        cout << "Right mouse released" << endl;
                        if(cn<3) { cn++; }
                        if(xn>0) { xn--; }
                    }
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        cout << "Left mouse released" << endl;
                        if(cn>0) { cn--; }
                        if(xn<3) { xn++; }
                    }
                    mouse_sim.play_sound();
                    break;
                case sf::Event::MouseWheelScrolled:
                    cout << "Scrolling delta: " << event.mouseWheelScroll.delta << endl;
                    break;
                case sf::Event::MouseMoved:
                    cout << "Mouse Moved: " << event.mouseMove.x << "-" << event.mouseMove.y << endl;
                    break;
                case sf::Event::Closed:
                    window.close();
                    cout << "Window closed successfully!" << endl;
                    break;
                default:
                    break;
            }
        }

        window.clear(sf::Color(150,135,167,255));
        window.draw(mouse_sim.drawPara());
        window.draw(mouse_sim.drawOrangeBar(on));
        window.draw(mouse_sim.drawBlueBar(bn));
        window.draw(mouse_sim.drawCircleO(cn));
        window.draw(mouse_sim.drawCircleX(xn));
        window.display();
    }

    return 0;
}
