// Ball class funcitons
#include "Ball.h"

std::vector<sf::Color> Ball::colors = {
        // Basic colors
        sf::Color::Red,
        sf::Color::Green,
        sf::Color::Blue,
        sf::Color::Yellow,
        sf::Color::Magenta,
        sf::Color::Cyan,
        // sf::Color::White,
        // sf::Color::Black,
        // sf::Color::Transparent,
        
        // Shades and variants
        sf::Color(255, 165, 0),  // Orange
        sf::Color(128, 0, 128),  // Purple
        sf::Color(255, 192, 203), // Pink
        // sf::Color(0, 255, 255),   // Aqua
        // sf::Color(255, 255, 0),   // Yellow
        sf::Color(0, 128, 0),     // Dark Green
        // sf::Color(0, 0, 128),     // Navy
        sf::Color(128, 128, 0),   // Olive
        sf::Color(128, 0, 0),     // Maroon
        // sf::Color(0, 0, 255),     // Pure Blue
        // sf::Color(0, 255, 0),     // Pure Green
        // sf::Color(255, 0, 255),   // Pure Purple
        sf::Color(255, 215, 0),   // Gold
        sf::Color(128, 128, 128), // Gray
        // sf::Color(165, 42, 42),   // Brown
        // sf::Color(0, 255, 127),   // Spring Green
        // sf::Color(218, 165, 32),  // Goldenrod
        // sf::Color(255, 0, 0, 128), // Red with transparency
        // sf::Color(0, 255, 255, 128), // Cyan with transparency
        // sf::Color(255, 0, 255, 128), // Magenta with transparency
        // sf::Color(255, 255, 0, 128), // Yellow with transparency
        // sf::Color(0, 128, 128, 128), // Teal with transparency
        // sf::Color(128, 0, 128, 128), // Purple with transparency
        // sf::Color(128, 128, 0, 128), // Olive with transparency
        // sf::Color(128, 0, 0, 128),   // Maroon with transparency
        // sf::Color(0, 0, 128, 128),   // Navy with transparency
    };

Ball::Ball(float radius) : shape(radius) {
    sf::Color ball_color = colors[rand() % colors.size()];
    shape.setFillColor(ball_color);
    shape.setOrigin(radius, radius); // Set origin to center of shape
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(2.f);

    float x = rand() % 800; // 800 is window width
    float y = rand() % 600; // 600 is window height
    shape.setPosition(x, y);
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
