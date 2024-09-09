/* Basic Bounding boxes & collisions */
#include "BoundCollide.h"

bool BoundCollide::load_images()
{
    if(!bgScene.loadFromFile("../assets/bgScene.jpg")) {
        return false;
    }
    if(!cashTxr.loadFromFile("../assets/sprite_01.png")) {
        return false;
    }
    if(!heartTxr.loadFromFile("../assets/sprite_02.png")) {
        return false;
    }
    if(!starTxr.loadFromFile("../assets/sprite_03.png")) {
        return false;
    }
    if(!lightTxr.loadFromFile("../assets/sprite_04.png")) {
        return false;
    }
    if(!skullTxr.loadFromFile("../assets/sprite_05.png")) {
        return false;
    }
    return true;
}

bool BoundCollide::load_sprites()
{
    bgSprite.setTexture(bgScene);
    //bgSprite.setScale(sf::Vector2f(0.5, 0.5f));

    sf::Vector2u sprite_sizes[5];
    sprite_sizes[0] = cashTxr.getSize();
    sprite_sizes[1] = heartTxr.getSize();
    sprite_sizes[2] = starTxr.getSize();
    sprite_sizes[3] = lightTxr.getSize();
    sprite_sizes[4] = skullTxr.getSize();

    sf::IntRect irect_obspr[5][2];
    for(int i=0,n=0;i<5;i++) {
        for(int k=0;k<2;k++) {
            irect_obspr[i][k].left   = k*sprite_sizes[i].x/2;
            irect_obspr[i][k].top    = 0;
            irect_obspr[i][k].width  = sprite_sizes[i].x/2;
            irect_obspr[i][k].height = sprite_sizes[i].y;
        }
    }

    for(int j=0;j<2;j++) {
        obSprite[0][j].setTexture(cashTxr);
        obSprite[0][j].setPosition(sf::Vector2f(100.f,100.f));
        obSprite[0][j].setScale(sf::Vector2f(0.75f,0.75f));
        obSprite[0][j].setTextureRect(irect_obspr[0][j]);
        obSprite[1][j].setTexture(heartTxr);
        obSprite[1][j].setPosition(sf::Vector2f(201.f,100.f));
        obSprite[1][j].setScale(sf::Vector2f(0.75f,0.75f));
        obSprite[1][j].setTextureRect(irect_obspr[1][j]);
        obSprite[2][j].setTexture(starTxr);
        obSprite[2][j].setPosition(sf::Vector2f(295.f,100.f));
        obSprite[2][j].setScale(sf::Vector2f(0.75f,0.75f));
        obSprite[2][j].setTextureRect(irect_obspr[2][j]);
        obSprite[3][j].setTexture(lightTxr);
        obSprite[3][j].setPosition(sf::Vector2f(390.f,100.f));
        obSprite[3][j].setScale(sf::Vector2f(0.75f,0.75f));
        obSprite[3][j].setTextureRect(irect_obspr[3][j]);
        obSprite[4][j].setTexture(skullTxr);
        obSprite[4][j].setPosition(sf::Vector2f(454.f,100.f));
        obSprite[4][j].setScale(sf::Vector2f(0.75f,0.75f));
        obSprite[4][j].setTextureRect(irect_obspr[4][j]);
    }

    // for(int i=0;i<5;i++) {
    //     diamondSprite[i].setTexture(diamonds);
    //     diamondSprite[i].setPosition(sf::Vector2f(700, 75*(i+1)));
    //     // diamondSprite[i].setScale(sf::Vector2f(0.5, 0.5f));
    //     sf::IntRect irectDiamond(i*diamonds_size.x/5, 0, diamonds_size.x/5, diamonds_size.y);
    //     diamondSprite[i].setTextureRect(irectDiamond);
    //}

    return true;
}

bool BoundCollide::load_sounds()
{
    if (!musicBuffer.loadFromFile("../assets/easy_cheesy.mp3")) {
        return false;
	}    
    if (!clickBuffer.loadFromFile("../assets/coin_single_001.mp3")) {
        return false;
	}
    musicSound.setBuffer(musicBuffer);
    musicSound.setVolume(20.0f);
    musicSound.setLoop(true);
    clickSound.setBuffer(clickBuffer);
    clickSound.setVolume(50.0f);
    return true;
}

bool BoundCollide::load_text()
{
    if (!txtFont.loadFromFile("../assets/Gluten-Regular.ttf")) {
        return false;
    }
    txtText.setFont(txtFont);
    txtText.setString("Bounds & Collisions");
    txtText.setPosition(sf::Vector2f(300.0f, 25.0f));
    txtText.setCharacterSize(35);
    txtText.setFillColor(sf::Color::White);
    txtText.setOutlineColor(sf::Color::Cyan);
    //txtText.setOrigin(50.0f,50.0f);
    txtText.setOutlineThickness(2);
    // txtText.setRotation(10);
    txtText.setLetterSpacing(2.0f);
    // txtText.setStyle(sf::Text::Style::Italic | sf::Text::Style::Bold);
    return true;
}
