//
// Created by Ran Liu on 10/16/2020.
//

#ifndef TICTACTOEC_HASHMAP_H
#define TICTACTOEC_HASHMAP_H

typedef struct HashMap{

} HashMap;

typedef struct HashNode {
    int key;
    void *value;
} HashNode;

HashMap* init_hashmap();
HashNode* init_hashnode();

void hashmap_insert(int key, void* value);

#endif //TICTACTOEC_HASHMAP_H
