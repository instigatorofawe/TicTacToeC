//
// Created by Ran Liu on 4/24/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "board.h"
#include "game_tree.h"

/**
 * Plays single player using minimax solver, either naive or alpha-beta pruning approach
 * @param root Root of game tree to use
 * @param resolve whether or not solver has to compute move each turn
 */
void play_singleplayer(GameTree *root, bool resolve) {
    Board board = init_board();
    char buffer[100];

    Player player = (Player) rand() % 2; // Which player
    printf("You are player %c. The computer is player %c.\n", player_to_char(player), player_to_char(opposite_player(player)));

    while (board_winner(board) == Empty) {
        print_board(board);

        // Human's turn.
        if (board.turn == player) {
            bool valid_input = false;
            while (!valid_input) {
                printf("Player %c's turn:", player_to_char(board.turn));
                fgets(buffer, sizeof(buffer), stdin);
                Coordinate move = parse_move(buffer);

                if (move.x == -1 || move.y == -1) {
                    printf("Invalid move! Format: a1-c3\n");
                } else if (board_valid_move(move, board)) {
                    board = board_do_move(move, board);
                    root = root->children[move.x][move.y];
                    valid_input = true;
                } else {
                    printf("Illegal move! Tile must be unoccupied.\n");
                }
            }
        } else {
            if (resolve) {
                solve_gametree_alpha_beta(root, -1, -1); // Solve using alpha beta pruning
            }
            printf("Computer move: %c%d\n", board_row_name(root->solution.x), root->solution.y+1);
            board = board_do_move(root->solution, board);
            root = root->children[root->solution.x][root->solution.y];
        }
    }

    print_board(board);
    if (board_winner(board) == Draw) {
        printf("Game ended in a draw!\n");
    } else {
        if (board_winner(board) == player) {
            printf("Human player won!\n"); // This should theoretically be impossible to reach
        } else {
            printf("Computer player won!\n");
        }
    }
}

void play_multiplayer() {
    Board board = init_board();
    char buffer[100];
    while (board_winner(board) == Empty) {
        print_board(board);
        bool valid_input = false;

        while (!valid_input) {
            printf("Player %c's turn:", player_to_char(board.turn));
            fgets(buffer, sizeof(buffer), stdin);
            Coordinate move = parse_move(buffer);

            if (move.x == -1 || move.y == -1) {
                printf("Invalid move! Format: a1-c3\n");
            } else if (board_valid_move(move, board)) {
                board = board_do_move(move, board);
                valid_input = true;
            } else {
                printf("Illegal move! Tile must be unoccupied.\n");
            }
        }
    }

    print_board(board);
    if (board_winner(board) == Draw) {
        printf("Game ended in a draw!\n");
    } else {
        printf("Player %c won!\n", player_to_char(board_winner(board)));
    }
}

void play_singleplayer_monte_carlo(int num_iterations) {
    Board board = init_board();

    char buffer[100];

    Player player = (Player) rand() % 2; // Which player
    printf("You are player %c. The computer is player %c.\n", player_to_char(player), player_to_char(opposite_player(player)));



    while (board_winner(board) == Empty) {
        print_board(board);

        // Human's turn.
        if (board.turn == player) {
            bool valid_input = false;
            while (!valid_input) {
                printf("Player %c's turn:", player_to_char(board.turn));
                fgets(buffer, sizeof(buffer), stdin);
                Coordinate move = parse_move(buffer);

                if (move.x == -1 || move.y == -1) {
                    printf("Invalid move! Format: a1-c3\n");
                } else if (board_valid_move(move, board)) {
                    board = board_do_move(move, board);
                    valid_input = true;
                } else {
                    printf("Illegal move! Tile must be unoccupied.\n");
                }
            }
        } else {
            MonteCarloTree *root = init_monte_carlo_tree(board);
            for (int c = 0; c < num_iterations; c++) {
                monte_carlo_do_iteration(root);
            }
            Coordinate move = monte_carlo_get_move(root);
            delete_monte_carlo_tree(root);

            printf("Computer move: %c%d\n", board_row_name(move.x), move.y+1);
            board = board_do_move(move, board);
        }
    }

    print_board(board);
    if (board_winner(board) == Draw) {
        printf("Game ended in a draw!\n");
    } else {
        if (board_winner(board) == player) {
            printf("Human player won!\n"); // This should theoretically be impossible to reach
        } else {
            printf("Computer player won!\n");
        }
    }


}
