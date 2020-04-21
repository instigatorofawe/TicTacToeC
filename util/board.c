//
// Created by Ran Liu on 4/21/2020.
//

#include "board.h"

#include <stdio.h>
#include <stdlib.h>


typedef struct Board {
    int turn; // Whose turn it is
    char board_state[3][3]; // Pointer to board state
} Board;

void print_board(Board *board) {
    for (int c = 0; c < 3; c++) {
        printf("%c|%c|%c\n",board->board_state[c][0],board->board_state[c][1],board->board_state[c][2]);
        if (c != 2) {
            printf("-----\n");
        }
    }
}

Board *initialize_board() {
    Board *new_board = (Board*) malloc(sizeof(Board));
    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            new_board->board_state[c][d] = ' ';
        }
    }

    return new_board;
}

