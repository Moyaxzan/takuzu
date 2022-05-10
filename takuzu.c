//
// Created by Moyaxzan on 07/04/2022.
//

#include "takuzu.h"

typedef struct
{
    int size;
    int** tab;
} GRID;

typedef struct {
    GRID* grid;
    GRID mask;
} SOLUTION;

typedef struct{
    int value;
    int column;
    int row;
}MOVE;

GRID create_grid(int size){
    GRID grid;
    grid.size = size;
    grid.tab = malloc(sizeof(int*) * size);
    for(int i = 0; i < size; i++){
        grid.tab[i] = malloc(sizeof(int) * size);
        for(int j=0; j < size; j++){
            grid.tab[i][j] = 0;
        }
    }
    return grid;
}


void display_grid(GRID grid){
    int i;
    int j;
    for(i = 0; i < grid.size; i++){
        for(j = 0; j < grid.size; j++){
            printf("%d  ", grid.tab[i][j]);
        }
        printf("\n");
    }
}
/*
int validity_move(GRID grid,MOVE move){

}*/