#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// udh bener anjay mabar

int binary_search(char nama_buku[101][11], char* find, int left, int right){
    if (left > right){return -1;}

    int mid = left + (right - left) / 2;

    if (strcmp(nama_buku[mid], find) == 0){return mid;}

    else if (strcmp(nama_buku[mid], find) > 0){return binary_search(nama_buku, find, left, mid - 1);}

    else if (strcmp(nama_buku[mid], find) < 0){return binary_search(nama_buku, find, mid + 1, right);}
}

int main(){
    FILE* fptr = fopen("testdata.in", "r");
    int test_case;
    fscanf(fptr, " %d", &test_case);
    for (int a = 0 ; a < test_case; a++){
        int rak_buku;
        fscanf(fptr, " %d", &rak_buku);
        char nama_buku[101][11];
        int jumlah_buku[101];
        int unique_index = 0;
        for (int i = 0 ; i < rak_buku; i++){
            char temp_nama[11];
            int temp_jumlah;
            fscanf(fptr, " %s %d", temp_nama, &temp_jumlah);
            int check = binary_search(nama_buku, temp_nama, 0, unique_index - 1);
            if (check != -1){
                jumlah_buku[check] += temp_jumlah;
                continue;
            }
            else{
                strcpy(nama_buku[unique_index], temp_nama);
                jumlah_buku[unique_index] = temp_jumlah;
            }
            unique_index++;
        }

        // for (int i = 0 ; i < unique_index; i++){
        //     printf("%s %d\n", nama_buku[i], jumlah_buku[i]);
        // }

        char buku_dicari[11];
        fscanf(fptr, " %[^\n]", buku_dicari);
        int look = binary_search(nama_buku, buku_dicari, 0, unique_index - 1); 
        if (look != -1){
            printf("%s %d\n", buku_dicari, jumlah_buku[look]);
        }
        else{
            printf("%s %d\n", buku_dicari, -1);
        }
    }
    

    fclose(fptr);
}