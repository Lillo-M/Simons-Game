#include "main.h"

int main()
{
    std::cout << "inciando jogo" << std::endl;
    Game* game;
    game = Game::getInstance();
    if(game)
        delete game;
    game = NULL;
    return 0;
}