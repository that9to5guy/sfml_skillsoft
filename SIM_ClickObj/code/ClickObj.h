/* Clicking on objects Mouse Actions in SFML */
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class ClickObj
{
    private:
        sf::Sound bgSound;
        sf::SoundBuffer bgBuffer;

        sf::Font text_font;
        sf::Text textName01;

        bool load_sounds();
        bool load_text();

    public:
        bool load_assets();
        bool init_game();

};
