//
// Created by Ran Liu on 4/24/2020.
//

#include "player.h"

Player opposite_player(Player player) {
    switch(player) {
        case X:
            return O;
        case O:
            return X;
        default:
            return Empty;
    }
}

char player_to_char(Player player) {
    switch(player) {
        case X:
            return 'X';
        case O:
            return 'O';
        default:
            return ' ';
    }
}
