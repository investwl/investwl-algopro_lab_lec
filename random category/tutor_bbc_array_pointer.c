#include <stdio.h>

int main(){
    // array
    int n;
    scanf("%d\n", &n);
    int angka[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &angka[i]);
    }
    
    int ganjil[n/2], genap[n/2];
    int count_ganjil = 0, count_genap = 0;
    for (int j = 0; j < n; j++){
        if (angka[j] % 2 == 1){
            ganjil[count_ganjil] = angka[j];
            count_ganjil++;
        }
        else if (angka[j] % 2 == 0){
            genap[count_genap] = angka[j];
            count_genap++;
        }
    }

    printf("Ganjil = ");
    int k = 0; int l = 0;
    for (k; k < n/2; k++){
        printf("%d ", ganjil[k]);
    }
    printf("\nGenap = ");
    for (l; l < n/2; l++){
        printf("%d ", genap[l]);
    }
}