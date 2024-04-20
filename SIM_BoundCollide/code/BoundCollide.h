/* Basic Bounding boxes & collisions */
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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
        sf::Sprite cashSpr[2];
        sf::Sprite heartSpr[2];
        sf::Sprite starSpr[2];
        sf::Sprite lightSpr[2];
        sf::Sprite skullSpr[2];

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
        
        void draw_windows(sf::RenderWindow& window);
    
};
