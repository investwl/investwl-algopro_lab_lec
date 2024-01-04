#include <stdio.h>
#include <string.h>

int count_walk(char *line, int kiri, int kanan, int panjang, int *count_total, int *count_kiri, int *count_kanan);

int main(){
    // int length;
    // scanf("%d",&length); getchar();
    char line[100];
    scanf("%s", line);
    int panjang = strlen(line) - 1;
    int count_total = 0, count_kiri = 0, count_kanan = 0;
    int posisi;
    for (int i = 0 ; i <= panjang ; i++){
        if (line[i] == 'X'){
            posisi = i;
            break;
        }
    }
    int kiri = posisi - 1;
    int kanan = posisi + 1;
    int result = count_walk(line, kiri, kanan, panjang, &count_total, &count_kiri, &count_kanan);
    printf("Count all mixue from X's house : %d\nMixue at left X's house : %d\nMixue at right X's house : %d\n", count_total, count_kiri, count_kanan);
}

int count_walk(char *line, int kiri, int kanan, int panjang, int *count_total, int *count_kiri, int *count_kanan){
    if (kiri < 0 && kanan > panjang){
        return 1;
    }
    // else if (kiri != -1 && kanan != panjang){
    if (line[kiri] == 'm'){
        *count_total += 1;
        *count_kiri += 1;
    }
    if (line[kanan] == 'm'){
        *count_total += 1;
        *count_kanan += 1;
    }
    return count_walk(line, kiri - 1, kanan +  1, panjang, count_total, count_kiri, count_kanan);
    // }
    // else if (kiri == -1){
    //     if (line[kanan] == 'm'){
    //         *count += 1;
    //     }
    //     return count_walk(line, kiri, kanan -  1, panjang, count);
    // }
    // else if (kanan == panjang){
    //     if (line[kiri] == 'm'){
    //         *count += 1;
    //     }
    //     return count_walk(line, kiri - 1, kanan, panjang, count);
    // }

}