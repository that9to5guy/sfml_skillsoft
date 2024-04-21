/* Doppler Effect on Music */
#include "Doppler.h"

bool DopplerRadio::load_images()
{
    // if(!bgScene.loadFromFile("../assets/bgScene.jpg")) {
    //     return false;
    // }
    if(!radioTexture.loadFromFile("../assets/radio.png")) {
        return false;
    }
    return true;
}

bool DopplerRadio::load_sprites()
{
    // bgSprite.setTexture(bgScene);
    //bgSprite.setScale(sf::Vector2f(0.5, 0.5f));
    radioSprite.setTexture(radioTexture);
    radioSprite.setOrigin(sf::Vector2f(50.f,37.5f));
    radioSprite.setPosition(sf::Vector2f(400.f,300.f));
    // radioSprite.setScale(sf::Vector2f(5.f, 5.f));

    // square.setSize(sf::Vector2f(450.f,450.f));
    circle.setRadius(225.f);
    circle.setOrigin(225.f,225.f);
    circle.setPosition(sf::Vector2f(400.f,300.f));
    circle.setFillColor(sf::Color::Blue);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(-2.f);
    circleBounds = circle.getGlobalBounds();
    return true;
}

bool DopplerRadio::load_sounds()
{
    if (!musicBuffer.loadFromFile("../assets/easy_cheesy.mp3")) {
        return false;
	}
    musicSound.setBuffer(musicBuffer);
    musicSound.setVolume(100.f);
    musicSound.setLoop(true);
    return true;
}

bool DopplerRadio::load_text()
{
    if (!txtFont.loadFromFile("../assets/Gluten-Medium.ttf")) {
        return false;
    }
    txtText.setFont(txtFont);
    txtText.setString("Doppler Effect");
    txtText.setPosition(sf::Vector2f(400.0f, 30.0f));
    txtText.setCharacterSize(35);
    txtText.setFillColor(sf::Color::Blue);
    txtText.setOutlineColor(sf::Color::White);
    txtText.setOrigin(sf::Vector2f(136.f,17.f));
    txtText.setOutlineThickness(2);
    // txtText.setRotation(10);
    // txtText.setLetterSpacing(2.0f);
    // txtText.setStyle(sf::Text::Style::Italic | sf::Text::Style::Bold);
    return true;
}
