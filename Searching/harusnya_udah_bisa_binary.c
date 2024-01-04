#include <stdio.h>

int partition(int* array, int left, int right){
    int pivot_idx = right;
    int last_swap = left;

    for (int i = left; i < pivot_idx; i++){
        if (array[i] < array[pivot_idx]){
            int temp = array[i];
            array[i] = array[last_swap];
            array[last_swap] = temp;

            last_swap++;
        }
    }

    int temp = array[last_swap];
    array[last_swap] = array[pivot_idx];
    array[pivot_idx] = temp;

    return last_swap;
}

void quick_sort(int* array, int left, int right){
    if (left >= right){return;}

    int mid = partition(array, left, right);

    quick_sort(array, left, mid - 1);
    quick_sort(array, mid + 1, right);
}

void binary_search(int* array, int look, int left, int right){
    if (left > right){printf("Not found\n");}

    int mid = left + (right - left) / 2;

    if (array[mid] == look){printf("Location --> %d\n", mid);}
    else if (array[mid] > look){binary_search(array, look, left, mid - 1);}
    else{binary_search(array, look, mid + 1, right);}
}

int main(){
    int array[5] = {31293,239832,32334,22394,12938};

    quick_sort(array, 0, 4);
    for (int i = 0 ; i < 5; i++){printf("%d ", array[i]);}
    printf("\n");

    binary_search(array, 239832, 0, 4);
}