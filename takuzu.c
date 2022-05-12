//
// Created by Moyaxzan on 07/04/2022.
//

#include "takuzu.h"

/* function that copy the grid in a new grid */
int** copy_grid(int size, int** grid) {
    int **grid_copy = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        grid_copy[i] = malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            grid_copy[i][j] = grid[i][j];
        }
    }
    return grid_copy;
}


int** create_grid(int size) {
    int **grid = malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        grid[i] = malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}


void display_grid(int size, int** grid_game){
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


int** get_grid_game(int size, int** empty_grid) {
    if (size == 4) {
        int solution_tab[4][4] = {{1, 0, 0, 1},
                                  {0, 1, 1, 0},
                                  {0, 1, 0, 1},
                                  {1, 0, 1, 0}};

        int solution_mask[4][4] = {{0, 1, 1, 0},
                                   {0, 0, 0, 0},
                                   {0, 1, 1, 0},
                                   {1, 0, 0, 0}};
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(solution_mask[i][j] == 1){
                    empty_grid[i][j] = solution_tab[i][j];
                }else{
                    empty_grid[i][j] = -1;
                }
            }
        }
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
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(solution_mask[i][j] == 1){
                    empty_grid[i][j] = solution_tab[i][j];
                }else{
                    empty_grid[i][j] = -1;
                }
            }
        }
    }

    return empty_grid;
}

/* TODO : avoid les -1 */



int check_equality_rows(int size, int** grid_game) {
    int count_zero, count_one;
    for(int i = 0; i < size; i++){
        count_zero = 0;
        count_one = 0;
        for(int j = 0; j < size; j++) {
            if (grid_game[i][j]==1)
                count_one += 1;
            else if (grid_game[i][j]==0)
                count_zero += 1;
        }
        if (count_one > size/2) {
            printf("Be careful ! There is too much 1's on the row %d\n", i+1);
            return 0;
        } else if(count_zero > size/2){
            printf("Be careful ! There is too much 0's on the row %d\n", i+1);
            return 0;
        }
    }
    return 1;
}

int check_equality_columns(int size, int** grid_game) {
    int count_zero, count_one;
    for(int i = 0; i < size; i++){
        count_zero = 0;
        count_one = 0;
        for(int j = 0; j < size; j++) {
            if (grid_game[i][j] == 1)
                count_one += 1;
            else if (grid_game[i][j] == 0)
                count_zero += 1;
        }
        if (count_one > size/2) {
            printf("Be careful ! There is too much 1's on the column %d\n", i+1);
            return 0;
        }else if(count_zero > size/2){
            printf("Be careful ! There is too much 0's on the column %d\n", i+1);
            return 0;
        }
    }
    return 1;
}


int compare_arrays(int size, int tab1[SIZE_M], int tab2[SIZE_M]) {
    for (int i; i < size; i++) {
        if (tab1[i]!=tab2[i])
            return 0;
    }
    return 1;
}

/* Return 1 if there are duplicated rows */
int check_duplicate_rows(int size, int** grid_game) {
    for (int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            if (compare_arrays(size, grid_game[i], grid_game[j]))
                return 1;
        }
    }
    return 0;
}



/* Returns 1 if there are duplicated columns */
int check_duplicate_columns(int size, int** grid_game) {
    for (int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            if (compare_arrays(size, grid_game[i], grid_game[j]))
                return 1;
        }
    }
    return 0;
}



int check_three_same_values(int size, int** grid_game) {
    for (int i = 0; i < size-2; i++) {
        for (int j = i + 1; j < size; j++) {

            if (grid_game[i][j] != -1) {
                printf("%d ", grid_game[i][j]);
                if (grid_game[i + 1][j] == grid_game[i][j]) {
                    printf("%d ", grid_game[i+1][j]);
                    if (grid_game[i + 2][j] == grid_game[i][j]) {
                        printf("%d ", grid_game[i+2][j]);
                        printf("There are 3 same values in a row in the row %d\n", i + 1);
                        return 0;
                    }
                }
            }
        }
    }
    for (int j = 0; j < size-2; j++) {
        for (int i = j + 1; i < size; i++) {

            if (grid_game[i][j] != -1) {
                /*TODO: make this work*/
                if (grid_game[i][j + 1] == grid_game[i][j]) {
                    if (grid_game[i][j + 2] == (grid_game[i][j])) {
                        printf("There are 3 same values in a row in the column %d\n", i + 1);
                        return 0;
                    }
                }

            }

        }
    }
    return 1;
}

int verification(int size, int** grid_game) {
    if (check_equality_rows(size, grid_game) && check_equality_columns(size, grid_game) && check_three_same_values(size, grid_game))
        return 1;
    return 0;
}

int Play() {
    int size, exit = 1, position_x, position_y, value, invalid_index = 1;

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

    int** not_tested_grid = NULL;
    int** grid_game = NULL;

    if (size == -1) {
        exit = 0;
    } else {
        grid_game = create_grid(size);
        get_grid_game(size,grid_game);

        display_grid(size, grid_game);

        /*TODO: while (exit or win) */
        while(exit) {
            invalid_index = 1;
            while (invalid_index){
                printf("Write a position in which you want to play\n");

                printf("Enter the row index (Between 1 and %d)\n", size);
                scanf("%d", &position_x);
                if (position_x == -1) {
                    exit = 0;
                }
                while ((position_x < 1 || position_x > 8) && exit) {
                    printf("Enter a correct row index (Between 1 and %d)\n", size);
                    scanf("%d", &position_x);
                    if (position_x == -1)
                        exit = 0;
                }

                if (exit) {
                    printf("Enter the column index (Between 1 and %d)\n", size);
                    scanf("%d", &position_y);
                    if (position_y == -1)
                        exit = 0;
                    while ((position_y < 1 || position_y > size) && exit) {
                        printf("Enter a correct column index (Between 1 and %d)\n", size);
                        scanf("%d", &position_y);
                        if (position_y == -1)
                            exit = 0;
                    }

                    if (grid_game[position_x-1][position_y-1] == -1 && exit)
                        invalid_index = 0;
                    if (invalid_index)
                        printf("invalid input : case already filled.\n\n");
                }
            }
            if (exit) {

                printf("Do you want to play 0 or 1 ?\n");
                scanf("%d", &value);
                if (value == -1)
                    exit = 0;
                while ((value != 0 && value != 1) && exit) {
                    printf("Enter a correct value (1 or 0)\n");
                    scanf("%d", &value);
                    if (value == -1)
                        exit = 0;
                }
                not_tested_grid = copy_grid(size, grid_game);
                not_tested_grid[position_x - 1][position_y - 1] = value;
                if(verification(size, not_tested_grid)){

                    /*TODO:check if the move is in solution_tab*/
                    grid_game[position_x-1][position_y-1] = value;

                }
                display_grid(size, grid_game);
            }


        }
    }
    return exit;
}

/*
int validity_move(GRID grid,MOVE move){

}*/


