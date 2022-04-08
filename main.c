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
        if (size != 4 && size != 6 && size != 8 && size != 10) {
            printf("wrong size, try again\n");
            scanf("%d", &size);
        }
    } while (size != 4 && size != 6 && size != 8 && size != 10);

    int **tab = create_grid(size);





    return 0;
}