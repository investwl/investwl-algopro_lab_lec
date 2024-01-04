#include <stdio.h>
#include <string.h>

void menu();

void call_factorial();

unsigned long long int factorial(unsigned long long int result, unsigned long long int fac_input);

int palindrome(char *get_str);

void call_palindrome();

unsigned int gcd(unsigned int angka1, unsigned int angka2, unsigned int *the_gcd, unsigned int counter);

void call_gcd();

void bubble_sort(int *arr_list, unsigned int arr_length);

void call_bubble_sort();

unsigned int alt_gcd(); // gatau parameternya apa

int main(){
    int flag = 1;
    while (flag){
        menu();
        int user_input;
        scanf("%d", &user_input); getchar();
        switch(user_input){
            case 5:
                flag = 0;
                printf("Adios, kerjain OJ ato gak DM, DM lu jelek sial.\n");
                break;
            case 1:
                call_factorial();
                break;
            case 2:
                call_palindrome();
                break;
            case 3:
                call_gcd();
                // ada 1 function yg isinya 4 baris doang buat lakuin gcd, nanti dibuat di function namanya alt_gcd
                break;
            case 4:
                call_bubble_sort();
                break;
        }
    }
    
}

unsigned int alt_gcd(){
    return 0; // blom
}

void call_bubble_sort(){
    unsigned int arr_length;
    printf("Please input the array size: ");
    scanf("%u", &arr_length); getchar();
    int arr_list[arr_length];
    for (int k = 0 ; k < arr_length ; k++){
        scanf("%d", &arr_list[k]);
    }
    printf("Here's your sorted array: ");
    bubble_sort(arr_list, arr_length);
    for (int l = 0 ; l < arr_length ; l++){
        printf("%d", arr_list[l]);
        if (l != arr_length - 1){printf(" ");}
    }
    printf("\nPress enter to continue...");
    getchar();
    getchar();
}

void bubble_sort(int *arr_list, unsigned int arr_length){
    
    if (arr_length == 1){
        return;
    }

    int counter = 0;
    for (int p = 0; p < arr_length - 1; p++){
        if (arr_list[p] > arr_list[p + 1]){
            int temp = arr_list[p];
            arr_list[p] = arr_list[p + 1];
            arr_list[p + 1] = temp;
            counter++;
        }
        
    }
    if (counter == 0){
        return;
    }

    bubble_sort(arr_list, arr_length - 1);
}

void call_gcd(){
    printf("Input the 2 number you want to check : ");
    unsigned int angka1, angka2, the_gcd = 1;
    scanf("%u %u", &angka1, &angka2);
    // code dibawah basically if else
    unsigned int counter = (angka1 > angka2) ? angka2 : angka1;
    gcd(angka1, angka2, &the_gcd, counter);
    printf("The GCD of %u and %u is %u\n", angka1, angka2, the_gcd);
}

unsigned int gcd(unsigned int angka1, unsigned int angka2, unsigned int *the_gcd, unsigned int counter){
    if (counter <= 0){
        return 1;
    }
    else{
        if (angka1 % counter == 0 && angka2 % counter == 0){
            *the_gcd = counter;
            counter--;
            return gcd(angka1, angka2, the_gcd, counter);
        }
    }
}

void menu(){
    printf("Recursive functions\n====================\n1. Factorial\n2. Palindrome\n3. Greatest Common Divisor\n4. Bubble sort\n5. Exit\n>> ");
}

void call_factorial(){
    printf("Input the number you want : ");
    unsigned long long int fac_input;
    scanf("%llu", &fac_input);
    unsigned long long int result = 0;
    printf("The factorial of %llu is %llu !\n", fac_input, factorial(result, fac_input));
}

unsigned long long int factorial(unsigned long long int result, unsigned long long int fac_input){
    if (fac_input > 0){
        result = fac_input;
        return result * factorial(result, fac_input - 1);
    }
    else{
        return result;
    }
}

int palindrome(char *get_str){
    int left = 0, right = strlen(get_str) - 1;
    while (left < right){
        if (get_str[left] != get_str[right]){
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

void call_palindrome(){
    printf("Input the string you wanna check : ");
    char get_str[100];
    gets(get_str);
    if (palindrome(get_str)){
        printf("%s is a palindrome!\n", get_str);
    }
    else{
        printf("%s is not a palindrome!\n", get_str);
    }
}