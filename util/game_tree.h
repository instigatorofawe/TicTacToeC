// Game tree data structure for minimax solver
// Created by Ran Liu on 4/22/2020.
//

#ifndef TICTACTOEC_GAME_TREE_H
#define TICTACTOEC_GAME_TREE_H

#include "board.h"
#include "game.h"

typedef struct GameTree {
    Coordinate minimax; // Index of minimax solution
    int value; // Value of minimax solution
    Board *board;
    struct GameTree *children[3][3]; // Children of tree
} GameTree;

GameTree *initialize_gametree(Board *board);
GameTree *create_gametree(Board *board); // Recursive creation of full game tree from current position

void destroy_subtree(GameTree *tree); // Recursively destructs subtree
void destroy_node(GameTree *tree); // Destroys current node only

#endif //TICTACTOEC_GAME_TREE_H
