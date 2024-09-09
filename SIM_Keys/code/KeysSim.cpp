/* Tracking Keys Actions in SFML */
#include "KeysSim.h"

bool KeysSim::init_game()
{
    if (!load_text() | !load_sounds() | !load_images() | !load_sprites()) {
	  return false;		
	}
    // musicSound.play();

    return true;
}

void KeysSim::play_sound(int n) {
    clickSound[n].play();
}

void KeysSim::draw_windows(sf::RenderWindow &window)
{
    window.draw(letterSprite[0]);
    // window.draw(radioSprite);
    // window.draw(txtText[0]);
    window.draw(txtText);
}
