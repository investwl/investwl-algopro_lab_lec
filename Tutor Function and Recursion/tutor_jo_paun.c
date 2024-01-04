#include <stdio.h>


/* box in recursion */

// void top_bottom(int size, int index){
//     if (index == size){
//         return;
//     }
//     printf("#");
//     top_bottom(size, index + 1);
// }

// void side(int size, int index){
//     if (index == size){
//         return;
//     }
//     if (index == 0 || index == size - 1){
//         printf("#");
//     }
//     else{
//         printf(" ");
//     }
//     side(size, index + 1);
// }

// void box(int size, int index){
//     if (index == 0 || index == size - 1){
//         top_bottom(size, 0);
//         if (index == size - 1){
//             return;
//         }
//     }
//     else{
//         side(size, 0);
//     }
//     printf("\n");
//     box(size, index + 1);
// }

// int main(){
//     int size;
//     scanf("%d", &size); getchar();
//     box(size, 0);
// }





/* strlen in func */

// int panjang(char* mystr, int counter){
//     if (mystr[counter] == '\0'){
//         return 0;
//     }
//     else{
//         return 1 + panjang(mystr, counter + 1);
//     }
// }

// int main(){
//     char mystr[1000];
//     int counter = 0;
//     gets(mystr);
//     printf("strlen = %d\n", panjang(mystr, counter));

// }



/* max num in func */

// int max(int* list_angka, int length){
//     int max = 0;
//     for (int j = 0 ; j < length ; j++){
//         if (j == 0){
//             max = list_angka[j];
//             continue;
//         }
//         if (list_angka[j] > max){max = list_angka[j];}
//     }
//     return max;
// }

// int main(){
//     int length;
//     scanf("%d", &length); getchar();
//     int list_angka[length];
//     for (int i = 0 ; i < length ; i++){
//         scanf("%d", &list_angka[i]);
//     }
//     printf("result : %d\n", max(list_angka, length));
// }