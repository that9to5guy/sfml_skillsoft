#pragma once

#include <iostream>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Player
{
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        
        void initTexture();
        void initSprite();
        
    public:
        Player();
        virtual ~Player();

        void update();
        void render(sf::RenderTarget& target);
};