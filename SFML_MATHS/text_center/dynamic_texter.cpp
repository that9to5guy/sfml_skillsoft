#include "dynamic_texter.h"

using std::cout;
using std::endl;

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Dynamic Text");

    sf::Font heading_font;
    if (!heading_font.loadFromFile("../font/PressStart2P-Regular.ttf")) {
        std::cout << "Error loading font - PressStart2P-Regular.ttf" << std::endl;
        return -1;
    }
    sf::Text heading;
    heading.setFont(heading_font);
    heading.setString("Press KEYS");
    heading.setPosition(sf::Vector2f(400.f, 300.f));
    heading.setCharacterSize(25);
    heading.setFillColor(sf::Color::Red);
    heading.setOutlineColor(sf::Color::Blue);
    // heading.setOrigin(187.f,13.5f);
    heading.setOutlineThickness(1);
    sf::FloatRect box = heading.getLocalBounds();
    cout << heading.getLocalBounds().height << " : " << heading.getLocalBounds().width << endl;
    heading.setOrigin(box.width/2,box.height/2);

    sf::Sound click_sound;
    sf::SoundBuffer click_buffer;
    if (!click_buffer.loadFromFile("../audio/clickSound.wav")) {
        std::cout << "Error loading Audio file" << std::endl;
        return -1;
    }
    click_sound.setBuffer(click_buffer);
    click_sound.setVolume(25.0f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Space:
                        heading.setString("S P A C E B A R");
                        break;
                    case sf::Keyboard::Backspace:
                        heading.setString("B A C K S P A C E");
                        break;
                    case sf::Keyboard::Enter:
                        heading.setString("E N T E R");
                        break;
                    case sf::Keyboard::Escape:
                        heading.setString("E S C A P E");
                        break;
                    case sf::Keyboard::Tab:
                        heading.setString("T A B");
                        break;
                    case sf::Keyboard::Delete:
                        heading.setString("D E L E T E");
                        break;
                    case sf::Keyboard::Home:
                        heading.setString("H O M E");
                        break;
                    case sf::Keyboard::End:
                        heading.setString("E N D");
                        break;
                    case sf::Keyboard::PageUp:
                        heading.setString("P A G E - U P");
                        break;
                    case sf::Keyboard::PageDown:
                        heading.setString("P A G E - D O W N");
                        break;
                    case sf::Keyboard::RShift:
                        heading.setString("R - S H I F T");
                        break;
                    case sf::Keyboard::LShift:
                        heading.setString("L - S H I F T");
                        break;
                    case sf::Keyboard::RControl:
                        heading.setString("R - C T R L");
                            break;
                    case sf::Keyboard::LControl:
                        heading.setString("L - C T R L");
                        break;
                    case sf::Keyboard::RAlt:
                        heading.setString("R - A L T");
                        break;
                    case sf::Keyboard::LAlt:
                        heading.setString("L - A L T");
                        break;
                    default:
                        // Optionally handle other keys or do nothing
                        break;
                }
                box = heading.getLocalBounds();
                heading.setOrigin(box.width/2,box.height/2);
                cout << heading.getLocalBounds().height << " : " << heading.getLocalBounds().width << endl;
                click_sound.play();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(heading);
        window.display();
    }

    return 0;
}