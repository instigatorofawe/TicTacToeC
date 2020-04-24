//
// Created by Ran Liu on 4/24/2020.
//

#ifndef TICTACTOEC_PLAYER_H
#define TICTACTOEC_PLAYER_H

typedef enum Player {
    X = 0, O = 1, Empty = -1, Draw = 2
} Player;

Player opposite_player(Player player);

char player_to_char(Player player);

#endif //TICTACTOEC_PLAYER_H
