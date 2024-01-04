#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int length;

int rec_1(int map[length][length], int k, int i, int j){
    if (k == -1){return 1;}
    if (map[i][j] <= map[i][k]){
        return 0;
    }
    return rec_1(map, k - 1, i, j);
}

int rec_2(int map[length][length], int k, int i, int j, int length){
    if (k == length){return 1;}
    if (map[i][j] <= map[i][k]){
        return 0;
    }
    return rec_2(map, k + 1, i, j, length);
}

int rec_3(int map[length][length], int k, int i, int j){
    if (k == -1){return 1;}
    if (map[i][j] <= map[k][j]){
        return 0;
    }
    return rec_3(map, k - 1, i, j);
}

int rec_4(int map[length][length], int k, int i, int j, int length){
    if (k == length){return 1;}
    if (map[i][j] <= map[k][j]){
        return 0;
    }
    return rec_4(map, k + 1, i, j, length);
}

int main(){
    int visible_tree = 0;
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
        }
    }
    // 2 loop dibawah ini untuk memulai dari 1,1 dst
    for (int i = 1; i < length - 1; i++){
        for (int j = 1; j < length - 1; j++){
            if (rec_1(map, j - 1, i, j)){
                visible_tree++;
                continue;
            }
            if (rec_2(map, j + 1, i, j, length)){
                visible_tree++;
                continue;
            }
            if (rec_3(map, i - 1, i, j)){
                visible_tree++;
                continue;
            }
            if (rec_4(map, i + 1, i, j, length)){
                visible_tree++;
                continue;
            }
        }
    }
    printf("Visible trees are %d.", visible_tree);
}