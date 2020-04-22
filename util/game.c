//
// Created by Ran Liu on 4/21/2020.
//
#include "game.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void play_singleplayer() {
    printf("Not yet implemented!\n");
}


void play_multiplayer() {
    char coordinate_input[100];
    struct Board *board = initialize_board();

    while (winner(board) == -1) {
        // TODO alternate inputs, parse coordinates, apply to board, check validity (is square empty?)
        bool valid_input = false;
        print_board(board);

        while(!valid_input) {
            printf("Player %d's move:\n", board->turn + 1);
            fgets(coordinate_input, sizeof(coordinate_input), stdin);
            Coordinate parsed_coordinate = parse_coordinate(coordinate_input);

            if (parsed_coordinate.x == -1 || parsed_coordinate.y == -1 ||
                board->board_state[parsed_coordinate.x][parsed_coordinate.y] != ' ') {
                printf("Invalid move! Format: a1-c3\n");
            } else {
                if (board->turn == 0) {
                    board->turn = 1;
                    board->board_state[parsed_coordinate.x][parsed_coordinate.y] = 'X';
                } else {
                    board->turn = 0;
                    board->board_state[parsed_coordinate.x][parsed_coordinate.y] = 'O';
                }
                valid_input = true;
            }
        }
    }

    if (winner(board) != 2) {
        printf("Player %d wins!\n", winner(board) + 1);
    } else {
        printf("Game ended in a draw!\n");
    }

    free(board); // Deallocate memory
}

Coordinate parse_coordinate(const char *option) {
    Coordinate result = {0, 0};
    switch(option[0]) {
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
    switch(option[1]) {
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