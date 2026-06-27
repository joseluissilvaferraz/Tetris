#include "board.h"

#include <iostream>

Board::Board()
{
    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            grid[i][j] = 0;
}

void Board::draw(const Piece& currentPiece) const
{
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[H";
#endif

    for(int i = 0; i < HEIGHT; i++)
    {
        std::cout << "|";

        for(int j = 0; j < WIDTH; j++)
        {
            // Verifica se a peça atual ocupa esta célula
            bool isPiece = false;
            int pi = i - currentPiece.getY();
            int pj = j - currentPiece.getX();

            if(pi >= 0 && pi < 4 && pj >= 0 && pj < 4)
                if(currentPiece.getCell(pi, pj))
                    isPiece = true;

            if(isPiece)
                std::cout << "[]";        // peça caindo
            else if(grid[i][j] != 0)
                std::cout << "##";        // peça fixada
            else
                std::cout << " .";        // célula vazia
        }

        std::cout << " |" << std::endl;
    }

    std::cout << " ----------------------" << std::endl;
}

bool Board::isCollision(const Piece& piece) const
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(piece.getCell(i, j))
            {
                int x = piece.getX() + j;
                int y = piece.getY() + i;

                if(x < 0 || x >= WIDTH)
                    return true;

                if(y >= HEIGHT)
                    return true;

                if(y >= 0 && grid[y][x] != 0)
                    return true;
            }
        }
    }

    return false;
}

void Board::placePiece(const Piece& piece)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(piece.getCell(i, j))
            {
                int x = piece.getX() + j;
                int y = piece.getY() + i;

                if(y >= 0)
                    grid[y][x] = 1;
            }
        }
    }
}

void Board::clearLines()
{
    for(int i = HEIGHT - 1; i >= 0; i--)
    {
        bool full = true;

        for(int j = 0; j < WIDTH; j++)
        {
            if(grid[i][j] == 0)
            {
                full = false;
                break;
            }
        }

        if(full)
        {
            for(int k = i; k > 0; k--)
                for(int j = 0; j < WIDTH; j++)
                    grid[k][j] = grid[k - 1][j];

            for(int j = 0; j < WIDTH; j++)
                grid[0][j] = 0;

            i++; // reavalia a mesma linha após descer as de cima
        }
    }
}

bool Board::isGameOver() const
{
    for(int j = 0; j < WIDTH; j++)
        if(grid[0][j] != 0)
            return true;

    return false;
}

int Board::getCell(int row, int col) const
{
    return grid[row][col];
}

void Board::setCell(int row, int col, int value)
{
    grid[row][col] = value;
}
