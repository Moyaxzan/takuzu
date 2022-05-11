//
// Created by Moyaxzan on 07/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "takuzu.h"


int main() {
    int exit = 1;
    while (exit){
        int size, choice1, choice2, position_x, position_y, value;
        printf("What do you want to do :\n");
        printf("(1) Solve the grid \n(2) Solve automatically \n(3) Generate takuzu grid\n");
        scanf("%d", &choice1);
        if (choice1 == -1){
            exit = 0;
        }
        while (choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != -1){
            printf("Please enter a valid choice\n");
            scanf("%d", &choice1);
        }
        if (choice1 != -1){
            switch (choice1) {
                case 1:
                    printf("(1) Enter a mask manually \n(2) Automatically generate a mask \n(3) Play\n");
                    scanf("%d", &choice2);
                    if (choice2 == -1) {
                        exit = 0;
                    }
                    while (choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2 != -1) {
                        printf("Please enter a valid choice\n");
                        scanf("%d", &choice2);
                    }
                    if (choice2 == -1) {
                        exit = 0;
                    }else{
                        switch (choice2) {
                            case 1: {
                                printf("what size you want ? (4 or 8)\n");
                                scanf("%d", &size);
                                do {
                                    if (size != 4 && size != 8 && size != -1) {
                                        printf("wrong size, try again\n");
                                        scanf("%d", &size);
                                    }
                                } while (size != 4 && size != 8 && size != -1);
                                int grid_game[size][size];
                                    if (size == -1) {
                                        exit = 0;
                                } else{
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
                                    display_grid(size, grid_game);
                                    printf("Write a position in which you want to play\n");
                                    printf("Enter the row index (Between 1 and %d)\n", size);
                                    /* TODO: Exits */
                                    scanf("%d", &position_y);
                                    while (position_y < 1 || position_y > 8) {
                                        printf("Enter a correct row index (Between 1 and %d)\n", size);
                                        scanf("%d", &position_y);
                                    }
                                    printf("Enter the column index (Between 1 and %d)\n", size);
                                    scanf("%d", &position_x);
                                    while (position_x < 1 || position_x > 8) {
                                        printf("Enter a correct column index (Between 1 and %d)\n", size);
                                        scanf("%d", &position_x);
                                    }
                                    printf("Do you want to play 0 or 1 ?");
                                    scanf("%d", &value);
                                    while (value != 0 && value!= 1) {
                                        printf("Enter a correct value (1 or 0)\n");
                                        scanf("%d", &value);
                                    }
                                    grid_game[position_x][position_y]=value;
                                    /*TODO: Check si le coup est bon oéoé*/

                                }
                                break; }
                            case 2: {
                                break; }
                            case 3: {
                                break; }
                        }
                    }
                    /*end case 1*/
            }
        }
        char restart_char;
        printf("do you want to restart (y/n)\n");
        scanf("%s", &restart_char);
        if (restart_char == 'n')
            exit = 0;
    }
    return 0;
}