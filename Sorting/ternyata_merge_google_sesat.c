// latihan merge sesuai aslab

#include <stdio.h>

void merge_sort_array(int* array, int left, int mid, int right){
    int left_arr_idx = mid - left + 1;
    int right_arr_idx = right - mid;

    int arr_kiri[left_arr_idx];
    int arr_kanan[right_arr_idx];

    for (int i = 0 ; i < left_arr_idx; i++){arr_kiri[i] = array[i + left];}
    for (int i = 0 ; i < right_arr_idx; i++){arr_kanan[i] = array[i + mid + 1];}

    int left_idx = 0;
    int right_idx = 0;
    int start = left;

    while (left_idx < left_arr_idx && right_idx < right_arr_idx){
        if (arr_kiri[left_idx] < arr_kanan[right_idx]){
            array[start] = arr_kiri[left_idx];
            left_idx++;
        }
        else{
            array[start] = arr_kanan[right_idx];
            right_idx++;
        }
        start++;
    }

    while (left_idx < left_arr_idx){
        array[start] = arr_kiri[left_idx];
        left_idx++;
        start++;
    }

    while (right_idx < right_arr_idx){
        array[start] = arr_kanan[right_idx];
        right_idx++;
        start++;
    }
}

void merge_sort(int* array, int left, int right){
    while (left < right){
        int mid  = left + (right - left) / 2;

        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);

        merge_sort_array(array, left, mid, right);
        return;
    }
}

int main(){
    int array[10] = {10,3,5,6,2,7,4,9,8,1};
    int length = 10;

    merge_sort(array, 0, length - 1);
    for (int i = 0; i < length ; i++){printf("%d ", array[i]);}
}