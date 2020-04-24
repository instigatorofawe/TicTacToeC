#include <stdio.h>
#include <stdbool.h>

#include "util/game.h"

int main() {
    char option[100];
    int option_number;
    int arg;

    GameTree *root = create_gametree(init_board());
    solve_gametree(root); // Solve once upon initialization

    while (true) {
        printf("1. Single Player\n2. Multiplayer\n3. Exit\n");
        fgets(option, sizeof(option), stdin);
        arg = sscanf(option, "%d", &option_number);

        if (arg != 1) {
            printf("Invalid choice! Please enter a number.\n");
            continue;
        }

        switch (option_number) {
            case 1:
                play_singleplayer(root);
                break;
            case 2:
                play_multiplayer();
                break;
            case 3:
                goto escape;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        if (false) {
            escape:
            break;
        }
    }

    delete_subtree(root);

    return 0;
}
