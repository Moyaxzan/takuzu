//
// Created by Moyaxzan on 07/04/2022.
//

#ifndef TAKUZU_TAKUZU_H
#define TAKUZU_TAKUZU_H
#include "takuzu.c"

GRID create_grid(int size);
void display_grid(GRID grid);
int validity_move(int **grid, int size, MOVE move);

#endif //TAKUZU_TAKUZU_H
