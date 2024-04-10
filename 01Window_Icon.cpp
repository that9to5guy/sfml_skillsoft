/* Adding an Icon to the window */

#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

using sf::Window;
using sf::VideoMode;
using sf::Event;

int main()
{
    Window window(VideoMode(800, 400), "SFML Window");
    
    sf::Image win_icon;
    if (!win_icon.loadFromFile("icon/bulb.png")) {
        cout << "Icon could not be loaded" << endl;
    }

    window.setIcon(win_icon.getSize().x, win_icon.getSize().y, win_icon.getPixelsPtr());

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                
                cout << "Window closed successfully!" << endl;
            }            
        }
    }

    return 0;
}
