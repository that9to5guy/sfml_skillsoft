#include "texter_clicker.h"

using std::cout;
using std::endl;

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Text Clicker");

    sf::Sound click_sound;
    sf::SoundBuffer click_buffer;
    if (!click_buffer.loadFromFile("../audio/clickSound.wav")) {
        std::cout << "Error loading Audio file" << std::endl;
        return -1;
    }
    click_sound.setBuffer(click_buffer);
    click_sound.setVolume(25.0f);

    sf::Sound true_sound;
    sf::SoundBuffer true_buffer;
    if (!true_buffer.loadFromFile("../audio/RetroEventAcute11.wav")) {
        std::cout << "Error loading Audio file" << std::endl;
        return -1;
    }
    true_sound.setBuffer(true_buffer);
    true_sound.setVolume(25.0f);


    sf::Font heading_font;
    if (!heading_font.loadFromFile("../font/PressStart2P-Regular.ttf")) {
        std::cout << "Error loading font - PressStart2P-Regular.ttf" << std::endl;
        return -1;
    }
    sf::Text heading;
    heading.setFont(heading_font);
    heading.setString("Press SPACE to start");
    heading.setPosition(sf::Vector2f(400.f, 100.f));
    heading.setCharacterSize(25);
    heading.setFillColor(sf::Color::Red);
    sf::FloatRect box = heading.getLocalBounds();
    heading.setOrigin(box.width/2,box.height/2);

    // Game loop
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (enGame) {
                heading.setString("Total Points : " + std::to_string(points) + "\n\nPress SPACE to restart");
                heading.setFillColor(sf::Color::Green);
                box = heading.getLocalBounds();
                heading.setOrigin(box.width/2,box.height/2);
                if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                    inGame = false;
                    enGame = false;
                    points = 0;
                    heading.setFillColor(sf::Color::Cyan);
                }
            }
            else if (!START) {
                if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                    START = true;
                    heading.setFillColor(sf::Color::Cyan);
                }
                else {
                    heading.setString("Press SPACE to start");
                    box = heading.getLocalBounds();
                    heading.setOrigin(box.width/2,box.height/2);
                }
            }
            else if (START && !inGame) {
                inGame = true;
                
                std::srand(static_cast<unsigned>(std::time(0))); // Seed random number generator

                // Select a random key-value pair
                auto randomIt = std::next(keyMappings.begin(), std::rand() % keyMappings.size());
                current_key = randomIt->first;
                heading.setString(randomIt->second);
                
                heading.setPosition(sf::Vector2f(400.f, 300.f));
                box = heading.getLocalBounds();
                heading.setOrigin(box.width/2,box.height/2);
            }
            else if (inGame && event.type == sf::Event::KeyPressed) { 
                if (event.key.code == current_key) {
                    inGame = false;
                    true_sound.play();
                    points++;
                }
                else {
                    click_sound.play();
                }
            }
        }

        // Spawn a new ball every second
        sf::Time elapsed = clock.getElapsedTime();
        if (elapsed.asSeconds() > 30) {
            enGame = true;
            std::cout << "Game Over" << std::endl;
            clock.restart(); // Restart the clock
        }

        window.clear(sf::Color::Black);
        window.draw(heading);
        window.display();
    }

    return 0;
}