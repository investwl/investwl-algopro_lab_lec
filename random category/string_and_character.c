#include <stdio.h>

int main(){
    // string --> array of characters
    // ends with null char (\0)
    // declare string by declare what is the value when declaring one
    // char name[40] = "your name";
    // cant do name[40] = "your name"; below
    // kecuali mau pake function strcpy
    char name[] = "aaaaaaa"; // dari awal bisa kosongin array size
    printf("%s\n", name);
    // mau character handling biasa pake library <ctype.h> dan <string.h>
    // <ctype.h>
    // ada bbrp fungsi, isblank() --> return true kalo dlm () separates words
    // isdigit() --> true if digit
    // isalpha() --> true if letter
    // isalnum() --> true if digit or letter
    // islower() and isupper() --> self explanatory, lowercase or uppercase
    // tolower() ---> konversi huruf gede ke huruf kecil
    // toupper() --> konversi huruf kecl ke gede
    
    // string.h
    // string manipulation
    // strlen() --> cek brp panjang string length
    // strcpy(s1, s2) copy s2 ke s1
    // strncpy(s1, s2, n) copy first n characters from s2 to s1
    // strcat(s1, s2) masukkin s2 ke blkg s1
    // sprintf(variable_penampung, "format_stringnya", stringnya) powerful than strcat, bisa atur format output
    // strncat(s1, s2, n)
    // strcmp(s1, s2) compare string. if same = return 0
    

    
}