//
// Created by Ran Liu on 4/24/2020.
//

#include <stdio.h>
#include "board.h"

/**
 * Initializes a board to default state
 * @return
 */
Board init_board() {
    Board board;
    board.turn = X;
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++ )
            board.board_state[c][d] = Empty;
    }
    return board;
}

unsigned int hash_board(Board board) {
    unsigned int hash = 0;
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            hash = hash * 3;

            switch (board.board_state[c][d]) {
                case Empty:
                    hash += 0;
                    break;
                case X:
                    hash += 1;
                    break;
                case O:
                    hash += 2;
                    break;
                default:
                    break;
            }
        }
    }
    return hash;
}

Board board_from_hash(unsigned int hash) {
    Board board;
    int n_empty = 9;
    for (int c = 2; c >= 0; c--) {
        for (int d = 2; d >= 0; d--) {
            switch (hash % 3) {
                case 0:
                    board.board_state[c][d] = Empty;
                    break;
                case 1:
                    board.board_state[c][d] = X;
                    n_empty--;
                    break;
                case 2:
                    board.board_state[c][d] = O;
                    n_empty--;
                    break;
                default:
                    break;
            }
            hash = hash / 3;
        }
    }
    if (n_empty % 2 == 0) {
        board.turn = O;
    } else {
        board.turn = X;
    }
    return board;
}

bool board_valid_move(Coordinate move, Board starting_position) {
    // If there is no board_winner, then the move is valid if the square is empty
    if (board_winner(starting_position) == Empty) {
        return (starting_position.board_state[move.x][move.y] == Empty);
    }
    return false; // If there is a board_winner, no moves are valid
}

Board board_do_move(Coordinate move, Board starting_position) {
    starting_position.board_state[move.x][move.y] = starting_position.turn;
    starting_position.turn = opposite_player(starting_position.turn);
    return starting_position;
}

void print_board(Board board) {
    printf("  1   2   3\n");
    for (int c = 0; c < 3; c++) {
        printf("    |   |\n");
        printf("%c %c | %c | %c\n", board_row_name(c), player_to_char(board.board_state[c][0]),
                player_to_char(board.board_state[c][1]), player_to_char(board.board_state[c][2]));
        if (c != 2) {
            printf(" ___|___|___\n");
        } else {
            printf("    |   |\n");
        }
    }
}

Coordinate parse_move(const char *move_str) {
    Coordinate result = {0, 0};
    switch(move_str[0]) {
        case 'a':
            result.x = 0;
            break;
        case 'b':
            result.x = 1;
            break;
        case 'c':
            result.x = 2;
            break;
        default:
            result.x = -1; // Sentinel value
            break;
    }
    switch(move_str[1]) {
        case '1':
            result.y = 0;
            break;
        case '2':
            result.y = 1;
            break;
        case '3':
            result.y = 2;
            break;
        default:
            result.y = -1;
            break;
    }
    return result;
}

Player board_winner(Board board) {
    // Check each row and column
    for (int c = 0; c < 3; c++) {
        if (board.board_state[c][0] == board.board_state[c][1] &&
            board.board_state[c][1] == board.board_state[c][2] &&
            board.board_state[c][0] != Empty) {
            return board.board_state[c][0];
        }
        if (board.board_state[0][c] == board.board_state[1][c] &&
            board.board_state[1][c] == board.board_state[2][c] &&
            board.board_state[0][c] != Empty) {
            return board.board_state[0][c];
        }
    }
    // Check diagonals
    if (board.board_state[0][0] == board.board_state[1][1] &&
        board.board_state[1][1] == board.board_state[2][2] &&
        board.board_state[0][0] != Empty) {
        return board.board_state[0][0];
    }
    if (board.board_state[0][2] == board.board_state[1][1] &&
        board.board_state[1][1] == board.board_state[2][0] &&
        board.board_state[0][2] != Empty) {
        return board.board_state[0][2];
    }

    // Check if board is full, if so, then draw.
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            if (board.board_state[c][d] == Empty) {
                return Empty; // Empty squares are available, there is no board_winner.
            }
        }
    }
    return Draw;
}

char board_row_name(int c) {
    switch (c) {
        case 0:
            return 'a';
        case 1:
            return 'b';
        case 2:
            return 'c';
        default:
            return ' ';
    }
}
