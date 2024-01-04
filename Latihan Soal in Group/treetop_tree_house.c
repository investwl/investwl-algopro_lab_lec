#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
30373
25512
65332
33549
35390
*/


int main(){
    int visible_tree = 0;
    int length;
    printf("Input map size : ");
    scanf("%d", &length); getchar();
    visible_tree += (length - 1) * 4; // the edges has pattern.

    int map[length][length];
    char str_tumbal[length];
    int int_tumbal[length];

    // terima dalam bentuk nonspace, dan pecah
    for (int i = 0 ; i < length ; i++){
        printf("Input array row %d (no spaces) : ", i);
        scanf("%s", str_tumbal);
        int_tumbal[i] = atoi(str_tumbal);
    }

    for (int i = 0 ; i < length ; i++){
        int modulor = length, divisor = length - 1;
        for (int j = 0 ; j < length ; j++){
            double sementara_1 = pow(10, modulor);
            double sementara_2 = pow(10, divisor);
            int convert_1 = (int)sementara_1;
            int convert_2 = (int)sementara_2;
            map[i][j] = int_tumbal[i] % convert_1 / convert_2;
            modulor--;
            divisor--;
            // line dibawah utk lgsg nambahin edge trees as visible
            // if (i == 0 || j == 0  || i == length - 1 || j == length - 1){visible_tree++;}
        }
    }

    // 2 loop dibawah ini untuk memulai dari 1,1 dst
    int flag;
    for (int i = 1; i < length - 1; i++){
        for (int j = 1; j < length - 1; j++){
            flag = 1;

            for (int k = j - 1; k > -1; k--){
                if (map[i][j] <= map[i][k]){
                    flag = 0;
                    break;
                }
            }

            if (flag){
                visible_tree++;
                continue;
            }

            flag = 1;
            for (int k = j + 1; k < length; k++){
                if (map[i][j] <= map[i][k]){
                    flag = 0;
                    break;
                }
            }

            if (flag){
                visible_tree++;
                continue;
            }

            flag = 1;
            for (int k = i - 1; k > -1; k--){
                if (map[i][j] <= map[k][j]){
                    flag = 0;
                    break;
                }
            }

            if (flag){
                visible_tree++;
                continue;
            }

            flag = 1;
            for (int k = i + 1; k < length; k++){
                if (map[i][j] <= map[k][j]){
                    flag = 0;
                    break;
                }
            }

            if (flag){
                visible_tree++;
                continue;
            }
        }
    }
    printf("Visible trees are %d.", visible_tree);
}