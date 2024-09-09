/*     Basic Window in SFML      **
** icon, background, music, text */
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ClickObj
{
    private:
        sf::Sprite bgSprite;
        sf::Texture bgTexture;
        sf::Sound bgSound;
        sf::SoundBuffer bgBuffer;

        sf::Font text_font;
        sf::Text textName01;

        bool load_images();
        bool load_sounds();
        bool load_text();

    public:
        bool play_sound();
        bool load_assets();
        bool init_game();
        
        sf::Text draw_text();
        sf::Sprite draw_background();
};
