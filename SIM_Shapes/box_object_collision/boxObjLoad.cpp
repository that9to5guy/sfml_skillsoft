/* Generating Basic Shapes & Bounds */
#include "boxObj.h"

bool boxObj::init_simu() {
    if (!load_sound() | !load_square() | !load_circle()) {
	  return false;		
	}
    return true;
}

bool boxObj::load_sound() {
    if (!click_buffer.loadFromFile("../clickSound.mp3")) {
        return false;
	}
    click_sound.setBuffer(click_buffer);
    click_sound.setVolume(50.0f);
    return true;
}

bool boxObj::load_square() {
    square.setSize(sf::Vector2f(600.f, 600.0f));
    square.setPosition(sf::Vector2f(300.0f, 300.0f));
    square.setOrigin(sf::Vector2f(300.0f, 300.0f));
    square.setFillColor(sf::Color::Transparent);
    square.setOutlineColor(sf::Color(150,150,50,255));
    square.setOutlineThickness(-5.0f);
    
    sqBounds = square.getGlobalBounds();
    return true;
}

bool boxObj::load_circle() {
    for(int i=0;i<BALLS;i++) {
        circle[i].setRadius(5.f);
        circle[i].setOrigin(sf::Vector2f(5.f, 5.f));
        circle[i].setPosition(sf::Vector2f((i+1)*20.0f, (1+i)*40.0f));
        circle[i].setFillColor(sf::Color(150,0,5*(i+1),255));
        velocitX[i] = 8.f;
        velocitY[i] = 0.f;
    }

    return true;
}

void boxObj::move_circle(int i) {
        circle[i].move(velocitX[i],velocitY[i]);
        cirBounds[i] = circle[i].getGlobalBounds();
        check_collision(i);
}

void boxObj::check_collision(int i) {
    if(sqBounds.intersects(cirBounds[i])) {
        if(cirBounds[i].left < sqBounds.left || 
            ((cirBounds[i].left + cirBounds[i].width) > (sqBounds.left + sqBounds.width))) {
            velocitX[i] = -velocitX[i];
            velocitX[i] > 0.f ? velocitX[i]+=0.5f : velocitX[i]-=0.5f;
            // click_sound.play();
        }
        if((cirBounds[i].top < sqBounds.top) ||
            ((cirBounds[i].top + cirBounds[i].height) > (sqBounds.top + sqBounds.height))) {
            velocitY[i] = -velocitY[i];
            velocitY[i] > 0.f ? velocitY[i]+=0.5f : velocitY[i]-=0.5f;
            // click_sound.play();
            }
    }
    else {
        velocitX[i] = -velocitX[i];
        velocitY[i] = -velocitY[i];
        // click_sound.play();
    }
}

void boxObj::draw_window(sf::RenderWindow& window) {
    window.draw(square);
    for(int i=0;i<BALLS;i++)
        window.draw(circle[i]);
}
