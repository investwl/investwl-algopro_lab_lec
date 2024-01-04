#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    // malloc, calloc, realloc, free

    // void * malloc (size_of_datatype)
    // inget karena void, nanti harus typecasting 

    // alokasi utk 1 int

    // variabel yang buat nampung malloc harus dlm bentuk ptr
    int* i;
    // (int * ) --> typecasting
    i = (int *) malloc(sizeof(int));

    // alokasi 10 integers
    int* j;
    j = (int *) malloc(sizeof(int) * 10);

    // alternatif lain --> calloc
    // calloc (ukuran per panjang, sizeof datatype)
    j = calloc(10, sizeof(int));

    // kalo mau pake lagi memorinya buat variable lain pake realloc

    j = realloc(i, sizeof(int)); // yg argumen tengah sesuaiin sama target (j)

    // always frree after malloc

    free(i); free(j);

    // yg diatas kalo 1 dimensi, kalo 2 dimensi 
    
    
}