//
// Created by Moyaxzan on 07/04/2022.
//

#ifndef TAKUZU_TAKUZU_H
#define TAKUZU_TAKUZU_H
#define SIZE_M 8
#include <stdio.h>
#include <stdlib.h>
#include "takuzu.c"

int** create_grid(int size);
void display_grid(int size,int** grid_game);
int** get_grid_game(int size, int** empty_grid);
int verification(int size, int** grid_game);
int check_equality_rows(int size, int** grid_game);
int check_equality_columns(int size, int** grid_game);
int check_duplicate_rows(int size, int** grid_game);
int check_duplicate_columns(int size, int** grid_game);
int check_three_same_values(int size, int** grid_game);
int check_full_grid(int size, int** grid_game);
int Play();
/*int validity_move(int **grid, int size, MOVE move);*/

#endif //TAKUZU_TAKUZU_H