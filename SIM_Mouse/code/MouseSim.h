/* Tracking Mouse Actions in SFML */
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MouseSim
{
    private:
        sf::Texture orangeBar1;
        sf::Texture orangeBar2;
        sf::Texture orangeBar3;
        sf::Texture orangeBar4;
        sf::Texture orangeBar5;
        //    sf::Texture blueBar[5]; Not feasible as loadFromFile will need diff paths
        sf::Texture blueBar1;
        sf::Texture blueBar2;
        sf::Texture blueBar3;
        sf::Texture blueBar4;
        sf::Texture blueBar5;
        sf::Texture circleButton;    
    
        sf::Sprite orangeBarSprites[5];
        sf::Sprite blueBarSprites[5];
        sf::Sprite circleSpriteO;
        sf::Sprite circleSpriteX;

        sf::Font paragraph_font;
        sf::Text paragraph;
        sf::Sound click_sound;
        sf::SoundBuffer click_buffer;

        bool load_bars();
        bool load_cirs();
        bool load_paragraph();
        bool load_sounds();

    public:
        bool load_assets();
        bool init_game();
        bool play_sound();

        sf::Sprite& drawOrangeBar(int n);
        sf::Sprite& drawBlueBar(int n);
        sf::Sprite& drawCircleO(int n);
        sf::Sprite& drawCircleX(int n);
        sf::Text& drawPara();
};



