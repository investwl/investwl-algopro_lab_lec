#include <stdio.h>

int main(){
    // max

    // int test_case;
    // scanf("%d", &test_case); getchar();
    // int max = 0, tumbal;
    // for (int i = 0; i < test_case ; i++){
    //     scanf("%d", &tumbal);
    //     if (i == 0){
    //         max = tumbal;
    //     }
    //     if (max < tumbal){
    //         max = tumbal;
    //     }
    // }
    // printf("max : %d\n", max);   
 
    // find index


    // int length;
    // scanf("%d", &length); getchar();
    // int panjang[length];
    // for (int i = 0 ; i < length ; i++){
    //     scanf("%d", &panjang[i]);
    // }
    // int yang_dicari;
    // scanf("%d", &yang_dicari);
    // int flag = 0;
    // for (int i = 0 ; i < length ; i++){
    //     if (panjang[i] == yang_dicari){
    //         printf("Exist\n");
    //         flag = 1;
    //         break;
    //     }
    // }
    // if (flag == 0){
    //     printf("Doesn't exist\n");
    // }

    // int test_case;
    // scanf("%d", &test_case); getchar();
    // char mapel[test_case][51];
    // int nilai[test_case];
    // int index_max;
    // for (int i = 0 ; i <  test_case ; i++){
    //     scanf("%s %d", mapel[i], &nilai[i]);
    // }
    // for (int j = 0 ; j < test_case ; j++){
    //     if (j == 0){index_max = j;}
    //     if (mapel[j] > mapel[index_max]){index_max = j;}
    // }
    // printf("Mata pelajaran : %s\nNilai : %d\n", mapel[index_max], nilai[index_max]);

    // not average
    // basically rata2 is modus. cari least number modus.

    int length;
    scanf("%d", &length); getchar();
    int average = 0, marker = 0;
    int arr[length];
    // karena constraint cuma sampe 10, boleh lah ya pake cara curang
    int number_count[10];

    for (int i = 0 ; i < 10 ; i++){
        number_count[i] = 0;
    }

    for (int i = 0 ; i < length ; i++){
        scanf("%d", &arr[i]);
        number_count[arr[i] - 1]++;
    }

    /* number_count = isi brp kali itu angka muncul 
    marker cuma nyimpen i + 1 karena itu nunjukkin si angka brp yg muncul
    bbrp kali dalam array list */

    for (int i = 0 ; i < 10 ; i++){
        if (i == 0){
            marker = number_count[i];
            average = i + 1;
        }
        else if (marker < number_count[i]){
            marker = number_count[i];
            average = i + 1;
        }
        else if (marker == number_count[i]){
            if (average > i + 1){
                average = i + 1;
            }
        }
    }

    int counter = 0;
    for (int i = 0 ; i < length ; i++){
        if (arr[i] >= average){counter++;}
    }
    printf("Nilai rata-rata : %d\nSiswa yang lulus: %d\n", average, counter);

}