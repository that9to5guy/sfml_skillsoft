/* Clicking on objects Mouse Actions in SFML */
#include "ClickObj.h"

sf::Text ClickObj::draw_text() {
    return textName01;
}

sf::Sprite ClickObj::draw_background() {
    return bgSprite;
}

sf::Sprite ClickObj::draw_coins(int n) {
    return coinSprite[n];
}

sf::Sprite ClickObj::draw_diamonds(int n) {
    return diamondSprite[n];
}

void ClickObj::draw_windows(sf::RenderWindow& window) {
    window.draw(bgSprite);
    window.draw(textName01);
    for(int i=0;i<4;i++) {
        window.draw(coinSprite[i]);
        window.draw(diamondSprite[i]);
    }
}

void ClickObj::buttonPress(sf::Vector2f pos, sf::RenderWindow &window) {
    static bool diamondFlag[4];
    sf::Vector2u diamonds_size = diamonds.getSize();
    for(int i=0;i<4;i++) {
        // Coins hit ?
        if(coinSprite[i].getGlobalBounds().contains(pos)) {
            coinCollect.play();
        }
        // Diamonds hit ?
        if(diamondSprite[i].getGlobalBounds().contains(pos)) {
            diamondPress.play();
            if(!diamondFlag[i]) {
                sf::IntRect irectDiamond(4*diamonds_size.x/5, 0, diamonds_size.x/5, diamonds_size.y);
                diamondSprite[i].setTextureRect(irectDiamond);
                diamondSprite[i].setScale(sf::Vector2f(0.95f, 0.95f));
                diamondFlag[i] = true;
            } else {
                sf::IntRect irectDiamond(i*diamonds_size.x/5, 0, diamonds_size.x/5, diamonds_size.y);
                diamondSprite[i].setTextureRect(irectDiamond);
                diamondSprite[i].setScale(sf::Vector2f(1.0f, 1.0f));
                diamondFlag[i] = false;
            }
        }
    }
}
