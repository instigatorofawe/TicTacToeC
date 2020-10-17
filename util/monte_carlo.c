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

double monte_carlo_compute_uct(MonteCarloTree *parent, MonteCarloTree *node, Player turn) {
//    printf("Computing uct for:\n");
//    print_board(child->board);
//    printf("Turn: %c, visits: %d, %d\n", player_to_char(turn), parent->visits, child->visits);

    if (parent->visits == 0) {
        return 0;
    }
    if (node->visits == 0) {
        return 0;
    }
    return (double)(node->wins[turn]) / node->visits + sqrt(2) * sqrt(log(parent->visits) / node->visits);
}

Coordinate monte_carlo_get_move(MonteCarloTree *root) {
    // Select node with highest total value
    Coordinate result = {0,0};
    double current_value = -1;
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            if (root->children[c][d] != NULL) {
                double value = (0.5*root->children[c][d]->draws + root->children[c][d]->wins[root->board.turn])/root->children[c][d]->visits;
//                printf("UCT of node %d,%d: %f\n",c,d,monte_carlo_compute_uct(root,root->children[c][d], root->board.turn));
//                printf("Win rate of node %d,%d: %f, %d w / %d d / %d\n",c,d,value, root->children[c][d]->wins[root->board.turn], root->children[c][d]->draws, root->children[c][d]->visits);
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
    if (root == NULL) {
        printf("Null root!\n");
    }
    Player current_winner = board_winner(root->board);
    if (current_winner != Empty) {
//        printf("Terminal node: \n");
//        print_board(root->board);
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
    double current_uct = -1;
    Coordinate highest = {-1,-1};

    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            if (root->children[c][d] == NULL && board_valid_move((Coordinate) {c, d}, root->board)) {
//                printf("Unvisited node:\n");
//                print_board(board_do_move((Coordinate){c,d},root->board));
                root->children[c][d] = init_monte_carlo_tree(board_do_move((Coordinate) {c, d}, root->board));
                Player result = monte_carlo_do_iteration(root->children[c][d]);

                root->visits = root->visits + 1;
                if (result != Draw) {
                    root->wins[result] = root->wins[result] + 1;
                } else {
                    root->draws = root->draws + 1;
                }
                return result;
            } else if (root->children[c][d] != NULL){
                double uct = monte_carlo_compute_uct(root, root->children[c][d], root->board.turn);
//                printf("UCT value: %f\n", uct);
                if (uct > current_uct) {
                    highest = (Coordinate){c,d};
                    current_uct = uct;
                }
            }
        }
    }
//    printf("Highest UCT at %d, %d\n", highest.x, highest.y);
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


