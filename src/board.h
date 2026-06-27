#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

class Board
{
public:
    static const int WIDTH  = 10;
    static const int HEIGHT = 20;

private:
    int grid[HEIGHT][WIDTH];

public:
    Board();

    // BUG CORRIGIDO: assinatura em board.h declarava draw(const Piece&)
    // mas board.cpp implementava draw() sem parâmetro — incompatibilidade
    // que impedia a compilação. A peça atual é desenhada em game.draw(),
    // então draw() no board não precisa de parâmetro.
    void draw(const Piece& currentPiece) const;

    bool isCollision(const Piece& piece) const;
    void placePiece(const Piece& piece);
    void clearLines();
    bool isGameOver() const;

    int  getCell(int row, int col) const;
    void setCell(int row, int col, int value);
};

#endif
