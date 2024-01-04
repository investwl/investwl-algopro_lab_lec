#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char name[51]; int n;
    printf("Enter name : ");
    scanf("%[^\n]s", &name);
    getchar();
    printf("Enter n : ");
    scanf("%d", &n);
    // int yang_dioutput = strlen(name) - n;
    for (int i = strlen(name) - n ; i < strlen(name); i++){
        printf("%c", name[i]);
    }
}