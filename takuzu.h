//
// Created by Moyaxzan on 07/04/2022.
//

#ifndef TAKUZU_TAKUZU_H
#define TAKUZU_TAKUZU_H
#include "takuzu.c"

int create_grid(int size);
void display_grid(int size,int grid_game[size][size]);
int get_grid_game(int size,int solution[size][size], int mask[size][size], int empty_grid[size][size]);
int verification(int size, int grid_game[size][size]);
int check_equality_rows(int size, int grid_game[size][size]);
int check_equality_columns(int size, int grid_game[size][size]);
int check_duplicate_rows(int size, int grid_game[size][size]);
int check_duplicate_columns(int size, int grid_game[size][size]);
int check_three_same_values(int size, int grid_game[size][size]);
/*int validity_move(int **grid, int size, MOVE move);*/

#endif //TAKUZU_TAKUZU_H