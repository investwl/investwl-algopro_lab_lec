#include <stdio.h>

int main(){
    int buat1, buat2, temp, point1, point2;
    scanf("%d\n", &buat1);
    int arr1[buat1];
    for (int i = 0; i < buat1; i++){
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &buat2);
    if (buat1 > buat2){temp = buat1;}
    else{temp = buat2;}
    int arr2[buat2];
    int total[temp];
    point1 = buat1;
    point2 = buat2;
    for (int i = 0; i < buat2; i++){
        scanf("%d", &arr2[i]);
    }
    for (int i = 0; i < temp; i++){
        if (point1 > 0 && point2 > 0){total[i] = arr1[i] + arr2[i];}
        else{
            if (point1 <= 0){total[i] = arr2[i];}
            else if (point2 <= 0){total[i] = arr1[i];}
        }
        point1--;
        point2--;

    }
    printf("{");
    for (int i = 0; i < temp; i++){
        if (i == temp-1){printf("%d}", total[i]);}
        else{printf("%d, ", total[i]);}
    }
}