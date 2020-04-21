#include <stdio.h>

#include "util/board.h"

int main() {

    struct Board *board = initialize_board();
    print_board(board);
    free(board);
}
