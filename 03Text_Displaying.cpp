/* Text Displaying & controlling in window */
#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;

int main()
{
    RenderWindow window(VideoMode(850, 450), "Drawing Text");

    sf::Font heading_font;
    if (!heading_font.loadFromFile("font/PressStart2P-Regular.ttf")) {
        cout << "Error loading font - PressStart2P-Regular.ttf" << endl;
        return -1;
    }

    sf::Text heading;
    heading.setFont(heading_font);
    heading.setString("SFML");

    heading.setPosition(sf::Vector2f(60.0f, 40.0f));
    heading.setCharacterSize(100);
    heading.setFillColor(sf::Color::Red);
    heading.setOutlineColor(sf::Color::Yellow);
    heading.setOutlineThickness(5);

    sf::Font paragraph_font;
    if (!paragraph_font.loadFromFile("font/FjallaOne-Regular.ttf")) {
        cout << "Error loading font - FjallaOne-Regular.ttf" << endl;
        return -1;
    }

    sf::Text paragraph;
    paragraph.setFont(paragraph_font);
    paragraph.setString("SFML has 5 modules - System, Window, Graphics, Audio, Network");

    paragraph.setPosition(sf::Vector2f(60.0f, 170.0f));
    paragraph.setScale(sf::Vector2f(0.80f, 2.0f));
    paragraph.setRotation(10);
    paragraph.setStyle(sf::Text::Style::Italic | sf::Text::Style::Bold);

    bool display_paragraph = false;

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Enter) {
                    cout << "Hit enter!" << endl;
                    display_paragraph = true;                
                } else if (event.key.code == sf::Keyboard::Backspace) {
                    cout << "Hit backspace!" << endl;
                    display_paragraph = false; 
                } else {
                    cout << "Keypress!" << endl;
                }
            }

            if (event.type == Event::Closed) {
                window.close();
                cout << "Window closed successfully!" << endl;
            }
        }

        window.clear(sf::Color::Blue);
        window.draw(heading);
        if (display_paragraph) {
            window.draw(paragraph);
        }
        window.display();
    }

    return 0;
}

