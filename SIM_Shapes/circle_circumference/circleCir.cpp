/* Generating Circles from Circumferences */
#include "circleCir.h"

constexpr double PI = 3.14159265358979323846;

bool circleCir::init_simu() {
    if (!load_sound() | !load_square() | !load_circle()) {
	  return false;		
	}
    return true;
}

bool circleCir::load_sound() {
    if (!click_buffer.loadFromFile("../clickSound.mp3")) {
        return false;
	}
    click_sound.setBuffer(click_buffer);
    click_sound.setVolume(50.0f);
    return true;
}

bool circleCir::load_square() {
    square.setSize(sf::Vector2f(600.f, 600.0f));
    square.setPosition(sf::Vector2f(300.0f, 300.0f));
    square.setOrigin(sf::Vector2f(300.0f, 300.0f));
    square.setFillColor(sf::Color::Black);
    square.setOutlineColor(sf::Color(150,150,50,255));
    square.setOutlineThickness(-5.0f);
    
    sqBounds = square.getGlobalBounds();
    return true;
}

bool circleCir::load_circle() {
    for(int i=0;i<BALLS;i++) {
        velocitX[i] = 8.f;
        velocitY[i] = 0.f;
        theta_deg[i] = (360.0/BALLS)*i;
        theta_rad[i] = theta_deg[i]*PI/180.0;
        circle[i].setRadius(5.f);
        circle[i].setOrigin(sf::Vector2f(5.f, 5.f));
        circle[i].setPosition(sf::Vector2f(300.f+(200.f*cos(theta_rad[i])),300.f+(200.f*sin(theta_rad[i]))));
        circle[i].setFillColor(sf::Color(200,0,50*(i+1),255));
        
    }

    return true;
}

void circleCir::draw_window(sf::RenderWindow& window) {
    window.draw(square);
    for(int i=0;i<BALLS;i++)
        window.draw(circle[i]);
}
