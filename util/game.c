//
// Created by Ran Liu on 4/21/2020.
//
#include "game.h"
#include "board.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Coordinate {
    int x;
    int y;
} Coordinate;

void play_singleplayer() {
    printf("Not yet implemented!\n");
}


void play_multiplayer() {

    struct Board *board = initialize_board();
    free(board);

}

Coordinate parse_coordinate(char *option) {

}