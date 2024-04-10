/* Text entered events */


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
                case Event::TextEntered:
                    cout << "Text: " << event.text.unicode << endl;
                    if (event.text.unicode < 128) {
                        cout << "ASCII character typed: " 
                             << static_cast<char>(event.text.unicode) << endl;
                    }
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
