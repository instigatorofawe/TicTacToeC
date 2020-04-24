//
// Created by Ran Liu on 4/24/2020.
//

#include "gtest/gtest.h"

extern "C" {
#include "util/game_tree.h"
}

TEST(test_game_tree,test_creation) {

    Board board = init_board();
    GameTree *root = create_gametree(board);
    delete_subtree(root);

}

TEST(test_game_tree,test_solution) {

    Board board = init_board();
    GameTree *root = create_gametree(board);
    solve_gametree(root);

    root = gametree_do_move((Coordinate){0,0},root);
    delete_subtree(root);
}