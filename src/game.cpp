#include "game.h"

#include <iostream>

Game::Game()
{
    gameOver    = false;
    score       = 0;
    level       = 1;
    linesCleared = 0; // BUG CORRIGIDO: original usava "linesCleared" aqui mas o .h declarava "lines"

    spawnPiece();
}

void Game::run()
{
    while(!gameOver)
    {
        draw();

        char tecla;
        std::cin >> tecla;

        processInput(tecla);

        update();

        if(board.isGameOver())
            gameOver = true;
    }

    std::cout << "\nGAME OVER\n";
    std::cout << "Score: " << score << std::endl;
}

void Game::update()
{
    Piece temp = currentPiece;
    temp.moveDown();

    if(board.isCollision(temp))
    {
        lockPiece();
        board.clearLines();
        spawnPiece();
    }
    else
    {
        currentPiece.moveDown();
    }
}

void Game::draw()
{
    board.draw(currentPiece);

    std::cout << "\nScore : " << score;
    std::cout << "\nLevel : " << level;
    std::cout << "\nLinhas: " << linesCleared << std::endl;

    std::cout << "\nControles:\n";
    std::cout << "  A = esquerda\n";
    std::cout << "  D = direita\n";
    std::cout << "  S = descer\n";
    std::cout << "  W = girar\n";
    std::cout << "  Q = sair\n";
}

void Game::processInput(char input)
{
    Piece temp = currentPiece;

    switch(input)
    {
        case 'a': case 'A':
            temp.moveLeft();
            if(!board.isCollision(temp))
                currentPiece.moveLeft();
            break;

        case 'd': case 'D':
            temp.moveRight();
            if(!board.isCollision(temp))
                currentPiece.moveRight();
            break;

        case 's': case 'S':
            update();
            break;

        case 'w': case 'W':
            temp.rotate();
            if(!board.isCollision(temp))
                currentPiece.rotate();
            break;

        case 'q': case 'Q':
            gameOver = true;
            break;
    }
}

void Game::spawnPiece()
{
    currentPiece = Piece();
}

void Game::lockPiece()
{
    board.placePiece(currentPiece);
}

// BUG CORRIGIDO: os métodos abaixo (clearLines, moveLeft, moveRight,
// moveDown, rotatePiece, isGameOver) existiam em game.cpp mas NÃO
// estavam declarados em game.h — erro de compilação.
// Como não fazem parte da interface pública usada, foram REMOVIDOS.
// A lógica equivalente já está em processInput() e update().
