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