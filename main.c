#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "util/board.h"

int main() {
    int option;
    int arg;

    while (true) {
        printf("1. Single Player\n2. Multiplayer\n");
        arg = scanf("%d", &option);

        if (arg == 0) {
            printf("Invalid choice! Please enter a number.\n");
            continue;
        }

        switch (option) {
            case 1:
                printf("Not yet implemented!\n");
            case 2:

                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        if (false) {
            escape:
            break;
        }
    }

    struct Board *board = initialize_board();
    print_board(board);
    free(board);

    return 0;
}
