/* Simulating Hues & Colors*/
#include "hues.h"

constexpr double PI = 3.14159265358979323846;

bool huesColor::init_simu() {
    if (!load_square() | !load_circle()) {
	  return false;		
	}

    r = g = b = 0;  // RGB values
    c = 1.0f;       // croma value
    m = 0.0f;       // value shifting
    hue = x = 0.0f; // hue value;
    flag = true;

    for(int i=0;i<360;i++) {
        create_rgbVector(i);
        hue += 1.0f;
    }
    hue = x = 0.0f; // hue value;

    return true;
}

void huesColor::create_rgbVector(int i) {
    float red,gre,blu;
    x = c * (1 - std::abs(std::fmod(hue/60.f,2)-1));
    if(hue>=0 && hue<60) {
        red=c; gre=x; blu=0;
    } else if (hue>=60 && hue<120) {
        red=x; gre=c; blu=0;
    } else if (hue>=120 && hue<180) {
        red=0; gre=c; blu=x;
    } else if (hue>=180 && hue<240) {
        red=0; gre=x; blu=c;
    } else if (hue>=240 && hue<300) {
        red=x; gre=0; blu=c;
    } else {
        red=c; gre=0; blu=x;
    }

    rgb[i].x = static_cast<int>((red+m)*255);
    rgb[i].y = static_cast<int>((gre+m)*255);
    rgb[i].z = static_cast<int>((blu+m)*255);
}

bool huesColor::load_square() {
    square.setSize(sf::Vector2f(500.f, 500.0f));
    square.setOrigin(sf::Vector2f(250.0f, 250.0f));
    square.setPosition(sf::Vector2f(400.0f, 300.0f));
    square.setFillColor(sf::Color::White);
    square.setOutlineColor(sf::Color::White);
    square.setOutlineThickness(-5.0f);
    
    sqBounds = square.getGlobalBounds();
    return true;
}

bool huesColor::load_circle() {
    for(int i=0;i<BALLS;i++) {
        velocitX[i] = 8.f;
        velocitY[i] = 6.f;
        theta_deg[i] = (360.0/BALLS)*i;
        theta_rad[i] = theta_deg[i]*PI/180.0;
        circle[i].setRadius(5.f);
        circle[i].setOrigin(sf::Vector2f(5.f, 5.f));
        circle[i].setPosition(sf::Vector2f(400.f+(150.f*cos(theta_rad[i])),300.f+(150.f*sin(theta_rad[i]))));
        // circle[i].setFillColor(sf::Color(200,0,5*(i+1),255));
        // circle[i].setFillColor(sf::Color::White);
        circle[i].setFillColor(sf::Color(rgb[i].x,rgb[i].y,rgb[i].z,255));
    }
    return true;
}

void huesColor::update_hue() {
    float red,gre,blu;
    x = c * (1 - std::abs(std::fmod(hue/60.f,2)-1));
    if(hue>=0 && hue<60) {
        red=c; gre=x; blu=0;
    } else if (hue>=60 && hue<120) {
        red=x; gre=c; blu=0;
    } else if (hue>=120 && hue<180) {
        red=0; gre=c; blu=x;
    } else if (hue>=180 && hue<240) {
        red=0; gre=x; blu=c;
    } else if (hue>=240 && hue<300) {
        red=x; gre=0; blu=c;
    } else {
        red=c; gre=0; blu=x;
    }

    hue += 1.0f;
    if(hue>=360.f) {
        hue -= 0.f;
        flag=false;
    }

    r = static_cast<int>((red+m)*255);
    g = static_cast<int>((gre+m)*255);
    b = static_cast<int>((blu+m)*255);
    
    square.setFillColor(sf::Color(r,g,b,255));
    if(flag) {
        std::cout << r << " - " << g << " - " << b << " = " << count++ <<std::endl;
    }
}

void huesColor::draw_window(sf::RenderWindow& window) {
    window.draw(square);
    for(int i=0;i<BALLS;i++) {
        window.draw(circle[i]);
        std::cout << rgb[i].x << " - " << rgb[i].y << " - " << rgb[i].z <<std::endl;
    }
}
