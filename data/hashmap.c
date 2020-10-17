//
// Created by Ran Liu on 10/16/2020.
//

#include <stdlib.h>
#include "hashmap.h"

HashNode* init_hash_node(unsigned int key, void *value, HashNode* next) {
    HashNode* result = (HashNode*) malloc(sizeof(HashNode));
    result->key = key;
    result->value = value;
    result->next = next;
    return result;
}

HashMap* init_hashmap(unsigned int size) {
    HashMap* result = (HashMap*) malloc(sizeof(HashMap));
    result->size = size;
    result->nodes = (HashNode**) malloc(sizeof(HashNode *) * size);
    for (int c = 0; c < size; c++) {
        result->nodes[c] = NULL;
    }
    return result;
}

void delete_hashmap(HashMap *map) {
    for (int c = 0; c < map->size; c++) {
        if (map->nodes[c] != NULL) {
            free(map->nodes[c]);
        }
    }
    free(map);
}

bool hashmap_contains(HashMap* map, unsigned int key) {
    unsigned int index = key % map->size;
    if (map->nodes[index] != NULL) {
        HashNode* current = map->nodes[index];
        while (current != NULL) {
            if (current->key == key) {
                return true;
            }
            current = current->next;
        }
    }
    return false;
}

void hashmap_insert(HashMap* map, unsigned int key, void* value) {
    unsigned int index = key % map->size;
    HashNode* new_node = init_hash_node(key, value, map->nodes[index]);
    map->nodes[index] = new_node;
}

void *hashmap_get(HashMap* map, unsigned int key) {
    unsigned int index = key % map->size;
    if (map->nodes[index] != NULL) {
        HashNode* current = map->nodes[index];
        while (current != NULL) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
    }
    return NULL;
}