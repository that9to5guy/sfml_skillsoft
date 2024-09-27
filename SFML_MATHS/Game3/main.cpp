#include "Game.h"

// using namespace sf;

int main()
{
    std::srand(static_cast<unsigned>(std::time(0))); // Seed random number generator

    Game game;  // Init Game object

    game.run();

    return 0;
}
