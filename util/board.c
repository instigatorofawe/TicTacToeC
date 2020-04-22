//
// Created by Ran Liu on 4/21/2020.
//
#include "board.h"

#include <stdio.h>
#include <stdlib.h>

void print_board(const Board *board) {
    for (int c = 0; c < 3; c++) {
        printf("   |   |   \n");
        printf(" %c | %c | %c \n",board->board_state[c][0],board->board_state[c][1],board->board_state[c][2]);

        if (c != 2) {
            printf("___|___|___\n");
        } else {
            printf("   |   |   \n");
        }
    }
}

Board *initialize_board() {
    Board *new_board = (Board*) malloc(sizeof(Board));
    new_board->turn = 0; // X goes first, O goes second
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            new_board->board_state[c][d] = ' ';
        }
    }
    return new_board;
}

int winner(const Board *board) {
    // Check each row and column
    for (int c = 0; c < 3; c++) {
        if (board->board_state[c][0] == board->board_state[c][1] &&
            board->board_state[c][1] == board->board_state[c][2]) {
            if (board->board_state[c][0] == 'X') {
                return 0;
            } else if (board->board_state[c][0] == 'O') {
                return 1;
            }
        }
        if (board->board_state[0][c] == board->board_state[1][c] &&
             board->board_state[1][c] == board->board_state[2][c]) {
            if (board->board_state[0][c] == 'X') {
                return 0;
            } else if (board->board_state[0][c] == 'O') {
                return 1;
            }
        }
    }
    // Check diagonals
    if ((board->board_state[0][0] == board->board_state[1][1] && board->board_state[1][1] == board->board_state[2][2])
        || (board->board_state[0][2] == board->board_state[1][1] && board->board_state[1][1] == board->board_state[2][0])) {
        if (board->board_state[1][1] == 'X') {
            return 0;
        } else if (board->board_state[1][1] == 'O') {
            return 1;
        }
    }
    // Check if board is full, if so, then draw
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            if (board->board_state[c][d] == ' ') {
                return -1; // Sentinel value, no winner
            }
        }
    }
    return 2; // Draw
}