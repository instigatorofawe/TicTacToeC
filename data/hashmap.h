//
// Created by Ran Liu on 10/16/2020.
//

#ifndef TICTACTOEC_HASHMAP_H
#define TICTACTOEC_HASHMAP_H

typedef struct HashNode {
    unsigned int key;
    void *value;
    struct HashNode *next;
} HashNode;

typedef struct HashMap{
    unsigned int size;
    HashNode **nodes;
} HashMap;

HashNode* init_hash_node();
HashMap* init_hashmap(unsigned int size);

void hashmap_insert(unsigned int key, void* value);

#endif //TICTACTOEC_HASHMAP_H
