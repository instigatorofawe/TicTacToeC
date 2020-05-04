//
// Created by Ran Liu on 5/3/2020.
//

#include "list.h"

bool list_insert(double value, List* list) {
    if (list->length < 9) {
        list->values[list->length] = value;
        list->length++;
        return true;
    }
    return false;
}

int list_length() {
    return 0;
}

List init_list() {
    List result;
    result.length = 0;
    return result;
}
