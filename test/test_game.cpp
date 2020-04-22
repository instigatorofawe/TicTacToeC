//
// Created by Ran Liu on 4/22/2020.
//

#include "gtest/gtest.h"
#include <iostream>

using std::cout;
using std::endl;

// Prevent C++ from name mangling
extern "C" {
#include "util/game.h"
}

TEST(test_game, coordinate_parse_test) {
    char coordinate[] = "b1";
    Coordinate test_coordinate = parse_coordinate(coordinate);
    ASSERT_EQ(test_coordinate.x, 1);
    ASSERT_EQ(test_coordinate.y, 0);

    strcpy(coordinate, "c2");
    test_coordinate = parse_coordinate(coordinate);
    ASSERT_EQ(test_coordinate.x, 2);
    ASSERT_EQ(test_coordinate.y, 1);

    strcpy(coordinate, "z5");
    test_coordinate = parse_coordinate(coordinate);
    ASSERT_EQ(test_coordinate.x, -1);
    ASSERT_EQ(test_coordinate.y, -1);
}