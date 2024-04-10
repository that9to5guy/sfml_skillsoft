/* Key Press Events */

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
                case Event::KeyPressed:
                    cout << "--------------------------------------------" << endl;
                    cout << "Key pressed" << endl;

                    if (event.key.code == sf::Keyboard::Enter) {
                        cout << "Enter pressed" << endl;
                    } else if (event.key.code == sf::Keyboard::Backspace) {
                        cout << "Backspace pressed" << endl;
                    } else if (event.key.code == sf::Keyboard::A) {
                        cout << "A pressed" << endl;
                    }
                    
                    // Modifier Keys
                    cout << "control:" << event.key.control << endl;
                    cout << "alt:" << event.key.alt << endl;
                    cout << "shift:" << event.key.shift << endl;
                    cout << "system:" << event.key.system << endl;
                    break;     
                case Event::KeyReleased:  
                    cout << "Key released" << endl;
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

