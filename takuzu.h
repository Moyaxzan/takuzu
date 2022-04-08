//
// Created by Moyaxzan on 07/04/2022.
//

#ifndef TAKUZU_TAKUZU_H
#define TAKUZU_TAKUZU_H
#include "takuzu.c"

typedef struct
{
    int nb_row;
    int nb_column;
    int **tab;
} GRID;

int **create_grid(int size);

#endif //TAKUZU_TAKUZU_H
