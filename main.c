#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "util/board.h"
#include "util/game.h"

int main() {
    int option;
    int arg;

    while (true) {
        printf("1. Single Player\n2. Multiplayer\n3. Exit\n");
        arg = scanf("%d", &option);

        if (arg == 0) {
            printf("Invalid choice! Please enter a number.\n");
            continue;
        }

        switch (option) {
            case 1:
                play_singleplayer();
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

    return 0;
}
