// Game logic
// Created by Ran Liu on 4/21/2020.
//

#ifndef TICTACTOEC_GAME_H
#define TICTACTOEC_GAME_H

void play_singleplayer();
void play_multiplayer();

typedef struct Coordinate {
    int x;
    int y;
} Coordinate;

Coordinate parse_coordinate(const char *option);

#endif //TICTACTOEC_GAME_H
