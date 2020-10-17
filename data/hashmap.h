//
// Created by Ran Liu on 10/16/2020.
//

#ifndef TICTACTOEC_HASHMAP_H
#define TICTACTOEC_HASHMAP_H

#include <stdbool.h>

typedef struct HashNode {
    unsigned int key;
    void *value;
    struct HashNode *next;
} HashNode;

typedef struct HashMap{
    unsigned int size;
    HashNode **nodes;
} HashMap;

HashNode* init_hash_node(unsigned int key, void* value, HashNode* next);
HashMap* init_hashmap(unsigned int size);
void delete_hashmap(HashMap *map, bool delete_values);

bool hashmap_contains(HashMap* map, unsigned int key);
void hashmap_insert(HashMap* map, unsigned int key, void* value);
void *hashmap_get(HashMap* map, unsigned int key);

#endif //TICTACTOEC_HASHMAP_H
