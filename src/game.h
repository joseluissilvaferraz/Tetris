#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "piece.h"

class Game
{
private:
    Board board;
    Piece currentPiece;

    bool gameOver;

    int score;
    int level;
    int linesCleared; // BUG CORRIGIDO: campo usado em game.cpp mas declarado
                      // como "lines" no .h original — causava erro de compilação

public:
    Game();

    void run();
    void update();
    void draw();
    void processInput(char key);

private:
    void spawnPiece();
    void lockPiece();
};

#endif
