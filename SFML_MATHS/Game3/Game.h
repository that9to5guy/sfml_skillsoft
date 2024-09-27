# pragma once

#include "Player.h"

class Game
{
    private:
        sf::RenderWindow* window;
        
        bool endGame;

        void initWindow();
        void initVariables();

    public:
    // Constructors & Destructors
        Game();
        virtual ~Game();

    // Accessors

    // Modifiers

    // Functions
    void run();
    void update();
    void render();
};
