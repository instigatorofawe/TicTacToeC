//
// Created by Ran Liu on 5/3/2020.
//

#include "gtest/gtest.h"

extern "C" {
#include "math.h"
#include "util/monte_carlo.h"
}

TEST(test_monte_carlo, test_allocation) {
    Board board = init_board();
    MonteCarloTree *root = init_monte_carlo_tree(board);
    monte_carlo_do_iteration(root);
    delete_monte_carlo_tree(root);
}

TEST(test_monte_carlo, test_do_iteration) {
    Board board = init_board();
    board.board_state[1][1] = X;
    board.board_state[0][1] = O;
    board.board_state[2][1] = X;
    board.board_state[2][2] = O;

    MonteCarloTree *root = init_monte_carlo_tree(board);
    for (int c = 0; c < 1000; c++) {
        monte_carlo_do_iteration(root);
    }
    delete_monte_carlo_tree(root);
}

TEST(test_monte_carlo, test_visit_count) {
    Board board = init_board();
    MonteCarloTree *root = init_monte_carlo_tree(board);
    monte_carlo_do_iteration(root);

    ASSERT_EQ(root->visits, 1);

    printf("Wins: %d, %d, Draws: %d, visits: %d\n", root->wins[0], root->wins[1], root->draws, root->visits);

    delete_monte_carlo_tree(root);
}

TEST(test_monte_carlo, test_infinity) {
    ASSERT_GT(INFINITY,0);
    ASSERT_EQ(INFINITY, INFINITY);
}

TEST(test_monte_carlo, test_uct) {
    Board board = init_board();
    MonteCarloTree *root = init_monte_carlo_tree(board);

    for(int c = 0; c < 1000; c++) {
        monte_carlo_do_iteration(root);
    }
    monte_carlo_get_move(root);



    delete_monte_carlo_tree(root);
}