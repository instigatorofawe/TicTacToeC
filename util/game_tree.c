//
// Created by Ran Liu on 4/24/2020.
//

#include <stdlib.h>
#include "game_tree.h"

int gametree_num_nodes = 0;

GameTree *create_gametree(Board board) {
    GameTree *root = init_gametree(board);
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            if (board_valid_move((Coordinate) {c, d}, board)) {
                root->children[c][d] = create_gametree(board_do_move((Coordinate) {c, d}, board));
            }
        }
    }
    return root;
}

GameTree *create_gametree_hashed(Board board, HashMap* hash_map) {
    unsigned int board_hash = hash_board(board);
    if (hashmap_contains(hash_map, board_hash)) {
        return (GameTree*) hashmap_get(hash_map, board_hash);
    } else {
        GameTree *root = init_gametree(board);
        hashmap_insert(hash_map, board_hash, root);
        for (int c = 0; c < 3; c++) {
            for (int d = 0; d < 3; d++) {
                if (board_valid_move((Coordinate) {c, d}, board)) {
                    root->children[c][d] = create_gametree_hashed(board_do_move((Coordinate) {c, d}, board), hash_map);
                }
            }
        }
        return root;
    }
}

GameTree *init_gametree(Board board) {
    gametree_num_nodes++;
    GameTree *tree = (GameTree*) malloc(sizeof(GameTree));
    tree->board = board;
    tree->solution = (Coordinate) {-1,-1};
    tree->minimax_values[0] = -100;
    tree->minimax_values[1] = -100; // Sentinel value indicating the current node has not yet been solved
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            tree->children[c][d] = NULL;
        }
    }
    return tree;
}

void delete_subtree(GameTree *root) {
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            if (root->children[c][d] != NULL) {
                delete_subtree(root->children[c][d]);
            }
        }
    }
    free(root);
}

void solve_gametree_minimax(GameTree *root) {
    // Utility function: 1 for win, 0 for draw, -1 for loss

    // Check if node already solved. If solved, then we return.
    if (root->minimax_values[0] != -100 && root->minimax_values[1] != -100) {
        return;
    }

    // Base case: there are no valid moves, we return based on the board_winner in the current position
    if (board_winner(root->board) != Empty) {
        switch(board_winner(root->board)) {
            case X:
                root->minimax_values[0] = 1;
                root->minimax_values[1] = -1;
                break;
            case O:
                root->minimax_values[1] = 1;
                root->minimax_values[0] = -1;
                break;
            case Draw:
                root->minimax_values[0] = 0;
                root->minimax_values[1] = 0;
                break;
        }
    } else {
        // We recursively solve for the minimax solution
        for (int c = 0; c < 3; c++) {
            for (int d = 0; d < 3; d++) {
                if (root->children[c][d] != NULL) {
                    solve_gametree_minimax(root->children[c][d]);
                    if (root->children[c][d]->minimax_values[root->board.turn] >
                        root->minimax_values[root->board.turn]) {
                        root->solution = (Coordinate) {c,d};
                        root->minimax_values[0] = root->children[c][d]->minimax_values[0];
                        root->minimax_values[1] = root->children[c][d]->minimax_values[1];
                    }
                }
            }
        }
    }
}

GameTree *gametree_do_move(Coordinate move, GameTree *root) {
    GameTree *return_value = root->children[move.x][move.y];
    root->children[move.x][move.y] = NULL;
    delete_subtree(root);
    return return_value;
}

void solve_gametree_alpha_beta(GameTree *root, int alpha, int beta) {
    // Alpha: minimum assured value for player 1
    // Beta: minimum assured value for player 2
    // Utility function: 1 for win, 0 for draw, -1 for loss
    // Reset values
    root->solution = (Coordinate) {-1,-1};
    root->minimax_values[0] = -100;
    root->minimax_values[1] = -100; // Sentinel value indicating the current node has not yet been solved

    // Base case: there are no valid moves, we return based on the board_winner in the current position
    if (board_winner(root->board) != Empty) {
        switch(board_winner(root->board)) {
            case X:
                root->minimax_values[0] = 1;
                root->minimax_values[1] = -1;
                break;
            case O:
                root->minimax_values[1] = 1;
                root->minimax_values[0] = -1;
                break;
            case Draw:
                root->minimax_values[0] = 0;
                root->minimax_values[1] = 0;
                break;
            default:
                break;
        }
    } else {
        // We recursively solve for the minimax solution, and quit
        for (int c = 0; c < 3; c++) {
            for (int d = 0; d < 3; d++) {
                if (root->children[c][d] != NULL) {
                    solve_gametree_alpha_beta(root->children[c][d], alpha, beta);
                    if (root->children[c][d]->minimax_values[root->board.turn] >
                        root->minimax_values[root->board.turn]) {
                        root->solution = (Coordinate) {c,d};
                        root->minimax_values[0] = root->children[c][d]->minimax_values[0];
                        root->minimax_values[1] = root->children[c][d]->minimax_values[1];

                        // The only difference between this and naive minimax: bounding and pruning
                        if (root->board.turn == X) {
                            if (root->minimax_values[0] > alpha) {
                                alpha = root->minimax_values[0];
                            }
                            if (root->minimax_values[1] <= beta) {
                                return;
                            }
                        } else if (root->board.turn == O) {
                            if (root->minimax_values[1] > beta) {
                                beta = root->minimax_values[1];
                            }
                            if (root->minimax_values[0] <= alpha) {
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}

