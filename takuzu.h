//
// Created by Moyaxzan on 07/04/2022.
//

#ifndef TAKUZU_TAKUZU_H
#define TAKUZU_TAKUZU_H
#include "takuzu.c"

GRID create_takuzu(int size);
void display_grid(GRID grid);
int validity_move(GRID grid, MOVE move);

#endif //TAKUZU_TAKUZU_H
