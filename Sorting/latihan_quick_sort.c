 #include <stdio.h>
#include <string.h>

// struct mhs{
//     int nim[100];
//     int graduate[100];
//     char name[100][100];
// };

// int main()
// {
//     struct mhs siswa_1;
//     for (int i = 0 ; i < 10 ; i++){
//         siswa_1.nim[i] = i+100;
//         siswa_1.graduate[i] = i;
//         strcpy(siswa_1.name[i], "Bambang");
//     }
    
//     for (int i = 0 ; i < 10 ; i++){
//         printf("%d %s %d\n", siswa_1.nim[i], siswa_1.name[i], siswa_1.graduate[i]);    
//     }
    
// }


// int partition(int* array, int left, int right){
//     int pivot = right;
//     int swap = left;

//     for (int i = left; i < pivot; i++){
//         if (array[i] < array[pivot]){
//             int temp = array[i];
//             array[i] = array[swap];
//             array[swap] = temp;

//             swap++;
//         }
//     }

//     int temp = array[swap];
//     array[swap] = array[pivot];
//     array[pivot] = temp;

//     return swap;
// }

// void quick_sort(int* array, int left, int right){
//     if (left > right){return;}
//     int mid = partition(array, left, right);

//     quick_sort(array, left, mid - 1);
//     quick_sort(array, mid + 1, right);
// }

// int main(){
//     int array[10] = {8,2,3,4,9,7,6,1,10,5};

//     int length = 10;

//     quick_sort(array, 0, length - 1);

//     for (int i = 0 ; i < length; i++){
//         printf("%d ", array[i]);
//     }
// }