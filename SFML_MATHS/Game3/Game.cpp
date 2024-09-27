#include "Game.h"

// Private Functions
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800,600), "G A M E - 3", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initVariables()
{
    this->endGame = false;
}

// Constructors & Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

// Functions
void Game::run()
{
    while(this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

void Game::update()
{
    sf::Event event;
    while(this->window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::render()
{
    this->window->clear();

    //Draw the frame

    this->window->display();
    
}
