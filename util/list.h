//
// Created by Ran Liu on 5/3/2020.
//

#ifndef TICTACTOEC_LIST_H
#define TICTACTOEC_LIST_H

#include <stdbool.h>

typedef struct List{
    double values[9]; // Maximum length
    int length;
} List;

List init_list();
bool list_insert(double value, List* list);

#endif //TICTACTOEC_LIST_H
