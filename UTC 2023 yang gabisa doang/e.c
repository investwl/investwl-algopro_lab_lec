#include <stdio.h>
#include <string.h>

int main(){
    int s[3], r[3] = {4, 2 ,1}, b[3], max = -1, idx = 0;

    scanf("%d %d %d", &s[0], &s[1] , &s[2]);

    for (int i = 0 ; i < 3 ; i++){
        if (max < s[i] / r[i]){
            max = s[i] / r[i];
            idx = i;
        }
    }

    if (s[idx] % r[idx] != 0){max++;}

    for (int i = 0 ; i < 3 ; i++){
        b[i] = (max * r[i]) - s[i];
    }

    printf("%d %d %d %d\n", max, b[0], b[1], b[2]);
}