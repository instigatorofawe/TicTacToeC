//
// Created by Ran Liu on 4/24/2020.
//

#ifndef TICTACTOEC_GAME_TREE_H
#define TICTACTOEC_GAME_TREE_H

#include "board.h"

typedef struct GameTree {
    Board board;
    struct GameTree *children[3][3];

    Coordinate solution; // Index of solution
    int minimax_values[2]; // Utility values for both players
} GameTree;

GameTree *create_gametree(Board board);
GameTree *init_gametree(Board board);
void delete_subtree(GameTree *root);
GameTree *gametree_do_move(Coordinate move, GameTree *root);

void solve_gametree_minimax(GameTree *root);
void solve_gametree_alpha_beta(GameTree *root, int alpha, int beta);

#endif //TICTACTOEC_GAME_TREE_H
