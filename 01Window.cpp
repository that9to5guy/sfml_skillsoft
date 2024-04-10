#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

using sf::Window;
using sf::VideoMode;
using sf::Event;

int main()
{
    Window window(VideoMode(500, 500), "SFML Window");
    
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
