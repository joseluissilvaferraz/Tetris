# 🎮 Tetris em C++

Implementação do clássico jogo Tetris em C++ para terminal, com renderização em modo texto.

## 📋 Funcionalidades

- 7 tipos de peças (I, O, T, L, J, S, Z)
- Rotação e movimentação das peças
- Detecção de colisão
- Limpeza de linhas completas
- Placar com score, level e linhas

## 🕹️ Controles

| Tecla | Ação |
|-------|------|
| `A` | Mover para esquerda |
| `D` | Mover para direita |
| `S` | Descer mais rápido |
| `W` | Girar peça |
| `Q` | Sair do jogo |

## 🛠️ Como compilar e executar

### Pré-requisitos
- [MSYS2](https://www.msys2.org/) com g++ instalado (Windows)
- g++ com suporte a C++17

### Compilar

Abra o terminal **MSYS2 UCRT64** e execute:

```bash
g++ -std=c++17 -o Tetris.exe src/main.cpp src/game.cpp src/board.cpp src/piece.cpp
```

### Executar

```bash
./Tetris.exe
```

## 📁 Estrutura do projeto

```
Tetris_fixed/
├── src/
│   ├── main.cpp      # Ponto de entrada
│   ├── game.h/cpp    # Lógica principal do jogo
│   ├── board.h/cpp   # Tabuleiro e colisões
│   └── piece.h/cpp   # Peças e rotações
├── CMakeLists.txt
└── README.md
```

## 🐛 Bugs corrigidos

- `#include "Game.h"` com maiúsculo causava erro em Linux/Mac
- `srand()` chamado a cada peça gerava sequências repetidas
- Assinatura de `board.draw()` incompatível entre `.h` e `.cpp`
- Campo `linesCleared` declarado com nome diferente no header
- Métodos definidos em `game.cpp` sem declaração em `game.h`
- `system("cls")` substituído por escape ANSI portável
- Peça atual não era renderizada no tabuleiro

## 👨‍💻 Autor

[joseluissilvaferraz](https://github.com/joseluissilvaferraz)
