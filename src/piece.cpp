#include "piece.h"

#include <cstdlib>
#include <ctime>

Piece::Piece()
{
    x = 3;
    y = 0;
    rotation = 0;

    // BUG CORRIGIDO: srand() chamado a cada peça reiniciava o gerador,
    // causando sequências repetidas. Movido para generateRandom() com
    // flag estática para inicializar apenas uma vez.
    generateRandom();
}

void Piece::generateRandom()
{
    // Inicializa o semente apenas na primeira chamada
    static bool seeded = false;
    if (!seeded)
    {
        std::srand((unsigned)std::time(nullptr));
        seeded = true;
    }

    type = std::rand() % 7;

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            shape[i][j] = 0;

    switch(type)
    {
        // I
        case 0:
            shape[1][0] = 1;
            shape[1][1] = 1;
            shape[1][2] = 1;
            shape[1][3] = 1;
            break;

        // O
        case 1:
            shape[1][1] = 1;
            shape[1][2] = 1;
            shape[2][1] = 1;
            shape[2][2] = 1;
            break;

        // T
        case 2:
            shape[1][1] = 1;
            shape[0][2] = 1;
            shape[1][2] = 1;
            shape[2][2] = 1;
            break;

        // L
        case 3:
            shape[1][0] = 1;
            shape[1][1] = 1;
            shape[1][2] = 1;
            shape[2][2] = 1;
            break;

        // J
        case 4:
            shape[2][0] = 1;
            shape[2][1] = 1;
            shape[2][2] = 1;
            shape[1][2] = 1;
            break;

        // S
        case 5:
            shape[1][1] = 1;
            shape[2][1] = 1;
            shape[0][2] = 1;
            shape[1][2] = 1;
            break;

        // Z
        case 6:
            shape[0][1] = 1;
            shape[1][1] = 1;
            shape[1][2] = 1;
            shape[2][2] = 1;
            break;
    }
}

void Piece::rotate()
{
    int temp[4][4];

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            temp[j][3 - i] = shape[i][j];

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            shape[i][j] = temp[i][j];

    rotation = (rotation + 1) % 4;
}

void Piece::moveLeft()  { x--; }
void Piece::moveRight() { x++; }
void Piece::moveDown()  { y++; }

int Piece::getX() const        { return x; }
int Piece::getY() const        { return y; }
int Piece::getType() const     { return type; }
int Piece::getRotation() const { return rotation; }

int Piece::getCell(int row, int col) const
{
    return shape[row][col];
}
