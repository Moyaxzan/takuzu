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

/*int verification(int size, int grid_game[size][size]) {}*/

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

int Play() {
    int size, exit, position_x, position_y, value;
    printf("what size you want ? (4 or 8)\n");
    scanf("%d", &size);
    if (size == -1)
        exit = 0;
    while (size != 4 && size != 8 && exit){
        printf("wrong size, try again\n");
        scanf("%d", &size);
        if (size == -1)
            exit = 0;
    }
    int grid_game[size][size];
    if (size == -1) {
        exit = 0;
    } else {
        if (size == 4) {
            int solution_tab[4][4] = {{1, 0, 0, 1},
                                      {0, 1, 1, 0},
                                      {0, 1, 0, 1},
                                      {1, 0, 1, 0}};

            int solution_mask[4][4] = {{0, 1, 1, 0},
                                       {0, 0, 0, 0},
                                       {0, 1, 1, 0},
                                       {1, 0, 0, 0}};
            grid_game[size][size] = create_grid(size);
            get_grid_game(size, solution_tab, solution_mask, grid_game);
        } else {
            int solution_tab[8][8] = {{1, 0, 1, 1, 0, 1, 0, 0},
                                      {1, 0, 1, 0, 1, 0, 0, 1},
                                      {0, 1, 0, 1, 1, 0, 1, 0},
                                      {0, 1, 0, 1, 0, 1, 1, 0},
                                      {1, 0, 1, 0, 0, 1, 0, 1},
                                      {0, 1, 1, 1, 1, 1, 1, 0},
                                      {0, 0, 1, 1, 0, 1, 1, 0},
                                      {1, 1, 0, 0, 1, 0, 0, 1}};

            int solution_mask[8][8] = {{1, 0, 1, 1, 0, 1, 0, 1},
                                       {0, 0, 1, 0, 0, 0, 0, 0},
                                       {1, 0, 0, 0, 0, 0, 0, 1},
                                       {1, 0, 1, 0, 0, 1, 1, 0},
                                       {1, 0, 0, 0, 1, 0, 0, 1},
                                       {0, 0, 0, 0, 1, 0, 0, 0},
                                       {0, 1, 1, 1, 1, 1, 0, 0},
                                       {0, 1, 0, 1, 0, 0, 1, 0}};
            grid_game[size][size] = create_grid(size);
            get_grid_game(size, solution_tab, solution_mask, grid_game);
        }
        if(exit) {
            display_grid(size, grid_game);

            printf("Write a position in which you want to play\n");

            printf("Enter the row index (Between 1 and %d)\n", size);
            scanf("%d", &position_y);
            if (position_y == -1) {
                exit = 0;
            }
            while ((position_y < 1 || position_y > 8) && exit) {
                printf("Enter a correct row index (Between 1 and %d)\n", size);
                scanf("%d", &position_y);
                if (position_y == -1)
                    exit = 0;
            }
            if (exit) {
                printf("Enter the column index (Between 1 and %d)\n", size);
                scanf("%d", &position_x);
                if (position_x == -1)
                    exit = 0;
                while ((position_x < 1 || position_x > 8) && exit) {
                    printf("Enter a correct column index (Between 1 and %d)\n", size);
                    scanf("%d", &position_x);
                    if (position_x == -1)
                        exit = 0;
                }

                if (exit) {
                    printf("Do you want to play 0 or 1 ?");
                    scanf("%d", &value);
                    if (value == -1)
                        exit = 0;
                    while ((value != 0 && value != 1) && exit) {
                        printf("Enter a correct value (1 or 0)\n");
                        scanf("%d", &value);
                        if (value == -1)
                            exit = 0;
                    }
                    grid_game[position_x][position_y] = value;
                    /*TODO: Check si le coup est bon oéoé*/
                }
            }
        }
    }
    return exit;
}

/*
int validity_move(GRID grid,MOVE move){

}*/