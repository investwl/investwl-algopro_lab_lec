#include <stdio.h>
#include <string.h>

int main(){
    // cara compare strings
    char nameA[101] = "ABC";
    char nameB[101] = "ABC";
    if (strcmp(nameA, nameB) == 0){
        printf("Namanya sama\n");
    }
    else{
        printf("Namanya gak sama\n");
    }

    // cara reassign variable's string
    // before reassign
    printf(nameA);
    printf("\n");
    // after reassign
    strcpy(nameA, "DEF");
    printf(nameA);
}