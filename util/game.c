//
// Created by Ran Liu on 4/21/2020.
//
#include "game.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>

void play_singleplayer() {
    printf("Not yet implemented!\n");
}


void play_multiplayer() {
    char coordinate_input[100];
    struct Board *board = initialize_board();

    while (winner(board) == -1) {
        // TODO alternate inputs, parse coordinates, apply to board, check validity (is square empty?)
        printf("Player %d's move:\n", board->turn);
        gets(coordinate_input);
        Coordinate parsed_coordinate = parse_coordinate(coordinate_input);


    }

    printf("Player %d wins!\n", winner(board));

    free(board); // Deallocate memory
}

Coordinate parse_coordinate(char *option) {
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