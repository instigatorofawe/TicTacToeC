//
// Created by Ran Liu on 4/22/2020.
//

#include <stdlib.h>
#include "game_tree.h"

GameTree *initialize_gametree(Board *board) {
    GameTree *tree = (GameTree*) malloc(sizeof(GameTree));
    tree->minimax = (Coordinate){0,0};
    tree->board = board;
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            tree->children[c][d] = NULL;
        }
    }
    return tree;
}

GameTree *create_gametree(Board *board) {
    // TODO
    return NULL;
}

void destroy_subtree(GameTree *tree) {
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            if (tree->children[c][d] != NULL) {
                destroy_subtree(tree->children[c][d]);
            }
        }
    }
    destroy_node(tree);
}

void destroy_node(GameTree *tree) {
    if (tree->board != NULL) {
        free(tree->board);
    }
    free(tree);
}