#include <stdio.h>

void merge_sort_array(int* array, int left, int mid, int right){
    int l_idx = mid - left + 1;
    int r_idx = right - mid;

    int kiri_arr[l_idx];
    int kanan_arr[r_idx];

    for (int i = 0 ; i < l_idx; i++){kiri_arr[i] = array[i + left];}
    for (int i = 0 ; i < r_idx; i++){kanan_arr[i] = array[mid + 1 + i];}

    int ind_kiri = 0, ind_kanan = 0, start = left;
    while (ind_kiri < l_idx && ind_kanan < r_idx){
        if (kiri_arr[ind_kiri] < kanan_arr[ind_kanan]){
            array[start] = kiri_arr[ind_kiri];
            ind_kiri++;
        }
        else{
            array[start] = kanan_arr[ind_kanan];
            ind_kanan++;
        }
        start++;
    }

    while (ind_kiri < l_idx){
        array[start] = kiri_arr[ind_kiri];
        ind_kiri++;
        start++;
    }

    while (ind_kanan < r_idx){
        array[start] = kanan_arr[ind_kanan];
        ind_kanan++;
        start++;
    }
}

void merge_sort(int* array, int left, int right){
    while (left < right){
        int mid = left + (right - left) / 2;

        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);

        merge_sort_array(array, left, mid, right);

        return;
    }
}

int binary_search(int* array, int find, int left, int right){
    int mid = left + (right - left) / 2;

    if (left > right){return -1;}

    if (array[mid] == find){return mid;}
    else if (array[mid] > find){
        return binary_search(array, find, left, mid - 1);
    }
    else{
        return binary_search(array, find, mid + 1, right);
    }
}


void bubble_sort(int* array, int length){
    for (int i = 0 ; i < length - 1; i++){
        for (int j = i+1; j < length ; j++){
            if (array[j] < array[i]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
int main(){
    int array[] = {2,5,4,3,1,9,6,7,8,10};

    merge_sort(array, 0, 9);

    // bubble_sort(array, 10);
    printf("Location : %d\n", binary_search(array, 9, 0, 9));

    for (int i = 0 ; i < 10; i++){printf("%d ", array[i]);}

}