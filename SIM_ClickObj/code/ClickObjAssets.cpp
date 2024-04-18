/* Clicking on objects Mouse Actions in SFML */
#include "ClickObj.h"

bool ClickObj::init_game() {
    if (!load_assets()) {
	  return false;		
	}
    if (!load_sprites()) {
	  return false;		
	}

    bgSound.play();

    return true;
}

bool ClickObj::load_sprites() {
    bgSprite.setTexture(bgTexture);
    bgSprite.setScale(sf::Vector2f(0.5, 0.5f));

    coinSprite[0].setTexture(coin01);
    coinSprite[0].setPosition(sf::Vector2f(100, 250));
    coinSprite[1].setTexture(coin03);
    coinSprite[1].setPosition(sf::Vector2f(200, 250));
    coinSprite[2].setTexture(coin09);
    coinSprite[2].setPosition(sf::Vector2f(300, 300));
    coinSprite[3].setTexture(coinVase);
    coinSprite[3].setPosition(sf::Vector2f(400, 400));

    sf::Vector2u grass_size = grass.getSize();
    sf::IntRect irectDiamond0(0, 0, grass_size.x/2, grass_size.y);
    sf::IntRect irectDiamond1(grass_size.x/2, 0, grass_size.x/2, grass_size.y);
    grassPhone[0].setTexture(grass);
    grassPhone[0].setPosition(sf::Vector2f(500, 175));
    grassPhone[0].setOrigin(40.75f,46.5);
    grassPhone[0].setTextureRect(irectDiamond0);
    grassPhone[1].setTexture(grass);
    grassPhone[1].setPosition(sf::Vector2f(500, 175));
    grassPhone[1].setOrigin(40.75f,46.5);
    grassPhone[1].setTextureRect(irectDiamond1);
    grassPhone[1].setScale(sf::Vector2f(0.9f, 0.9f));

    sf::Vector2u diamonds_size = diamonds.getSize();
    for(int i=0;i<5;i++) {
        diamondSprite[i].setTexture(diamonds);
        diamondSprite[i].setPosition(sf::Vector2f(700, 75*(i+1)));
        // diamondSprite[i].setScale(sf::Vector2f(0.5, 0.5f));
        sf::IntRect irectDiamond(i*diamonds_size.x/5, 0, diamonds_size.x/5, diamonds_size.y);
        diamondSprite[i].setTextureRect(irectDiamond);
    }

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
    if(!coin01.loadFromFile("../assets/Reward/Coin-1.png")) {
        return false;
    }
    if(!coin03.loadFromFile("../assets/Reward/Coin-3.png")) {
        return false;
    }
    if(!coin09.loadFromFile("../assets/Reward/Coin-9.png")) {
        return false;
    }
    if(!coinVase.loadFromFile("../assets/Reward/Flower-vase.png")) {
        return false;
    }
    if(!diamonds.loadFromFile("../assets/Collectibles/diamondColors01.png")) {
        return false;
    }
    if(!grass.loadFromFile("../assets/MenuButtons/grassPhone.png")) {
        return false;
    }
    return true;
}

bool ClickObj::load_sounds() {
    if (!bgBuffer.loadFromFile("../audio/cozyMusic01.mp3")) {
        return false;
	}
    if (!coinCollectBuffer.loadFromFile("../audio/coinCollect.mp3")) {
        return false;
	}
    if (!diamondPressBuffer.loadFromFile("../audio/clickSound.mp3")) {
        return false;
	}    
    if (!grassBuffer.loadFromFile("../audio/retrobeep.mp3")) {
        return false;
	}
    bgSound.setBuffer(bgBuffer);
    bgSound.setVolume(20.0f);
    bgSound.setLoop(true);
    coinCollect.setBuffer(coinCollectBuffer);
    coinCollect.setVolume(75.0f);
    diamondPress.setBuffer(diamondPressBuffer);
    diamondPress.setVolume(75.0f);    
    grassSound.setBuffer(grassBuffer);
    grassSound.setVolume(25.0f);
    return true;
}

bool ClickObj::load_text() {
    if (!text_font.loadFromFile("../fonts/Gluten-SemiBold.ttf")) {
        return false;
    }
    if (!coin_font.loadFromFile("../fonts/Gluten-Light.ttf")) {
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

    coinName01.setFont(coin_font);
    coinName01.setString("Coins : ");
    coinName01.setPosition(sf::Vector2f(50.0f, 50.0f));
    coinName01.setCharacterSize(25);
    coinName01.setFillColor(sf::Color::White);
    coinName01.setOutlineColor(sf::Color::Magenta);
    coinName01.setOutlineThickness(5);
    return true;
}

bool ClickObj::play_sound() {
    bgSound.play();
    return true;
}
