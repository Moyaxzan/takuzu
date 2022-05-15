//
// Created by Moyaxzan on 07/04/2022.
//
#include <time.h>
#include "takuzu.h"
#include <unistd.h>

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
            grid[i][j] = -1;
        }
    }
    return grid;
}


void display_grid(int size, int** grid_game){
    printf("\n");
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
    printf("\n");
}



int** get_grid_game(int size, int** solution_grid, int** mask_grid) {
    int** grid_game = create_grid(size);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(mask_grid[i][j] == 1){
                grid_game[i][j] = solution_grid[i][j];
            }else{
                grid_game[i][j] = -1;
            }
        }
    }
    return grid_game;
}


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

int check_equality_columns(int size, int** grid_game, int display) {
    int count_zero, count_one;
    for(int i = 0; i < size; i++){
        count_zero = 0;
        count_one = 0;
        for(int j = 0; j < size; j++) {
            if (grid_game[j][i] == 1)
                count_one += 1;
            else if (grid_game[j][i] == 0)
                count_zero += 1;
        }
        if (count_one > size/2) {
            if(display)
                printf("There is too much 1's on the column %d\n\n", i+1);
            return 0;
        }else if(count_zero > size/2){
            if(display)
                printf("There is too much 0's on the column %d\n\n", i+1);
            return 0;
        }
    }
    return 1;
}


int compare_arrays(int size, int tab1[SIZE_M], int tab2[SIZE_M]) {
    for (int i = 0; i < size; i++) {
        if (tab1[i]!=tab2[i] || tab1[i]==-1 || tab2[i]==-1)
            return 0;
    }
    return 1;
}

/* Returns a 1D list containing the column [index] of grid_game */
int* get_grid_column(int size, int** grid_game, int index) {
    int* grid_column = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        grid_column[i]= grid_game[i][index];
    }
    return grid_column;
}

int half_filled_row(int size, int tab[SIZE_M]) {
    int count_zero=0, count_one=0;
    for (int i=0; i < size; i++) {
        if (tab[i]==0)
            count_zero+=1;
        else if (tab[i]==1)
            count_one+=1;
    }
    if (count_zero + count_one != size) {
        if (count_zero == size / 2) {
            for (int i = 0; i < size; i++)
                if (tab[i] == -1)
                    tab[i] = 1;
            return 1;
        } else if (count_one == size / 2) {
            for (int i = 0; i < size; i++)
                if (tab[i] == -1)
                    tab[i] = 0;
            return 1;
        }
    }
    return 0;
}

int half_filled_column(int size, int** grid_game, int index) {
    int count_zero=0, count_one=0;
    for (int i=0; i < size; i++) {
        if (grid_game[i][index]==0)
            count_zero+=1;
        else if (grid_game[i][index]==1)
            count_one+=1;
    }
    if (count_zero + count_one != size) {
        if (count_zero == size / 2) {
            for (int i = 0; i < size; i++)
                if (grid_game[i][index] == -1)
                    grid_game[i][index] = 1;
            return 1;
        } else if (count_one == size / 2) {
            for (int i = 0; i < size; i++)
                if (grid_game[i][index] == -1)
                    grid_game[i][index] = 0;
            return 1;
        }
    }
    return 0;
}

/* Returns 1 if there are duplicated rows */
int check_duplicate_rows(int size, int** grid_game, int display) {
    for (int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            printf("");
            if (compare_arrays(size, grid_game[i], grid_game[j])) {
                if(display)
                    printf("The row %d and %d are the sames.\n\n", i + 1, j + 1);
                return 0;
            }
        }
    }
    return 1;
}


/* Returns 1 if there are duplicated columns */
int check_duplicate_columns(int size, int** grid_game, int display) {
    int* tab1 = NULL;
    int* tab2 = NULL;
    for (int i = 0; i < size; i++) {
        tab1 = get_grid_column(size, grid_game, i);
        for(int j = i+1; j < size; j++) {
            tab2 = get_grid_column(size, grid_game, j);
            printf("");
            if (compare_arrays(size, tab1 , tab2)) {
                if(display)
                    printf("The column %d and %d are the sames.\n\n", i + 1, j + 1);
                return 0;
            }
        }
    }
    return 1;
}



int check_three_same_values(int size, int** grid_game, int display) {
    for (int i = 0; i < size-2; i++) {
        for (int j = 0; j < size; j++) {
            if (grid_game[i][j] != -1) {
                if (grid_game[i + 1][j] == grid_game[i][j]) {
                    if (grid_game[i + 2][j] == grid_game[i][j]) {
                        if(display)
                            printf("There are 3 same values in a row in the column %d\n\n", j + 1);
                        return 0;
                    }
                }
            }
        }
    }
    for (int j = 0; j < size-2; j++) {
        for (int i = 0; i < size; i++) {
            if (grid_game[i][j] != -1) {
                if (grid_game[i][j + 1] == grid_game[i][j]) {
                    if (grid_game[i][j + 2] == (grid_game[i][j])) {
                        if(display)
                            printf("There are 3 same values in a row in the row %d\n\n", i + 1);
                        return 0;
                    }
                }

            }

        }
    }
    return 1;
}

int verification(int size, int** grid_game) {
    if (check_equality_rows(size, grid_game) &&
        check_equality_columns(size, grid_game, 1) &&
        check_duplicate_rows(size, grid_game, 1) &&
        check_duplicate_columns(size, grid_game, 1) &&
        check_three_same_values(size, grid_game, 1))
        return 1;
    return 0;
}


/*function that checks if the grid is full*/
int check_full_grid(int size, int** grid_game) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid_game[i][j] == -1)
                return 0;
        }
    }
    return 1;
}

int get_clues(int size, int** grid_game, int display) {
    for (int i = 0; i < size - 2; i++) {
        for (int j = 0; j < size; j++) {
            if (half_filled_column(size, grid_game, j)) {
                if (display)
                    printf("Since half the column %d is filled, we can fill the other half\n", j+1);
                return 1;
            }
            if (half_filled_row(size, grid_game[j])) {
                if (display)
                    printf("Since half the row %d is filled, we can fill the other half\n", j+1);
                return 1;
            }
            if (grid_game[i][j] != -1) {
                if (grid_game[i + 1][j] == grid_game[i][j]) {
                    if (grid_game[i + 2][j] == -1) {
                        if (display)
                            printf("We can put a %d at row %d column %d since there is two %d above\n",
                               (grid_game[i][j] + 1) % 2, i + 3, j + 1, grid_game[i][j]);
                        grid_game[i+2][j] = (grid_game[i][j] + 1) % 2;
                        return 1; }
                } else if (grid_game[i + 1][j] == -1 && (grid_game[i + 2][j] == grid_game[i][j])) {
                    if (display)
                        printf("We can put a %d at row %d column %d because it is between two %d\n",
                           (grid_game[i][j] + 1) % 2, i + 2, j + 1, grid_game[i][j]);
                    grid_game[i + 1][j] = (grid_game[i][j] + 1) % 2;
                    return 1;}
            } else if (i > 0 && (grid_game[i+1][j] == grid_game[i+2][j]) && (grid_game[i+1][j]!=-1) && (grid_game[i+1][j]!=grid_game[i][j])) {
                if (display)
                    printf("We can put a %d at row %d column %d since there is two %d below\n",
                       (grid_game[i+1][j] + 1) % 2, i+1, j + 1, grid_game[i+1][j]);
                grid_game[i][j] = (grid_game[i+1][j] + 1) % 2;
                return 1; }
        }
    }
    for (int j = 0; j < size - 2; j++) {
        for (int i = 0; i < size; i++) {
            if (grid_game[i][j] != -1) {
                if (grid_game[i][j+1] == grid_game[i][j]) {
                    if (grid_game[i][j+2] == -1) {
                        if (display)
                            printf("We can put a %d at row %d column %d since there is two %d to its left\n",
                               (grid_game[i][j] + 1) % 2, i + 1, j+3, grid_game[i][j]);
                        grid_game[i][j+2] = (grid_game[i][j] + 1) % 2;
                        return 1; }
                } else if (grid_game[i][j+1] == -1 && (grid_game[i][j+2] == grid_game[i][j])) {
                    if (display)
                        printf("We can put a %d at row %d column %d because it is between two %d\n",
                           (grid_game[i][j] + 1) % 2, i + 1, j + 2, grid_game[i][j]);
                    grid_game[i][j + 1] = (grid_game[i][j] + 1) % 2;
                    return 1; }
            } else if (j > 0 && (grid_game[i][j+1] == grid_game[i][j+2]) && (grid_game[i][j+1]!=-1)) {
                    if (display)
                        printf("We can put a %d at row %d column %d since there is two %d to its right\n",
                           (grid_game[i][j] + 1) % 2, i + 1, j + 1, grid_game[i][j+1]);
                    grid_game[i][j] = (grid_game[i][j] + 1) % 2;
                    return 1; }
        }
    }
    if (display)
        printf("No more clues");
    return 0;
}





int** initialize_grid(int size, int display){
    srand(time(NULL));

    int random_val, valid = 0, cpt_rand;
    int** grid = create_grid(size);

    if(size == 4){
        int possibilities[6][4] = {
                {0, 0, 1, 1},
                {0, 1, 0, 1},
                {1, 0, 1, 0},
                {1, 1, 0, 0},
                {1, 0, 0, 1},
                {0, 1, 1, 0}};
        for (int i = 0; i < size; i++){
            cpt_rand = 0;
            valid = 0;
            while(!valid && cpt_rand != 10){
                random_val = rand() % 6;
                for (int j = 0; j < size; j++) {
                    grid[i][j] = possibilities[random_val][j];
                }

                if(display){
                    display_grid(size, grid);
                    sleep(3);
                }

                if (check_equality_columns(size, grid, display) &&
                    check_three_same_values(size, grid, display) &&
                    check_duplicate_rows(size, grid, display) &&
                    check_duplicate_columns(size, grid, display)) {
                    valid = 1;
                }

                if (!valid) {
                    for (int j = 0; j < size; j++) {
                        grid[i][j] = -1;
                    }
                    cpt_rand ++;
                }
                if(cpt_rand == 10){
                    grid = create_grid(size);
                    i = -1;
                }
            }
        }

    } else {
        int possibilities[30][8] = {
                {0, 0, 1, 0, 1, 0, 1, 1},
                {0, 0, 1, 0, 1, 1, 0, 1},
                {0, 0, 1, 1, 0, 0, 1, 1},
                {0, 0, 1, 1, 0, 1, 0, 1},
                {0, 0, 1, 1, 0, 1, 1, 0},
                {0, 1, 0, 0, 1, 1, 0, 1},
                {0, 1, 0, 0, 1, 0, 1, 1},
                {0, 1, 0, 1, 0, 1, 0, 1},
                {0, 1, 0, 1, 1, 0, 0, 1},
                {0, 1, 0, 1, 1, 0, 1, 0},
                {0, 1, 1, 0, 0, 1, 0, 1},
                {0, 1, 1, 0, 0, 1, 1, 0},
                {0, 1, 1, 0, 1, 0, 0, 1},
                {0, 1, 1, 0, 1, 0, 1, 0},
                {0, 1, 1, 0, 1, 1, 0, 0},
                {1, 0, 0, 1, 0, 0, 1, 1},
                {1, 0, 0, 1, 0, 1, 0, 1},
                {1, 0, 0, 1, 0, 1, 1, 0},
                {1, 0, 0, 1, 1, 0, 0, 1},
                {1, 0, 0, 1, 1, 0, 1, 0},
                {1, 0, 1, 0, 0, 1, 0, 1},
                {1, 0, 1, 0, 0, 1, 1, 0},
                {1, 0, 1, 0, 1, 0, 1, 0},
                {1, 0, 1, 1, 0, 0, 1, 0},
                {1, 0, 1, 1, 0, 1, 0, 0},
                {1, 1, 0, 0, 1, 0, 0, 1},
                {1, 1, 0, 0, 1, 0, 1, 0},
                {1, 1, 0, 0, 1, 1, 0, 0},
                {1, 1, 0, 1, 0, 0, 1, 0},
                {1, 1, 0, 1, 0, 1, 0, 0}};
        for (int i = 0; i < size; i++){
            cpt_rand = 0;
            valid = 0;
            while(!valid && cpt_rand != 10){
                random_val = rand() % 29;
                for (int j = 0; j < size; j++) {
                    grid[i][j] = possibilities[random_val][j];
                }
                if(display){
                    display_grid(size, grid);
                    sleep(2);
                }

                if (check_equality_columns(size, grid, display) &&
                    check_three_same_values(size, grid, display) &&
                    check_duplicate_rows(size, grid, display) &&
                    check_duplicate_columns(size, grid, display)) {
                    valid = 1;
                }

                if (!valid) {
                    for (int j = 0; j < size; j++) {
                        grid[i][j] = -1;
                    }
                    cpt_rand ++;
                }
                if(cpt_rand == 10){
                    grid = create_grid(size);
                    i = -1;
                }
            }
        }
    }
    return grid;
}

int** create_random_mask(int size) {
    srand(time(NULL));
    int **mask_grid = create_grid(size);
    int **solution_grid = NULL;
    int **grid_game = NULL;
    if (size == 4) {
        int cpt = 8;
        while (cpt > 0)
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int random_value = rand() % 3;
                    if (random_value == 1 && cpt > 0) {
                        mask_grid[i][j] = 1;
                        cpt -= 1;
                    }
                }
            }
    } else if (size == 8) {
        int cpt = 30;
        while (cpt > 0)
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int random_value = rand() % 3;
                    if (random_value == 1 && cpt > 0) {
                        mask_grid[i][j] = 1;
                        cpt -= 1;
                    }
                }
            }
    }
    solution_grid = initialize_grid(size, 0);
    grid_game = get_grid_game(size, solution_grid, mask_grid);
    while (!check_full_grid(size, grid_game)) {
        printf("%d %d\n", get_clues(size, grid_game, 0), check_full_grid(size, grid_game));
        if (!get_clues(size, grid_game, 0))
            return create_random_mask(size);
    }
    printf("AAAAAAAAAAAAAAAAAAAAAAAA %d\n", check_full_grid(size, grid_game));
    display_grid(size, grid_game);
    printf("oéoééoéooéoé");
    return mask_grid;
}

int Auto_complete(int size) {
    int** solution_grid = NULL;
    int** mask_grid = NULL;
    int** grid_game = NULL;
    solution_grid = initialize_grid(size, 0);
    mask_grid = create_random_mask(size);
    grid_game = get_grid_game(size, solution_grid, mask_grid);
    while (!check_full_grid(size, grid_game)) {
        display_grid(size, grid_game);
        get_clues(size, grid_game, 1);
        printf("\n");
        sleep(2);
    }
    display_grid(size, grid_game);
    printf("oeoe gg\n");
}

int Play(int size) {
    int exit = 1, position_x, position_y, value, invalid_index = 1, win = 0, player_lifes = 3;
    int** not_tested_grid = NULL;
    int** solution_grid = NULL;
    int** mask_grid = NULL;
    int** grid_game = NULL;
    if (size == -1) {
        exit = 0;
    } else {
        solution_grid = initialize_grid(size, 0);
        mask_grid = create_random_mask(size);
        grid_game = get_grid_game(size, solution_grid, mask_grid);
        display_grid(size, grid_game);
        while(exit && !win && player_lifes > 0) {
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
                    if (grid_game[position_x-1][position_y] == value)
                        grid_game[position_x-1][position_y-1] = value;
                    else
                        printf("Valid move but incorrect");
                } else {
                    player_lifes -= 1;
                    printf("You lost a life ! You have %d remaining.", player_lifes);
                }
                display_grid(size, grid_game);
            }
            win = check_full_grid(size, grid_game);
        }
        if(win)
            printf("CONGRATULATIONS ! You won (gg) ! \n");
        else if (player_lifes < 0)
            printf("Sadge");
    }
    return exit;
}
