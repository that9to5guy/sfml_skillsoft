/* Heaader for game of life */
#pragma once

#include <iostream>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameOfLife
{
    private:
        sf::Texture white;
        sf::Texture yello;

        sf::Sprite wySprite[2];

        sf::Font txtFont;
        sf::Text txtText;

        sf::SoundBuffer musicBuffer;
        sf::Sound       musicSound;
        sf::SoundBuffer clickBuffer;
        sf::Sound       clickSound;

        bool load_images();
        bool load_sprites();
        bool load_sounds();
        bool load_text();

    public:
        bool init_game();
        void click_sound();
        void draw_windows(sf::RenderWindow& window);

        GameOfLife();
        virtual ~GameOfLife();

};