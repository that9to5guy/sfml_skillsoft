/* Basic Bounding boxes & collisions */
#include "BoundCollide.h"

bool BoundCollide::init_game()
{
    if (!load_text() | !load_sounds() | !load_images() | !load_sprites()) {
	  return false;		
	}

    musicSound.play();

    return true;
}

void BoundCollide::draw_windows(sf::RenderWindow &window)
{
    window.draw(bgSprite);
    window.draw(txtText);
    for(int i=0;i<5;i++) {
        window.draw(obSprite[i][0]);
    }
}

void BoundCollide::update_sprites() {
    if(obSprite[0][0].getPosition().y < 500.f && clock.getElapsedTime().asSeconds() > 0.03f) {
        for(int i=0;i<5;i++) { 
            obSprite[i][0].move(0.f,5.f);
        }
        clock.restart();
    }
    else if(obSprite[0][0].getPosition().y >= 500.f) {
        for(int i=0;i<5;i++) {
            obSprite[i][0].move(0.f,-400.f);
        }
    }
}

void BoundCollide::click_sound() {
    clickSound.play();
}

sf::Sprite BoundCollide::check_sprite(int n)
{
    return obSprite[n][0];
}
