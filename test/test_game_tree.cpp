//
// Created by Ran Liu on 4/24/2020.
//

#include "gtest/gtest.h"

extern "C" {
#include "util/game_tree.h"
}

TEST(test_game_tree,test_node_size) {
    printf("Board: %d bytes\n", (int)sizeof(Board));
    printf("GameTree: %d bytes\n", (int)sizeof(GameTree));
}

TEST(test_game_tree,test_creation) {
    Board board = init_board();
    GameTree *root = create_gametree(board);
    delete_subtree(root);
}

TEST(test_game_tree,test_hash_creation) {
    Board board = init_board();
    HashMap *map = init_hashmap(4096);
    GameTree *root = create_gametree_hashed(board, map);
    solve_gametree_minimax(root);
    delete_hashmap(map, true);

    extern unsigned int gametree_num_nodes;
    printf("# of nodes: %d\n", gametree_num_nodes);
}

TEST(test_game_tree,test_solution) {
    Board board = init_board();
    GameTree *root = create_gametree(board);

    solve_gametree_minimax(root);

    root = gametree_do_move((Coordinate){0,0},root);
    delete_subtree(root);
}

TEST(test_game_tree,test_alpha_beta) {
    Board board = init_board();
    GameTree *root = create_gametree(board);

    solve_gametree_alpha_beta(root, -1, -1);

    root = gametree_do_move((Coordinate){0,0},root);
    delete_subtree(root);
}