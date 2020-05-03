//
// Created by Ran Liu on 5/2/2020.
//

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
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

double compute_uct(MonteCarloTree *parent, MonteCarloTree *child, Player turn) {
    if (parent->visits == 0) {
        return 0;
    }
    if (child->visits == 0) {
        return 0;
    }
    return child->wins[turn]/child->visits + sqrt(2) * sqrt(log(parent->visits)/child->visits);
}

Coordinate monte_carlo_get_move(MonteCarloTree *root) {
    // Select node with highest total value
    Coordinate result = {0,0};
    int current_value = -1;
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            if (root->children[c][d] != NULL) {
                int value = compute_value(root->children[c][d], root->board.turn);
                if (value > current_value) {
                    current_value = value;
                    result = (Coordinate){c,d};
                }
            }
        }
    }
    return result;
}

/**
 *
 * @param root Pointer to root node of tree
 * @return Result of iteration
 */
Player monte_carlo_do_iteration(MonteCarloTree *root) {
    // Check if a player has won or the game has ended in a draw
    Player current_winner = winner(root->board);
    if (current_winner != Empty) {
        root->visits = root->visits + 1;
        if (current_winner != Draw) {
            root->wins[current_winner] = root->wins[current_winner] + 1;
        } else {
            root->draws = root->draws + 1;
        }
        return current_winner;
    }

    // Cycle through nodes, if one hasn't been visited, visit it.
    // Otherwise choose the node with the highest uct.
    double current_uct = 0;
    Coordinate highest = {-1,-1};

    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            if (root->children[c][d] == NULL && valid_move((Coordinate){c,d},root->board)) {
                root->children[c][d] = init_monte_carlo_tree(do_move((Coordinate){c,d},root->board));
                Player result = monte_carlo_do_iteration(root->children[c][d]);

                root->visits = root->visits + 1;
                if (result != Draw) {
                    root->wins[result] = root->wins[result] + 1;
                } else {
                    root->draws = root->draws + 1;
                }
                return result;
            } else if (root->children[c][d] != NULL){
                double uct = compute_uct(root, root->children[c][d], root->board.turn);
                if (uct > current_uct) {
                    highest = (Coordinate){c,d};
                }
            }
        }
    }

    Player result = monte_carlo_do_iteration(root->children[highest.x][highest.y]);

    root->visits = root->visits + 1;
    if (result != Draw) {
        root->wins[result] = root->wins[result] + 1;
    } else {
        root->draws = root->draws + 1;
    }
    return result;

    // Increment number of visits
}


