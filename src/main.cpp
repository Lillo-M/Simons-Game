#include <iostream>


#include "../include/Game.h"

int main()
{
    std::cout << "inciando jogo" << std::endl;
    Game* game;
    game = Game::getInstance();
    game->~Game();
    game = NULL;
    return 0;
}
