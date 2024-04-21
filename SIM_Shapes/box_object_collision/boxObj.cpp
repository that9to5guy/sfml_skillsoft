/* Generating Basic Shapes & Bounds */
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using std::cout;
using std::endl;

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Circle Shape Polygons", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Image game_icon;
    game_icon.loadFromFile("../abstractImg.png");
    window.setIcon(game_icon.getSize().x, game_icon.getSize().y, game_icon.getPixelsPtr());

    sf::Sound       click_sound;
    sf::SoundBuffer click_buffer;
    if (!click_buffer.loadFromFile("../clickSound.mp3")) {
        return false;
	}
    click_sound.setBuffer(click_buffer);
    click_sound.setVolume(50.0f);

    sf::CircleShape circle(5.0f);
    circle.setOrigin(sf::Vector2f(5.f, 5.f));
    circle.setPosition(sf::Vector2f(300.0f, 300.0f));
    circle.setFillColor(sf::Color::Red);
    // circle.setOutlineColor(sf::Color::Cyan);
    // circle.setOutlineThickness(-1.0f);
    sf::CircleShape circle2(5.0f);
    circle2.setOrigin(sf::Vector2f(5.f, 5.f));
    circle2.setPosition(sf::Vector2f(400.0f, 400.0f));
    circle2.setFillColor(sf::Color::Blue);

    sf::RectangleShape square;
    square.setSize(sf::Vector2f(600.f, 600.0f));
    square.setPosition(sf::Vector2f(300.0f, 300.0f));
    square.setOrigin(sf::Vector2f(300.0f, 300.0f));
    square.setFillColor(sf::Color::Transparent);
    square.setOutlineColor(sf::Color::Blue);
    square.setOutlineThickness(-5.0f);
    sf::FloatRect sqBounds = square.getGlobalBounds();
    
    float velocitX = 8.f;
    float velocitY = 0.f;
    
    float velocitXb = 0.f;
    float velocitYb = 8.f;

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        circle.move(velocitX,velocitY);
        circle2.move(velocitXb,velocitYb);

        sf::FloatRect cirBounds = circle.getGlobalBounds();
        sf::FloatRect cirBounds2 = circle2.getGlobalBounds();

        if(sqBounds.intersects(cirBounds)) {
            if(cirBounds.left < sqBounds.left || 
              ((cirBounds.left + cirBounds.width) > (sqBounds.left + sqBounds.width))) {
                velocitX = -velocitX;
                velocitX > 0.f ? velocitX+=0.5f : velocitX-=0.5f;
                click_sound.play();
                cout << velocitX << endl;
            }
            if((cirBounds.top < sqBounds.top) ||
              ((cirBounds.top + cirBounds.height) > (sqBounds.top + sqBounds.height))) {
                velocitY = -velocitY;
                velocitY > 0.f ? velocitY+=0.5f : velocitY-=0.5f;
                click_sound.play();
                cout << velocitY << endl;
              }
        }
        else {
            velocitX = -velocitX;
            velocitY = -velocitY;
            click_sound.play();
        }

        if(sqBounds.intersects(cirBounds2)) {
            if(cirBounds2.left < sqBounds.left || 
              ((cirBounds2.left + cirBounds2.width) > (sqBounds.left + sqBounds.width))) {
                velocitXb = -velocitXb;
                velocitXb > 0.f ? velocitXb+=0.5f : velocitXb-=0.5f;
                click_sound.play();
            }
            if((cirBounds2.top < sqBounds.top) ||
              ((cirBounds2.top + cirBounds2.height) > (sqBounds.top + sqBounds.height))) {
                velocitYb = -velocitYb;
                velocitYb > 0.f ? velocitYb+=0.5f : velocitYb-=0.5f;
                click_sound.play();
              }
        }
        else {
            velocitXb = -velocitXb;
            velocitYb = -velocitYb;
            click_sound.play();
        }

        window.clear(sf::Color::Black);
        window.draw(square);
        window.draw(circle);
        window.draw(circle2);
		window.display();
    }

    return 0;
}
