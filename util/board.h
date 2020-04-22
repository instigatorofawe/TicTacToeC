// Board logic
// Created by Ran Liu on 4/21/2020.
//

#ifndef TICTACTOEC_BOARD_H
#define TICTACTOEC_BOARD_H

typedef struct Board {
    int turn; // Whose turn it is
    char board_state[3][3]; // Board state
} Board;

Board *initialize_board();
void print_board(const Board *board);
int winner(const Board *board);

#endif //TICTACTOEC_BOARD_H
