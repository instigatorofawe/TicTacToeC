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
    char *coordinate = "a1";
    struct Coordinate test_coordinate = parse_coordinate(coordinate);
}