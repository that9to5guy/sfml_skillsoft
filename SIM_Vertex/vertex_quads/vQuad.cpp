/* Quads using texture in vertex arrays*/

#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;

int main()
{
    RenderWindow window(VideoMode(850, 450), "Vertex Arrays");

    sf::Vertex quad[] = {
        sf::Vertex(sf::Vector2f(50.0f, 50.0f)),
        sf::Vertex(sf::Vector2f(800.0f, 100.0f)),
        sf::Vertex(sf::Vector2f(600.0f, 400.0f)),
        sf::Vertex(sf::Vector2f(30.0f, 200.0f))
    };

    // Define its texture area to be a 400x400 square starting at (100, 100)
    quad[0].texCoords = sf::Vector2f(100, 100);
    quad[1].texCoords = sf::Vector2f(500, 100);
    quad[2].texCoords = sf::Vector2f(500, 500);
    quad[3].texCoords = sf::Vector2f(100, 500);

    sf::Texture fiery;
    if (!fiery.loadFromFile("fiery.jpeg", sf::IntRect(0, 0, 800, 800))) {
        cout << "Error loading fiery texture file!" << endl;
        return -1;
    }

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();
                cout << "Window closed successfully!" << endl;
            }
        }

        window.clear(sf::Color::White);
        window.draw(quad, 4, sf::Quads, &fiery);
        window.display();
    }

    return 0;
}
