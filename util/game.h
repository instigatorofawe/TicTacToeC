//
// Created by Ran Liu on 4/24/2020.
//

#ifndef TICTACTOEC_GAME_H
#define TICTACTOEC_GAME_H

#include "game_tree.h"
#include "monte_carlo.h"

void play_singleplayer(GameTree *root, bool resolve);
void play_singleplayer_monte_carlo(int num_iterations);
void play_multiplayer();

#endif //TICTACTOEC_GAME_H
