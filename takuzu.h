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
int** get_grid_game(int size, int** solution_grid, int** mask_grid);
int** create_random_mask(int size);
int verification(int size, int** grid_game);
int half_filled_array(int size, int tab[SIZE_M]);
int half_filled_column(int size, int** grid_game, int index);
int get_count_zero(int size, int** grid_game);
int check_equality_rows(int size, int** grid_game);
int check_equality_columns(int size, int** grid_game, int display);
int check_duplicate_rows(int size, int** grid_game, int display);
int check_duplicate_columns(int size, int** grid_game, int display);
int check_three_same_values(int size, int** grid_game, int display);
int check_full_grid(int size, int** grid_game);
int* get_grid_column(int size, int** grid_game, int index);
int get_clues(int size, int** grid_game, int display);
int Play(int size);
int** initialize_grid(int size, int display);
/*int validity_move(int **grid, int size, MOVE move);*/

#endif //TAKUZU_TAKUZU_H