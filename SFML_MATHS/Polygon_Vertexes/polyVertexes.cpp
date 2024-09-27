#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace sf;
using namespace std;

// Define M_PI if it's not defined
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

std::vector<sf::Color> colors = {
        // Basic colors
        sf::Color::Red,
        sf::Color::Green,
        sf::Color::Blue,
        sf::Color::Yellow,
        sf::Color::Magenta,
        sf::Color::Cyan,
        
        // Shades and variants
        sf::Color(255, 165, 0),  // Orange
        sf::Color(128, 0, 128),  // Purple
        sf::Color(255, 192, 203), // Pink
        sf::Color(0, 128, 0),     // Dark Green
        sf::Color(128, 128, 0),   // Olive
        sf::Color(128, 0, 0),     // Maroon
        sf::Color(255, 215, 0),   // Gold
        sf::Color(128, 128, 128), // Gray
    };

int main() {
    // Create the main window
    RenderWindow window(VideoMode(800, 600), "SFML Polygon");

    // Get the number of sides from the user
    int sides;
    cout << "Enter the number of sides for the polygon (at least 3): ";
    cin >> sides;

    // Validate the number of sides
    if (sides < 3) {
        cerr << "A polygon must have at least 3 sides." << endl;
        return 1;
    }

    // Center and radius of the polygon
    Vector2f center(400.0f, 300.0f);
    float radius = 200.0f;

    srand(static_cast<unsigned int>(time(nullptr)));

    // Create the vertex array for a triangle strip
    VertexArray polygon(sf::TrianglesStrip, sides + 1); // Additional vertices for the strip

    // Calculate the vertices
    for (int i = 0; i < sides; ++i) {
        float angle = 2 * M_PI * i / sides;
        float x = center.x + radius * cos(angle);
        float y = center.y + radius * sin(angle);

        // Add vertices in a way that they form a strip
        polygon[i].position = Vector2f(x, y);
        cout << x << ":" << y << endl;
        // Initialize position randomly within the window bounds
        polygon[i].color = colors[rand() % colors.size()];
    }

    // Add the first vertex again to close the polygon properly
    polygon[sides].position = polygon[0].position;
    polygon[sides].color = sf::Color::Red;
    // polygon[sides + 1] = polygon[0]; // Close the strip

    // Main loop
    while (window.isOpen()) {
        // Process events
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // Clear the window
        window.clear(Color::Black);

        // Draw the polygon using sf::TrianglesStrip
        window.draw(polygon);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
