#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
int main(){
    char array_box[12][12];
    int location_x = 1, location_y = 1;
    int life = 1;
    int score = 0;
    int randomized_coordinate[6];
    int count_the_food = 3;
    int indicator_q = 0;
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            if (i == 0 || j == 0 || i == 11 || j == 11){
                array_box[i][j] = '#';
            }
            else if (i == 1 && j == 1){array_box[1][1] = '$';}
            else{
                array_box[i][j] = ' ';
            }
        }
    }
    for (int a = 0; a < 6; a+=2){
        int tumbal_rand_a = rand() % 11;
        if (tumbal_rand_a == 0){tumbal_rand_a++;}
        int tumbal_rand_b = rand() % 11;
        if (tumbal_rand_b == 0){tumbal_rand_b++;}
        array_box[tumbal_rand_a][tumbal_rand_b] = '*';
        randomized_coordinate[a] = tumbal_rand_a;
        randomized_coordinate[a+1] = tumbal_rand_b;
    }
    
    
    while (life){
        if (count_the_food == 0){
            for (int a = 0; a < 6; a+=2){
                int tumbal_rand_a = rand() % 11;
                if (tumbal_rand_a == 0){tumbal_rand_a++;}
                int tumbal_rand_b = rand() % 11;
                if (tumbal_rand_b == 0){tumbal_rand_b++;}
                array_box[tumbal_rand_a][tumbal_rand_b] = '*';
                randomized_coordinate[a] = tumbal_rand_a;
                randomized_coordinate[a+1] = tumbal_rand_b;
                count_the_food = 3;
            }
        }
        for (int i = 0; i < 12; i++){
            for (int j = 0; j < 12; j++){
                printf("%c", array_box[i][j]);
            }
            printf("\n");
        }
        
        char user_input;
        int flag_input = 1;
        while (flag_input){
            printf("Input command\n>> ");
            scanf("%c", &user_input);
            getchar();
            switch (user_input){
                case 'a':
                    if (location_y == 1){
                        printf("Invalid move, barrier there.\n");
                        break;
                    }
                    array_box[location_x][location_y] = ' ';
                    location_y--;
                    // array_box[location_x][location_y] = '$';
                    flag_input = 0;
                    break;
                case 'w':
                    if (location_x == 1){
                        printf("Invalid move, barrier there.\n");
                        break;
                    }
                    array_box[location_x][location_y] = ' ';
                    location_x--;
                    // array_box[location_x][location_y] = '$';
                    flag_input = 0;
                    break;
                case 'd':
                    if (location_y == 11){
                        printf("Invalid move, barrier there.\n");
                        break;
                    }
                    array_box[location_x][location_y] = ' ';
                    location_y++;
                    // array_box[location_x][location_y] = '$';
                    flag_input = 0;
                    break;
                case 's':
                    if (location_x == 11){
                        printf("Invalid move, barrier there.\n");
                        break;
                    }
                    array_box[location_x][location_y] = ' ';
                    location_x++;
                    // array_box[location_x][location_y] = '$';
                    flag_input = 0;
                    break;
                case 'q':
                    flag_input = 0;
                    life = 0;
                    break;
                default:
                    printf("Wrong input! Try again.\n");
                    break;
            }
            int you_die = rand() % 5;
            int your_gacha = rand() % 5;
            if (array_box[location_x][location_y] == '*'){
                if (your_gacha == you_die){
                    life = 0;
                    break;
                }
                else{
                    score++;
                    count_the_food--;
                }
            }
            array_box[location_x][location_y] = '$';
        }
    }
    if (life == 0 && indicator_q == 0){
        printf("YOU HAVE BEEN POISONED!\nGAME OVER!\nScore : %d\n", score);
    }
    else if (indicator_q == 1){
        printf("Quit while in game? Noob.\n");
    }
    
}