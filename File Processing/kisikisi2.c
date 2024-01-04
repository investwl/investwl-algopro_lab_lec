#include <stdio.h>

char checker(char book, int amt, int buy){
    if (buy == -100 || buy < amt){
        if (book == 'A'){
            return '#';
        }
        else if (book == 'B'){
            return '@';
        }
        else if (book == 'C'){
            return '!';
        }
    }
    if (buy == amt){
        return 'H';
    }
    else if (buy > amt){
        return 'K';
    }
}

int main(){
    FILE* fptr = fopen("testdata.in", "r");

    int test_case;
    fscanf(fptr, " %d", &test_case);
    for (int i = 0 ; i < test_case; i++){
        int size;
        fscanf(fptr, " %d", &size);
        char rak_buku[size][size];
        int amt[size][size];
        for (int j = 0 ; j < size ; j++){
            for (int k = 0 ; k < size; k++){
                fscanf(fptr, " %c %d", &rak_buku[j][k], &amt[j][k]);
            }
        }
        int x, y, buy;
        fscanf(fptr, " %d %d %d", &x, &y, &buy);
        x--;
        y--;

        printf("Case #%d:\n", i+1);
        for (int j = 0 ; j < size; j++){
            for (int k = 0 ; k < size; k++){
                if (j == x && k == y){
                    printf("%c ", checker(rak_buku[j][k], amt[j][k], buy));
                }
                else{
                    printf("%c ", checker(rak_buku[j][k], amt[j][k], -100));
                }
            }
            printf("\n");
        }
    }

    fclose(fptr);
}