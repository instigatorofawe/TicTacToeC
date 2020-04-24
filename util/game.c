//
// Created by Ran Liu on 4/24/2020.
//

#include <stdio.h>
#include "game.h"
#include "board.h"

void play_singleplayer() {
    printf("Not yet implemented!\n");
}

void play_multiplayer() {
    Board board = init_board();
    char buffer[100];
    while (winner(board) == Empty) {
        print_board(board);
        bool valid_input = false;

        while (!valid_input) {
            printf("Player %c's turn:", player_to_char(board.turn));
            fgets(buffer, sizeof(buffer), stdin);
            Coordinate move = parse_move(buffer);

            if (move.x == -1 || move.y == -1) {
                printf("Invalid move! Format: a1-c3\n");
            } else {
                board = do_move(move, board);
                valid_input = true;
            }
        }
    }

    print_board(board);
    if (winner(board) == Draw) {
        printf("Game ended in a draw!\n");
    } else {
        printf("Player %c won!\n", player_to_char(winner(board)));
    }
}
