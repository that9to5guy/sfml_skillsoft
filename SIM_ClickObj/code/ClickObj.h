/* Clicking on objects Mouse Actions in SFML */
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

static bool grassFlag;

class ClickObj
{
    private:
        sf::Sprite  bgSprite;
        sf::Texture bgTexture;

        sf::Sound coinCollect;
        sf::SoundBuffer coinCollectBuffer;
        sf::Sound diamondPress;
        sf::SoundBuffer diamondPressBuffer;
        sf::Sound bgSound;
        sf::SoundBuffer bgBuffer;
        sf::Sound grassSound;
        sf::SoundBuffer grassBuffer;

        sf::Font text_font;
        sf::Text textName01;
        sf::Font coin_font;
        sf::Text coinName01;

        sf::Texture diamonds;
        sf::Sprite  diamondSprite[5];
        sf::Texture coin01;
        sf::Texture coin03;
        sf::Texture coin09;
        sf::Texture coinVase;
        sf::Sprite  coinSprite[4];
        sf::Texture grass;
        sf::Sprite  grassPhone[2];

        bool load_images();
        bool load_sprites();
        bool load_sounds();
        bool load_text();

    public:
        bool play_sound();
        bool load_assets();
        bool init_game();
        
        sf::Text draw_text();
        sf::Sprite draw_background();
        sf::Sprite draw_coins(int n);
        sf::Sprite draw_diamonds(int n);
        sf::Sprite draw_grass(bool gf);

        void draw_windows(sf::RenderWindow& window);
        void buttonPress(sf::Vector2f pos, sf::RenderWindow &window);
};
