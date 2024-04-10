/* mouse events */

#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

using sf::Window;
using sf::VideoMode;
using sf::Event;

int main()
{
    Window window(VideoMode(850, 450), "Events");

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {

            switch (event.type) {
                case Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Right) {
                        cout << "Right mouse button pressed" << endl;
                    }
                    if (event.mouseButton.button == sf::Mouse::Middle) {
                        cout << "Middle mouse button pressed" << endl;
                    }
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        cout << "Left mouse button pressed" << endl;
                    }
                    cout << "Mouse position: " << event.mouseButton.x 
                            << ", " << event.mouseButton.y << endl;
                    break;
                case Event::MouseButtonReleased:
                    cout << "Mouse button released" << endl;
                    break;
                case Event::MouseWheelScrolled:
                    cout << "Scrolling delta: " << event.mouseWheelScroll.delta << endl;
                    break;
                case Event::Closed:
                    window.close();
                    cout << "Window closed successfully!" << endl;
                    break;
                default:
                    break;
            }
        }
    }

    return 0;
}
