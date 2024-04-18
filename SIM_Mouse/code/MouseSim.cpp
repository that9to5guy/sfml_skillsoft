/* Tracking Mouse Actions in SFML */
#include "MouseSim.h"

bool MouseSim::load_assets() {
    if (!load_bars() | !load_cirs() | !load_paragraph() | !load_sounds()) {
	  return false;		
	}
	return true;
}

bool MouseSim::load_cirs() {
    if(!circleButton.loadFromFile("../asset/CheckBox/circleButtons.png")) {
        return false;
    }
    return true;
}

bool MouseSim::load_bars() {
    if(!orangeBar1.loadFromFile("../asset/Bar/UI-88.png")) {
        return false;
    }

    if(!orangeBar2.loadFromFile("../asset/Bar/UI-89.png")) {
        return false;
    }

    if(!orangeBar3.loadFromFile("../asset/Bar/UI-90.png")) {
        return false;
    }

    if(!orangeBar4.loadFromFile("../asset/Bar/UI-91.png")) {
        return false;
    }

    if(!orangeBar5.loadFromFile("../asset/Bar/UI-92.png")) {
        return false;
    }

    if(!blueBar1.loadFromFile("../asset/Bar/UI-111.png")) {
        return false;
    }

    if(!blueBar2.loadFromFile("../asset/Bar/UI-112.png")) {
        return false;
    }

    if(!blueBar3.loadFromFile("../asset/Bar/UI-113.png")) {
        return false;
    }

    if(!blueBar4.loadFromFile("../asset/Bar/UI-114.png")) {
        return false;
    }

    if(!blueBar5.loadFromFile("../asset/Bar/UI-115.png")) {
        return false;
    }

    return true;
}

bool MouseSim::load_sounds() {
    if (!click_buffer.loadFromFile("../asset/audio/clickSound.mp3")) {
        return false;
	}
    click_sound.setBuffer(click_buffer);
    click_sound.setVolume(25.0f);
    return true;
}

bool MouseSim::load_paragraph() {
    if (!paragraph_font.loadFromFile("../asset/font/FjallaOne-Regular.ttf")) {
        return false;
    }

    paragraph.setFont(paragraph_font);
    paragraph.setString("Right Click / Left Click");
    paragraph.setPosition(sf::Vector2f(175.0f, 50.0f));
    paragraph.setCharacterSize(35);
    paragraph.setFillColor(sf::Color::Magenta);
    paragraph.setOutlineColor(sf::Color::White);
    paragraph.setOutlineThickness(5);
    //paragraph.setRotation(10);
    //paragraph.setStyle(sf::Text::Style::Italic | sf::Text::Style::Bold);
    return true;
}

bool MouseSim::init_game() {
    if (!load_assets()) {
	  return false;		
	}

    this->orangeBarSprites[0].setTexture(orangeBar1);
    this->orangeBarSprites[1].setTexture(orangeBar2);
    this->orangeBarSprites[2].setTexture(orangeBar3);
    this->orangeBarSprites[3].setTexture(orangeBar4);
    this->orangeBarSprites[4].setTexture(orangeBar5);
    this->blueBarSprites[0].setTexture(blueBar1);
    this->blueBarSprites[1].setTexture(blueBar2);
    this->blueBarSprites[2].setTexture(blueBar3);
    this->blueBarSprites[3].setTexture(blueBar4);
    this->blueBarSprites[4].setTexture(blueBar5);

    for(int i=0;i<5;i++){
        this->orangeBarSprites[i].setPosition(sf::Vector2f(50.0f,150.0f));
        this->orangeBarSprites[i].setScale(sf::Vector2f(0.4, 0.4f));
        this->blueBarSprites[i].setPosition(sf::Vector2f(350.0f,150.0f));
        this->blueBarSprites[i].setScale(sf::Vector2f(0.4, 0.4f));
    }

    this->circleSpriteO.setTexture(circleButton);
    this->circleSpriteO.setPosition(sf::Vector2f(100, 250));
    //this->circleSprite.setScale(sf::Vector2f(0.5, 0.5f));
    sf::Vector2u circleSpriteO_size = circleButton.getSize();
    sf::IntRect irectCharO(0, 0, circleSpriteO_size.x/8, circleSpriteO_size.y);
    this->circleSpriteO.setTextureRect(irectCharO);

    this->circleSpriteX.setTexture(circleButton);
    this->circleSpriteX.setPosition(sf::Vector2f(400, 250));
    //this->circleSprite.setScale(sf::Vector2f(0.5, 0.5f));
    sf::Vector2u circleSpriteX_size = circleButton.getSize();
    sf::IntRect irectCharX(7*circleSpriteX_size.x/8, 0, circleSpriteX_size.x/8, circleSpriteX_size.y);
    this->circleSpriteX.setTextureRect(irectCharX);
    
    return true;
}

sf::Sprite& MouseSim::drawOrangeBar(int on) {
    return orangeBarSprites[on];
}

sf::Sprite& MouseSim::drawBlueBar(int bn) {
    return blueBarSprites[bn];
}

sf::Sprite& MouseSim::drawCircleO(int cn) {
    sf::Vector2u circleSpriteO_size = circleButton.getSize();
    sf::IntRect irectCharO(0, 0, circleSpriteO_size.x/8, circleSpriteO_size.y);
    irectCharO.left = (circleSpriteO_size.x/8)*cn*2;
    circleSpriteO.setTextureRect(irectCharO);
    return circleSpriteO;
}

sf::Sprite& MouseSim::drawCircleX(int xn) {
    sf::Vector2u circleSpriteX_size = circleButton.getSize();
    sf::IntRect irectCharX(7*circleSpriteX_size.x/8, 0, circleSpriteX_size.x/8, circleSpriteX_size.y);
    irectCharX.left = (circleSpriteX_size.x/8)*((xn*2)+1);
    circleSpriteX.setTextureRect(irectCharX);
    return circleSpriteX;
}

sf::Text& MouseSim::drawPara() {
    return paragraph;
}

bool MouseSim::play_sound() {
    click_sound.play();
    return true;
}
