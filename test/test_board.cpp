//
// Created by Ran Liu on 4/24/2020.
//

#include "gtest/gtest.h"

extern "C" {
#include "util/board.h"
}

TEST(test_board,test_board_init) {
    Board board = init_board();
    print_board(board);

    board.board_state[0][0] = X;
    print_board(board);
}

TEST(test_board,test_parser) {
    Coordinate coordinate = parse_move("a1");
    ASSERT_EQ(coordinate.x,0);
    ASSERT_EQ(coordinate.y,0);

    Coordinate coordinate1 = parse_move("b2");
    ASSERT_EQ(coordinate1.x,1);
    ASSERT_EQ(coordinate1.y,1);
}

TEST(test_board,test_valid_move) {
    Board board = init_board();
    ASSERT_EQ(valid_move((Coordinate){0,0},board), true);
    board = do_move((Coordinate){0,0},board);
    ASSERT_EQ(valid_move((Coordinate){0,0},board), false);

}

TEST(test_board,test_winner) {
    Board board = init_board();
    board.board_state[0][0] = O;
    board.board_state[1][0] = O;

    board.board_state[0][2] = X;
    board.board_state[1][2] = X;
    board.board_state[2][2] = X;
    print_board(board);

    int d = 2;
    ASSERT_EQ(board.board_state[0][d], board.board_state[1][d]);
    ASSERT_EQ(board.board_state[1][d], board.board_state[2][d]);
    ASSERT_TRUE(board.board_state[0][d] == board.board_state[1][d] && board.board_state[1][d] == board.board_state[2][d]);

    ASSERT_EQ(winner(board), X);

}

TEST(test_board,test_hash) {
    Board board = init_board();
    board.board_state[0][0] = O;
    board.board_state[1][0] = O;

    board.board_state[0][2] = X;
    board.board_state[1][2] = X;
    board.board_state[2][2] = X;

    printf("Hash: %d\n", hash_board(board));

    Board parsed_board = from_hash(hash_board(board));

    for (int c = 0; c < 3; c++) {
        for (int d = 0; d < 3; d++) {
            ASSERT_EQ(board.board_state[c][d], parsed_board.board_state[c][d]);
        }
    }
    print_board(parsed_board);

}