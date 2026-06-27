#include "game.h"   // BUG CORRIGIDO: original incluía "Game.h" com G maiúsculo
                    // — falha em sistemas case-sensitive (Linux/Mac)

int main()
{
    Game game;
    game.run();

    return 0;
}
