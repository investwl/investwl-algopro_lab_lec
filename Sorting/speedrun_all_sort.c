#include <stdio.h>

void bubble_sort(int* array, int length){
    for (int i = 0 ; i < length - 1; i++){
        for (int j = i+1; j < length; j++){
            if (array[j] < array[i]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void selection_sort(int* array, int length){
    int tumbal;
    for (int i = 0 ; i < length - 1; i++){
        tumbal = i;
        for (int j = i+1; j < length ; j++){
            if (array[j] < array[tumbal]){
                tumbal = j;
            }
        }

        if (tumbal != i){
            int temp = array[i];
            array[i] = array[tumbal];
            array[tumbal] = temp;
        }
    }
}

int partition(int* array, int left, int right){
    int pivot = right;
    int swap = left;

    for (int i = left; i < pivot; i++){
        if (array[i] < array[pivot]){
            int temp = array[i];
            array[i] = array[swap];
            array[swap] = temp;

            swap++;
        }
    }

    int temp = array[swap];
    array[swap] = array[pivot];
    array[pivot] = temp;

    return swap;
}

void quick_sort(int* array, int left, int right){
    if (left > right){return;}

    int mid = partition(array, left, right);

    quick_sort(array, left, mid - 1);
    quick_sort(array, mid + 1,  right);
}

void merge_sort_array(int* array, int left, int mid, int right){
    int left_idx = mid - left + 1;
    int right_idx = right - mid;

    int arr_left[left_idx];
    int arr_right[right_idx];

    for (int i = 0 ; i < left_idx; i++){arr_left[i] = array[i + left];}
    for (int i = 0 ; i < right_idx; i++){arr_right[i] = array[i + mid + 1];}

    int kiri = 0, kanan = 0, start = left;

    while (kiri < left_idx && kanan < right_idx){
        if (arr_left[kiri] < arr_right[kanan]){
            array[start] = arr_left[kiri];
            kiri++;
        }
        else{
            array[start] = arr_right[kanan];
            kanan++;
        }
        start++;
    }

    while (kiri < left_idx){
        array[start] = arr_left[kiri];
        start++;
        kiri++;
    }

    while (kanan < right_idx){
        array[start] = arr_right[kanan];
        start++;
        kanan++;
    }
}

void merge_sort(int* array, int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;

        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);

        merge_sort_array(array, left, mid, right);
    }
}

void insertion_sort(int* array, int length){
    int a, key, b;
    for (int a = 1; a < length; a++){
        key = array[a];
        b = a - 1;

        while (b >= 0 && array[b] > key){
            array[b + 1] = array[b];
            b--;
        }
        array[b + 1] = key;
    }
}

int main(){
    int array[] = {9,2,4,5,1,7,10,3,6,8};

    int length = 10;

    //bubble_sort(array, length);
    //selection_sort(array, length);
    //quick_sort(array, 0, length);
    //merge_sort(array, 0, length);

    // semua sort diatas works

    insertion_sort(array, length);

    for (int i = 0 ; i < length ; i++){printf("%d ", array[i]);}
    printf("\n\n");


}