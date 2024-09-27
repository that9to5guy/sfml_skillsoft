#include "Ball.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Spawn Balls");
    window.setFramerateLimit(60); // Limit to 60 frames per second

    std::vector<Ball> balls;

    // Initialize position randomly within the window bounds
    srand(static_cast<unsigned int>(time(nullptr)));

    // Game loop
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Spawn a new ball every second
        sf::Time elapsed = clock.getElapsedTime();
        if (elapsed.asSeconds() > 0.01) {
            balls.emplace_back(20.f); // Create a new ball
            clock.restart(); // Restart the clock
            std::cout << balls.size() << std::endl;
        }

        // Draw all balls
        window.clear(); // Clear the window (comment out to not clear)
        for (auto& ball : balls) {
            ball.draw(window);
        }
        window.display(); // Display everything drawn
    }

    return 0;
}
