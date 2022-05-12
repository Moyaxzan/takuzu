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
                                break; }
                            case 2: {
                                break; }
                            case 3: {
                                if(exit)
                                    exit = Play();
                                break;
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
        else
            exit = 1;
        }
    }
    return 0;
}