/* Adding the Style the window */

#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

using sf::Window;
using sf::VideoMode;
using sf::Event;

int main()
{
//    Window window(VideoMode(800, 400), "SFML Window", sf::Style::Default);
    Window window(VideoMode(800, 400), "SFML Window", sf::Style::Close);
//    Window window(VideoMode(800, 400), "SFML Window", sf::Style::Resize);
//    Window window(VideoMode(800, 400), "SFML Window", sf::Style::Resize | sf::Style::Close);
    
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
