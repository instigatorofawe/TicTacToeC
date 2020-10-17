//
// Created by Ran Liu on 10/16/2020.
//

#include "gtest/gtest.h"


extern "C" {
#include "data/hashmap.h"
}

TEST(test_hashmap,test_init) {
    printf("HashNode size: %d\n", (int) sizeof(HashNode));
    printf("HashNode* size: %d\n", (int) sizeof(HashNode*));
    printf("HashMap size: %d\n", (int) sizeof(HashMap));

    HashMap* map = init_hashmap(16);
    delete_hashmap(map);
}