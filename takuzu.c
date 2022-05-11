//
// Created by Moyaxzan on 07/04/2022.
//

#include "takuzu.h"


/* function that create a grid with a given size initalized with 0 */
int **create_grid(int size) {
    int **grid = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}


void display_grid(int size,int grid_game[size][size]){
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
    int i, j;
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            if(mask[i][j] == 1){
                empty_grid[i][j] = solution[i][j];
            }else{
                empty_grid[i][j] = -1;
            }
        }
    }
    return **empty_grid;
}

/*
int validity_move(GRID grid,MOVE move){

}*/