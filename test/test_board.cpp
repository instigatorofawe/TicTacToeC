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

}