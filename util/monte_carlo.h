//
// Created by Ran Liu on 5/2/2020.
//

#ifndef TICTACTOEC_MONTE_CARLO_H
#define TICTACTOEC_MONTE_CARLO_H

#include "board.h"

typedef struct MonteCarloTree {
    Board board;
    struct MonteCarloTree *children[3][3];

    int visits;
    int wins[2];
    int draws;

} MonteCarloTree;

MonteCarloTree *init_monte_carlo_tree(Board board);
//MonteCarloTree *create_monte_carlo_tree(Board board);
void delete_monte_carlo_tree(MonteCarloTree *root);

double compute_value(MonteCarloTree *node, Player turn);
double compute_uct(MonteCarloTree *node, Player turn);
Coordinate monte_carlo_get_move(MonteCarloTree *root);
void monte_carlo_do_iteration(MonteCarloTree *root);

#endif //TICTACTOEC_MONTE_CARLO_H