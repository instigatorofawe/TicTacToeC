//
// Created by Ran Liu on 4/24/2020.
//

#ifndef TICTACTOEC_BOARD_H
#define TICTACTOEC_BOARD_H

#include <stdbool.h>
#include "player.h"

typedef struct Board {
    Player turn; // Current player's turn
    Player board_state[3][3];
} Board;

typedef struct Coordinate {
    int x;
    int y;
} Coordinate;

Board init_board();
unsigned int hash_board(Board board);
Board board_from_hash(unsigned int hash);

bool board_valid_move(Coordinate move, Board starting_position);
Board board_do_move(Coordinate move, Board starting_position);
Player board_winner(Board board);
void print_board(Board board);

Coordinate parse_move(const char *move_str);
char board_row_name(int c);

#endif //TICTACTOEC_BOARD_H
