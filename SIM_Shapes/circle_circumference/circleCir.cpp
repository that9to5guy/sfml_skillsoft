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
    r = g = b = 0;
    square.setSize(sf::Vector2f(600.f, 600.0f));
    square.setPosition(sf::Vector2f(300.0f, 300.0f));
    square.setOrigin(sf::Vector2f(300.0f, 300.0f));
    square.setFillColor(sf::Color(r,g,b,255));
    // square.setOutlineColor(sf::Color::White);
    // square.setOutlineThickness(-5.0f);
    
    sqBounds = square.getGlobalBounds();
    return true;
}

bool circleCir::load_circle() {
    for(int i=0;i<BALLS;i++) {
        velocitX[i] = 8.f;
        velocitY[i] = 6.f;
        theta_deg[i] = (360.0/BALLS)*i;
        theta_rad[i] = theta_deg[i]*PI/180.0;
        circle[i].setRadius(5.f);
        circle[i].setOrigin(sf::Vector2f(5.f, 5.f));
        circle[i].setPosition(sf::Vector2f(300.f+(150.f*cos(theta_rad[i])),300.f+(150.f*sin(theta_rad[i]))));
        // circle[i].setFillColor(sf::Color(200,0,5*(i+1),255));
        circle[i].setFillColor(sf::Color::White);
    }
    isCollided = false;
    return true;
}

void circleCir::move_circle(int i) {
        circle[i].move(velocitX[i],velocitY[i]);
        cirBounds[i] = circle[i].getGlobalBounds();
        check_collision(i);
}

void circleCir::check_collision(int i) {
    if(sqBounds.intersects(cirBounds[i])) {
        if(cirBounds[i].left < sqBounds.left || 
            ((cirBounds[i].left + cirBounds[i].width) > (sqBounds.left + sqBounds.width))) {
            velocitX[i] = -velocitX[i];
            // velocitY[i] = -velocitY[i];
            // velocitX[i] > 0.f ? velocitX[i]+=0.5f : velocitX[i]-=0.5f;
            // click_sound.play();
            isCollided = true;
        }
        if((cirBounds[i].top < sqBounds.top) ||
            ((cirBounds[i].top + cirBounds[i].height) > (sqBounds.top + sqBounds.height))) {
            // velocitX[i] = -velocitX[i];
            velocitY[i] = -velocitY[i];
            // velocitY[i] > 0.f ? velocitY[i]+=0.5f : velocitY[i]-=0.5f;
            // click_sound.play();
            isCollided = true;
            }
    }
    else {
        velocitX[i] = -velocitX[i];
        velocitY[i] = -velocitY[i];
        // click_sound.play();
        isCollided = true;
    }
    if(isCollided) {
        isCollided = false;
        // r++;
        if(r++>255) {
            r = 0;
            // g++;
            if(g++>255) {
                g = 0;
                // b++;
                if(b++>255) {
                    b=0;
                }
            }
        }
        square.setFillColor(sf::Color(r,g,b,255));
        click_sound.play();
        // std::cout << r << "-" << g << "-" << b << std::endl;
    }
}

void circleCir::draw_window(sf::RenderWindow& window) {
    window.draw(square);
    for(int i=0;i<BALLS;i++)
        window.draw(circle[i]);
}
