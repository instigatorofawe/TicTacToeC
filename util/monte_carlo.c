//
// Created by Ran Liu on 5/2/2020.
//

#include <stdlib.h>
#include "monte_carlo.h"

MonteCarloTree *init_monte_carlo_tree(Board board) {
    MonteCarloTree *result = (MonteCarloTree*) malloc(sizeof(MonteCarloTree));
    result->board = board;
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            result->children[c][d] = NULL;
        }
    }

    result->visits = 0;
    result->wins[0] = 0;
    result->wins[1] = 0;
    result->draws = 0;
    return result;
}

void delete_monte_carlo_tree(MonteCarloTree *root) {
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            if (root->children[c][d] != NULL) {
                delete_monte_carlo_tree(root->children[c][d]);
            }
        }
    }
    free(root);
}

double compute_value(MonteCarloTree *node, Player turn) {
    if (turn == X) {
        return 0.5 * node->draws + node->wins[0];
    } else {
        return 0.5 * node->draws + node->wins[1];
    }
}

double compute_uct(MonteCarloTree *node, Player turn) {
    return 0;
}

Coordinate monte_carlo_get_move(MonteCarloTree *root) {
    Coordinate result;
    return result;
}

void monte_carlo_do_iteration(MonteCarloTree *root) {

}


