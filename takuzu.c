//
// Created by Moyaxzan on 07/04/2022.
//

#include "takuzu.h"

typedef struct
{
    int size;
    int **tab;
} GRID;

typedef struct{
    int value;
    int indice_x;
    int indice_y;
}MOVE;


void display_grid(GRID grid){
    int i;
    int j;
    for(i = 0; i < grid.size; i++){
        for(j = 0; j < grid.size; j++){
            printf("%d ", grid.tab[i][j]);
        }
        printf("\n");
    }
}

int validity_move(GRID grid, MOVE move){

}

/* function that creates a grid with the size of the user */
GRID create_grid(int size){
    GRID grid;
    grid.size = size;
    grid.tab = malloc(sizeof(int *) * size ^ 2);
    for(int i = 0; i < size; i++){
        for(int j=0; j < size; j++){
            grid.tab[i][j] = 0;
            printf("%d", grid.tab[i][j]);
        }
        printf("\n");
    }
    return grid;
}