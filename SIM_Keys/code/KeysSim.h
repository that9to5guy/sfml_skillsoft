/* Tracking Keys Actions in SFML */
#pragma once
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class KeysSim
{
    private:
        sf::Texture letterTexture;
        sf::Sprite  letterSprite[26];
        sf::Vector2u letterTexture_size;
        sf::IntRect irectLetter[26];

        // sf::CircleShape circle;
        // sf::FloatRect circleBounds;

        sf::Font txtFont;
        sf::Text txtText;

        sf::SoundBuffer clickBuffer[5];
        sf::Sound       clickSound[5];

        // sf::Vector2f mousePosView;

        // float dist;
        // float perc;

        bool load_images();
        bool load_sprites();
        bool load_sounds();
        bool load_text();

    public:
        bool init_game();

        void play_sound(int n);
        
        // void update_mouse_pos(sf::RenderWindow &window);

        void draw_windows(sf::RenderWindow& window);
};
