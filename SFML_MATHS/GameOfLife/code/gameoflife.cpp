/* Game of life functions */
#include "gameoflife.h"

bool GameOfLife::init_game()
{
    if (!load_text() | !load_sounds() | !load_images() | !load_sprites()) {
	  return false;		
	}

    musicSound.play();

    return true;
}

bool GameOfLife::load_images()
{
    if(!white.loadFromFile("../assets/White.png")) {
        return false;
    }
    if(!yello.loadFromFile("../assets/Black.png")) {
        return false;
    }
    return true;
}

bool GameOfLife::load_sprites()
{
    wySprite[0].setTexture(white);
    wySprite[0].setOrigin(sf::Vector2f(16.f,16.f));
    wySprite[0].setPosition(sf::Vector2f(100.f,100.f));
    wySprite[1].setTexture(yello);    
    wySprite[1].setOrigin(sf::Vector2f(16.f,16.f));
    wySprite[1].setPosition(sf::Vector2f(200.f,100.f));

    return true;
}

bool GameOfLife::load_sounds()
{
    if (!musicBuffer.loadFromFile("../assets/game-music-loop-6.mp3")) {
        return false;
	}    
    if (!clickBuffer.loadFromFile("../assets/select-sound.mp3")) {
        return false;
	}
    musicSound.setBuffer(musicBuffer);
    musicSound.setVolume(20.0f);
    musicSound.setLoop(true);
    clickSound.setBuffer(clickBuffer);
    clickSound.setVolume(50.0f);
    return true;
}

bool GameOfLife::load_text()
{
    if (!txtFont.loadFromFile("../assets/Super-Feel.ttf")) {
        return false;
    }
    txtText.setFont(txtFont);
    txtText.setString("S T A R T");
    txtText.setPosition(sf::Vector2f(400.0f, 500.0f));
    txtText.setCharacterSize(35);
    txtText.setFillColor(sf::Color::White);
    sf::FloatRect box = txtText.getLocalBounds();
    std::cout << txtText.getLocalBounds().height << " : " << txtText.getLocalBounds().width << std::endl;
    txtText.setOrigin(box.width/2,box.height/2);
    // txtText.setOutlineColor(sf::Color::Cyan);
    //txtText.setOrigin(50.0f,50.0f);
    // txtText.setOutlineThickness(2);
    // txtText.setRotation(10);
    // txtText.setLetterSpacing(2.0f);
    // txtText.setStyle(sf::Text::Style::Italic | sf::Text::Style::Bold);
    return true;
}

void GameOfLife::draw_windows(sf::RenderWindow &window)
{
    window.draw(txtText);
    window.draw(wySprite[0]);
    window.draw(wySprite[1]);
}

void GameOfLife::click_sound()
{
    clickSound.play();
}

GameOfLife::GameOfLife()
{

}

GameOfLife::~GameOfLife()
{

}
