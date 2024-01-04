// kata terbalik
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

int main(){
    char s[31], o[31];
    scanf("%[^\n]s", s);
    int len = strlen(s), count = 0, io = 0, min;

    for (int i = 0 ; i < len ; i++){
        count++;
        if (s[i+1] == ' ' || i == len-1){
            min = 0;
            while (min < count){
                o[io] = s[i-min];
                io++; 
                min++;
            }
            count = 0;
        }
        else if (s[i] == ' '){
            o[io] = ' ';
            io++;
            count = 0;
        }
    }
    o[io] = '\0';
    io++;

    printf("%s\n", o);
}