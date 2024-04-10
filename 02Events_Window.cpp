/* Events in  sfml window */

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
                case Event::Resized:                
                    cout << "Current window size: " << event.size.width 
                         << "x" << event.size.height << endl;
                    break;     
                case Event::LostFocus:    
                    cout << "Lost Focus from game window" << endl;
                    break;     
                case Event::GainedFocus:       
                    cout << "Focus on game window" << endl;
                    break;     
                case Event::Closed:
                    window.close();
                    cout << "Window closed successfully!" << endl;
                    break;
                default:
                    // Do nothing - all key press, mouse scroll, joystick and other events
                    // will be handled by the default case
                    break;
            }
        }
    }

    return 0;
}
