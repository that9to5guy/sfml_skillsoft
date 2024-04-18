/* Clicking on objects Mouse Actions in SFML */
#include "ClickObj.h"

bool ClickObj::init_game() {
    if (!load_assets()) {
	  return false;		
	}

    return true;
}

bool ClickObj::load_assets() {
    if (!load_sounds() | !load_text()) {
	  return false;		
	}
	return true;
}

bool ClickObj::load_sounds() {
    if (!bgBuffer.loadFromFile("../audio/cozyMusic01.mp3")) {
        return false;
	}
    bgSound.setBuffer(bgBuffer);
    bgSound.setVolume(50.0f);
    return true;
}

bool ClickObj::load_text() {
    if (!text_font.loadFromFile("../fonts/Gluten-Black.ttf")) {
        return false;
    }

    textName01.setFont(text_font);
    textName01.setString("Click The Buttons");
    // textName01.setPosition(sf::Vector2f(175.0f, 50.0f));
    // textName01.setCharacterSize(35);
    // textName01.setFillColor(sf::Color::Magenta);
    // textName01.setOutlineColor(sf::Color::White);
    // textName01.setOutlineThickness(5);
    // textName01.setRotation(10);
    // textName01.setStyle(sf::Text::Style::Italic | sf::Text::Style::Bold);
    return true;
}