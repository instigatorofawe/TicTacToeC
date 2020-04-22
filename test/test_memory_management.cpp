//
// Created by Ran Liu on 4/22/2020.
//

#include "gtest/gtest.h"
#include <iostream>

using std::cout;
using std::endl;

extern "C" {
#include "util/game_tree.h"
}

TEST(test_memory_management, test_size) {
    GameTree *gameTree = initialize_gametree(NULL);
    cout << sizeof(GameTree[3][3]) << endl;
    cout << sizeof(GameTree*[3][3]) << endl;
    cout << sizeof(GameTree) << endl;
    cout << sizeof(Coordinate) << endl;
    destroy_node(gameTree);
}