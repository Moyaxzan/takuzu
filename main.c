//
// Created by Moyaxzan on 07/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "takuzu.h"


int main() {
    int size;

    printf("what size you want ? (4, 6, 8 or 10)\n");
    scanf("%d", &size);
    do {
        if (size != 4 && size != 8) {
            printf("wrong size, try again\n");
            scanf("%d", &size);
        }
    } while (size != 4 && size != 6 && size != 8 && size != 10);

    if (size == 4) {
        int solution_tab[4][4] = {{1, 0, 0, 1},
                                  {0, 1, 1, 0},
                                  {0, 1, 0, 1},
                                  {1, 0, 1, 0}};

        int solution_mask[4][4] = {{0, 1, 1, 0},
                                   {0, 0, 0, 0},
                                   {0, 1, 1, 0},
                                   {1, 0, 0, 0}};

        display_grid(4, solution_tab, solution_mask);
    }else{
        int solution_tab[8][8] = {{1, 0, 0, 1},
                                  {0, 1, 1, 0},
                                  {0, 1, 0, 1},
                                  {1, 0, 1, 0}};

        int solution_mask[8][8] = {{0, 1, 1, 0, },
                                   {0, 0, 0, 0},
                                   {0, 1, 1, 0},
                                   {1, 0, 0, 0}};
    }
    return 0;
}