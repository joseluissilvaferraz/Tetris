#ifndef PIECE_H
#define PIECE_H

class Piece
{
private:
    int x;
    int y;
    int rotation;
    int type;
    int shape[4][4];

public:
    Piece();

    void generateRandom();
    void rotate();
    void moveLeft();
    void moveRight();
    void moveDown();

    int getX() const;
    int getY() const;
    int getType() const;        // estava declarado em piece.cpp mas faltava no .h
    int getRotation() const;    // idem
    int getCell(int r, int c) const;
};

#endif
