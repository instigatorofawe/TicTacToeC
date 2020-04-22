// Game tree data structure for minimax solver
// Created by Ran Liu on 4/22/2020.
//

#ifndef TICTACTOEC_GAME_TREE_H
#define TICTACTOEC_GAME_TREE_H

#include "board.h"
#include "game.h"

typedef struct GameTree {
    Coordinate minimax; // Index of minimax solution
    Board *board;
    struct GameTree *children[3][3]; // Children of tree
} GameTree;

GameTree *initialize_gametree(Board *board);

void destroy_subtree(GameTree *tree); // Recursively destructs subtree
void destroy_node(GameTree *tree); // Destroys

#endif //TICTACTOEC_GAME_TREE_H
