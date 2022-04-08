//
// Created by Moyaxzan on 07/04/2022.
//

#include "takuzu.h"

int **create_grid(int size){
    int i;
    int j;
    int tab[size][size];
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            tab[i][j]=0;
        }
    }
    return tab;
}
