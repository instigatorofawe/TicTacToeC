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
    delete_hashmap(map, true);
}

TEST(test_hashmap,test_function) {
    unsigned int hashes[] = {0, 1, 2, 3, 4, 5, 6, 18};
    int values[] = {0, 1, 2, 3, 4, 5, 6, 18};
    HashMap* map = init_hashmap(16);

    for (int c = 0; c < 6; c++) {
        ASSERT_FALSE(hashmap_contains(map, hashes[c]));
        hashmap_insert(map, hashes[c], &values[c]);
        ASSERT_TRUE(hashmap_contains(map, hashes[c]));
        ASSERT_EQ(*(int*)hashmap_get(map, hashes[c]), values[c]);
    }

    delete_hashmap(map, false);
}