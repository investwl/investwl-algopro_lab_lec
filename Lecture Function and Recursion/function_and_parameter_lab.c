#include <stdio.h>
#include <stdbool.h>

int fibbonaci(int n);

int main(){
    // recursive 
    /*
    manggil dirinya sendiri
    langsung bljr fibbonaci

    pake iterative dlu
    */


    // int n1 = 0, n2 = 1, n3, number = 5;
    // for (int i = 2 ; i < number ; i++){
    //     n3 = n1 + n2;
    //     printf("%d\n", n3);
    //     n1 = n2;
    //     n2 = n3;
    // }
    printf("angka : %d\n", fibbonaci(10));

}

int fibbonaci(int n){
    if (n <= 1){
        return n;
    }
    else{
        return fibbonaci(n-1) + fibbonaci(n-2);
    }
}











// void greetings();

// int addition();

// bool check();

// int main(){
//     /* function
//     bisa dipanggil terus utk run code inside it
//     misal mau manggil printf("idhifhihai"); 10x
//     brti kita panggil function itu 10x
//     */

//     // scope = rang sebuah variable bisa diakses
//     greetings();
//     int result = addition();
//     printf("The value of a + b is %d\n", result);
//     bool valid = check();
//     if (valid){
//         printf("Valid\n");
//     }
//     else{
//         printf("Not valid\n");
//     }
// }

// void greetings(){
//     printf("Hello world!\n");

// }

// int addition(){
//     int a = 10;
//     int b = 9;
//     int c = a + b;
//     return c;
// }

// bool check(){
//     int a  = 10, b = 5;
//     bool valid = a > b;
//     return valid;
//     // or return a > b;
// }