#include <iostream>
#include <vector>
#include <cstdlib>   // for std::rand and std::srand
#include <ctime>     // for std::time
#include <SFML/Graphics.hpp>

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;

int get_random_number() {
    return std::rand() % 11; // Gives a number between 0 and 10
}

void update_rectangles(std::vector<sf::RectangleShape> &rectangles, std::vector<int> &retVec) {
    int rnum = get_random_number();
    ++retVec[rnum];

    for (int i = 0; i < 11; i++) {
        rectangles[i].setSize(sf::Vector2f(60.0f, static_cast<float>(retVec[i])));
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(0))); // Seed random number generator

    RenderWindow window(VideoMode(780, 600), "Drawing Graphs");

    std::vector<int> retVec(11, 0);

    std::vector<sf::RectangleShape> rectangles(11);
    for(int i = 0; i < 11; i++) {
        rectangles[i].setFillColor(sf::Color::Cyan);
        rectangles[i].setOutlineColor(sf::Color::White);
        rectangles[i].setOutlineThickness(-2.f);
        rectangles[i].setPosition(sf::Vector2f((10.f*(i+1)) + (60.0f*i), 50.0f));
        rectangles[i].setSize(sf::Vector2f(60.0f, 0.f)); // Start with height 0
    }

    bool drawing_flag = true;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        if(drawing_flag) {
            // Update logic
            update_rectangles(rectangles, retVec);

            // Drawing logic
            window.clear(sf::Color::Black);
            for(int i = 0; i < 11; i++) {
                window.draw(rectangles[i]);
                if(retVec[i]>500) {
                    drawing_flag = false;
                }
                // std::cout << retVec[i] << " ";
            }
            // std::cout << std::endl;
            window.display();
        }
        // Sleep to control frame rate
        // sf::sleep(sf::milliseconds(10)); // Optional sleep to reduce CPU usage
    }

    return 0;
}
