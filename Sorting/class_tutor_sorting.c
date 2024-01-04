#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int partition(int* array, int left, int right){
    int pivot_index = right;
    int last_swap = left;

    for (int i = left; i < pivot_index; i++){
        if (array[i] < array[pivot_index]){
            int temp = array[i];
            array[i] = array[last_swap];
            array[last_swap] = temp;

            last_swap++;
        }
    }

    int temp = array[last_swap];
    array[last_swap] = array[pivot_index];
    array[pivot_index] = temp;

    return last_swap;
}

void quick_sort(int* array, int left, int right){
    if (left > right){return;}

    int mid = partition(array, left, right);

    quick_sort(array, left, mid - 1);
    quick_sort(array, mid + 1, right);
}

int main(){
    // bubble sort, udh tau

    // int array[6];

    // int length = 6;

    // printf("Array numbers : ");

    // for (int i = 0 ; i < length ; i++){scanf("%d", &array[i]);}
    // getchar();

    // for (int i = 0 ; i < length - 1; i++){
    //     for (int j = i+1; j < length; j++){
    //         if (array[j] < array[i]){
    //             int temp = array[i];
    //             array[i] = array[j];
    //             array[j] = temp;
    //         }
    //     }
    // }

    // for (int i = 0 ; i < length ; i++){printf("%d ", array[i]);}

    // bb sort pt 2

    // char array[6][21];

    // int length = 6;

    // printf("List of names : ");

    // for (int i = 0 ; i < length ; i++){scanf("%s", array[i]);}
    // getchar();

    // for (int i = 0 ; i < length - 1; i++){
    //     for (int j = i+1; j < length; j++){
    //         if (strcmp(array[j], array[i]) < 0){
    //             char temp[21];
    //             strcpy(temp,array[i]);
    //             strcpy(array[i],array[j]);
    //             strcpy(array[j], temp);
    //         }
    //     }
    // }

    // for (int i = 0 ; i < length ; i++){printf("%s\n", array[i]);}

    // quick sort

    int array[21];

    int length = 6;

    for (int i = 0 ; i < length ; i++){scanf("%d", &array[i]);}
    getchar();

    quick_sort(array, 0, length);

    for (int i = 0 ; i < length ; i++){printf("%d\n", array[i]);}
}