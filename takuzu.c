//
// Created by Moyaxzan on 07/04/2022.
//

#include "takuzu.h"


int create_grid(int size) {
   int **grid = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
    return **grid;
}


void display_grid(int size, int grid_game[size][size]){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(grid_game[i][j] != -1){
                printf(" %d ", grid_game[i][j]);
            }else{
                printf(" . ");
            }
        }
        printf("\n");
    }
}


int get_grid_game(int size,int solution[size][size], int mask[size][size], int empty_grid[size][size]){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(mask[i][j] == 1){
                empty_grid[i][j] = solution[i][j];
            }else{
                empty_grid[i][j] = -1;
            }
        }
    }
    return **empty_grid;
}

/* TODO : avoid les -1 */

int verification(int size, int grid_game[size][size]) {}

int check_equality_rows(int size, int grid_game[size][size]) {
    for(int i = 0; i < size; i++){
        int sum = 0;
        for(int j = 0; j < size; j++) {
            if (grid_game[i][j]!=-1)
                sum += grid_game[i][j];
        }
        if (sum != size/2)
            return 0;
    }
    return 1;
}

int check_equality_columns(int size, int grid_game[size][size]) {
    for(int i = 0; i < size; i++){
        int sum = 0;
        for(int j = 0; j < size; j++) {
            if (grid_game[j][i]!=-1)
                sum += grid_game[j][i];
        }
        if (sum != size/2)
            return 0;
    }
    return 1;
}

int check_duplicate_rows(int size, int grid_game[size][size]) {
    for (int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
                if (grid_game[i] != grid_game[j])
                    return 0;
            }
        }
    return 1;
}

int check_duplicate_columns(int size, int grid_game[size][size]) {
    for (int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
                if (grid_game[j] != grid_game[i])
                    return 0;
            }
        }
    return 1;
}

int check_three_same_values(int size, int grid_game[size][size]) {
    for (int i = 0; i < size-2; i++) {
        for(int j = i+1; j < size-2; j++) {
            if (grid_game[i][j] != -1) {
                if (grid_game[i + 1][j] == grid_game[i][j])
                    if (grid_game[i + 2][j] == grid_game[i][j])
                        return 0;
                if (grid_game[i][j + 1] == grid_game[i][j])
                    if (grid_game[i][j + 2] == (grid_game[i][j]))
                        return 0;
            }
        }
    }
    return 1;
}



/*
int validity_move(GRID grid,MOVE move){

}*/