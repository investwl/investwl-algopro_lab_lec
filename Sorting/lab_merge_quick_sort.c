#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_null = 1; // global variable utk main_menu
int arr_num[10] = {0}; // global var biar gausah passing passing terus. {0} biar isinya semuanya 0

void print_array(){
    for (int i = 0 ; i < 10 ; i++){
        printf("%d", arr_num[i]);
        if (i != 9){printf(" ");}
    }
}

void randomize_number(){
    srand(time(NULL));

    for (int i = 0 ; i < 10 ; i++){
        int random_number = rand() % 101;
        arr_num[i] = random_number;
    }

    is_null = 0;
}

void merge(int* arr_num, int left, int right, int mid){
    int left_size = mid - left + 1; // + 1 biar midnya masuk juga utk left_size
    int right_size = right - mid;

    int left_array[left_size];
    int right_array[right_size];

    // loop utk isi array
    for (int i = 0 ; i < left_size ; i++){
        left_array[i] = arr_num[i+left];
    }

    for (int i = 0; i < right_size; i++){
        right_array[i] = arr_num[i+mid+1]; // tambah mid+1 supaya middlenya ga masuk dan kan dimulai setelah middle kalo yg kanan secara ascending
    }

    int left_idx = 0;
    int right_idx = 0;
    int start = left;

    // array kiri dan kanan masih ada element
    while(left_idx < left_size && right_idx < right_size){
        if (left_array[left_idx] < right_array[right_idx]){
            arr_num[start] = left_array[left_idx];
            left_idx++;
        }
        else{
            arr_num[start] = right_array[right_idx];
            right_idx++;
        }
        start++;
    }

    while (left_idx < left_size){ 
        arr_num[start] = left_array[left_idx];
        left_idx++;
        start++;
    }

    while (right_idx < right_size){
        arr_num[start] = right_array[right_idx];
        right_idx++;
        start++;
    }
}

void merge_sort(int arr_num[], int left, int right){
    // while utk validasi bisa dibagi 2 terus sampe elemennya sisa 1
    while (left < right){ // udah kayak palindrome
        int mid = left + (right - left) / 2; // tambah left supaya nanti kalo array bagian kanan, misal left 6 sama 9, kalo cuma right - left ntar takutnya ga cakup index arraynya

        // panggil recursionnya 2x, yg recursion pertama urus kiri, kalo kiri selesai pasti gabisa jalan lagi, maka dia bakal loncat ke recursion kedua yang ngerjain kanan
        merge_sort(arr_num, 0, mid);
        merge_sort(arr_num, mid + 1, right);
        merge(arr_num, left, right, mid);
        return; // wajib return biar ga infinite loop
    }

    
}

void main_menu(){
    int user_input = 0; // kalo lab nya kasih value -9 duluan incase ada error
    while (user_input != 4){
        printf("Sequence : ");

        if (is_null){printf("[null]");}
        else{print_array();}// call function that prints the array 
        printf("\n");

        printf("Sorter\n=================\n1. Randomize number\n2. Merge Sort\n3. Quick Sort\n4. Exit\n>> ");
        
        scanf("%d", &user_input);

        switch(user_input){
            case 4:
                printf("Bye.\n");
                break;
            case 1:
                randomize_number();
                break;
            case 2:
                merge_sort(arr_num, 0, 9); // yg right alternatifnya pake sizeof()
                break;
            case 3:

                break;
        }
    }
    
}

int main(){
    /* pake soal menu sorting */
    main_menu();
}