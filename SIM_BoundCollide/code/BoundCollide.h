/* Basic Bounding boxes & collisions */
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class BoundCollide 
{
    private:
        sf::Texture bgScene;
        sf::Texture cashTxr;
        sf::Texture heartTxr;
        sf::Texture starTxr;
        sf::Texture lightTxr;
        sf::Texture skullTxr;

        sf::Sprite bgSprite;
        sf::Sprite obSprite[5][2];

        sf::Font txtFont;
        sf::Text txtText;

        sf::SoundBuffer musicBuffer;
        sf::Sound       musicSound;
        sf::SoundBuffer clickBuffer;
        sf::Sound       clickSound;

        sf::Clock clock;

        bool load_images();
        bool load_sprites();
        bool load_sounds();
        bool load_text();

    public:
        bool init_game();
        void update_sprites();
        void click_sound();
        sf::Sprite check_sprite(int n);
        void draw_windows(sf::RenderWindow& window);
};
