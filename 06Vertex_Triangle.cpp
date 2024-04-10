/* Drawing Triangles using Vertex Arrays */

#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

using sf::RenderWindow;
using sf::VideoMode;
using sf::Event;

int main()
{
    RenderWindow window(VideoMode(1000, 500), "Vertex Arrays");

    // An array of 3 vertices that defines a triangle primitive
    sf::VertexArray triangle(sf::Triangles, 3);

    // Set position of the triangle points
    triangle[0].position = sf::Vector2f(957.0f, 50.0f);
    triangle[1].position = sf::Vector2f(600.0f, 100.0f);
    triangle[2].position = sf::Vector2f(900.0f, 300.0f);

    // Different colors for each point of the triangle
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Blue;
    triangle[2].color = sf::Color::Green;

    sf::Vertex triangle_strip[] = {
        sf::Vertex(sf::Vector2f(50.0f, 150.0f)),
        sf::Vertex(sf::Vector2f(200.0f, 100.0f)),
        sf::Vertex(sf::Vector2f(200.0f, 300.0f)),
        sf::Vertex(sf::Vector2f(400.0f, 100.0f)),
        sf::Vertex(sf::Vector2f(600.0f, 300.0f))
    };

    triangle_strip[0].color = sf::Color::Black;
    triangle_strip[1].color = sf::Color::Yellow;
    triangle_strip[2].color = sf::Color::Magenta;
    triangle_strip[3].color = sf::Color::Cyan;
    triangle_strip[4].color = sf::Color::Red;

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {

            if (event.type == Event::Closed) {
                window.close();
                cout << "Window closed successfully!" << endl;
            }
        }

        window.clear(sf::Color::White);
        window.draw(triangle_strip, 5, sf::TriangleStrip);
        window.draw(triangle);
        window.display();
    }

    return 0;
}

