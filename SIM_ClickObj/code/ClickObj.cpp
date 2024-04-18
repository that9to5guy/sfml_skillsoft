/* Clicking on objects Mouse Actions in SFML */
#include "ClickObj.h"

bool ClickObj::init_game() {
    if (!load_assets()) {
	  return false;		
	}
    
    bgSprite.setTexture(bgTexture);
    bgSprite.setScale(sf::Vector2f(0.5, 0.5f));

    bgSound.play();

    return true;
}

bool ClickObj::load_assets() {
    if (!load_sounds() | !load_text() | !load_images()) {
	  return false;		
	}
	return true;
}

bool ClickObj::load_images() {
    if(!bgTexture.loadFromFile("../assets/Background/Background_Blue.png")) {
        return false;
    }
    return true;
}

bool ClickObj::load_sounds() {
    if (!bgBuffer.loadFromFile("../audio/cozyMusic01.mp3")) {
        return false;
	}
    bgSound.setBuffer(bgBuffer);
    bgSound.setVolume(25.0f);
    bgSound.setLoop(true);
    return true;
}

bool ClickObj::load_text() {
    if (!text_font.loadFromFile("../fonts/Gluten-SemiBold.ttf")) {
        return false;
    }

    textName01.setFont(text_font);
    textName01.setString("Click The Buttons");
    textName01.setPosition(sf::Vector2f(300.0f, 50.0f));
    textName01.setCharacterSize(35);
    textName01.setFillColor(sf::Color::Cyan);
    textName01.setOutlineColor(sf::Color::Black);
    //textName01.setOrigin(50.0f,50.0f);
    textName01.setOutlineThickness(3);
    // textName01.setRotation(10);
    // textName01.setStyle(sf::Text::Style::Italic | sf::Text::Style::Bold);
    return true;
}

bool ClickObj::play_sound() {
    bgSound.play();
    return true;
}

sf::Text ClickObj::draw_text() {
    return textName01;
}

sf::Sprite ClickObj::draw_background() {
    return bgSprite;
}
