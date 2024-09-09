/* Tracking Keys Actions in SFML */
#include "KeysSim.h"

using std::cout;
using std::endl;

bool KeysSim::load_images()
{
    if(!letterTexture.loadFromFile("../asset/GreenButtons.png")) {
        return false;
    }
    letterTexture_size = letterTexture.getSize();
    return true;
}

bool KeysSim::load_sprites()
{
    irectLetter[0].left = 0;
    irectLetter[0].top = 0;
    irectLetter[0].width = letterTexture_size.x/3;
    irectLetter[0].height = letterTexture_size.y/11;
    cout << irectLetter[0].left << endl;
    cout << irectLetter[0].top << endl;
    cout << irectLetter[0].width << endl;
    cout << irectLetter[0].height << endl;
    cout << letterTexture_size.x << endl;
    cout << letterTexture_size.y << endl;
    
    letterSprite[0].setTexture(letterTexture);
    letterSprite[0].setTextureRect(irectLetter[0]);
    letterSprite[0].setPosition(sf::Vector2f(200.f,200.f));
    letterSprite[0].setScale(2.f,2.f);
    letterSprite[0].setOrigin(8.f,8.f);
    return true;
}

bool KeysSim::load_sounds()
{
    if (!clickBuffer[0].loadFromFile("../asset/clickSound.wav")) {
        return false;
	}
    clickSound[0].setBuffer(clickBuffer[0]);
    clickSound[0].setVolume(100.f);

    if (!clickBuffer[1].loadFromFile("../asset/jump.wav")) {
        return false;
	}
    clickSound[1].setBuffer(clickBuffer[1]);
    clickSound[1].setVolume(100.f);

    if (!clickBuffer[2].loadFromFile("../asset/coin04.wav")) {
        return false;
	}
    clickSound[2].setBuffer(clickBuffer[2]);
    clickSound[2].setVolume(100.f);

    if (!clickBuffer[4].loadFromFile("../asset/Acute.wav")) {
        return false;
	}
    clickSound[4].setBuffer(clickBuffer[4]);
    clickSound[4].setVolume(100.f);
    // clickSound.setLoop(true);
    return true;
}

bool KeysSim::load_text()
{
    if (!txtFont.loadFromFile("../asset/Gluten-Medium.ttf")) {
        return false;
    }

    txtText.setFont(txtFont);
    txtText.setCharacterSize(35);
    txtText.setFillColor(sf::Color::White);
    txtText.setOutlineColor(sf::Color::Green);
    txtText.setOutlineThickness(2);
    // txtText.setRotation(10);
    // txtText.setLetterSpacing(2.0f);
    // txtText.setStyle(sf::Text::Style::Italic | sf::Text::Style::Bold);
    txtText.setString("K E Y B O A R D");
    // txtText.setOrigin(sf::Vector2f(136.f,17.f));
    txtText.setPosition(sf::Vector2f(250.f,30.f));
    return true;
}