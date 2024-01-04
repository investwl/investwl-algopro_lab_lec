// August 8th, 2023

#include <stdio.h>

int main(){
    // Figure 1
    printf("Simple Input\\Output Program\n============================\n");
    printf("Welcome to \"Algorithm and Programming\"!\n");
    // Figure 2
    char yourName[101];
    int yourAge;
    printf("Enter your name: ");
    scanf("%[^\n]s", &yourName);
    printf("Enter your age: ");
    scanf("%d", &yourAge);
    printf("Hi, %s!\n", yourName);
    // Figure 3
    float first, second;
    printf("Enter first number: ");
    scanf("%f", &first);
    printf("Enter second number: ");
    scanf("%f", &second);
    printf("Arithmetic Calculation Result:\n%f + %f = %.2f\n%f - %f = %.2f\n%f * %f = %.2f\n%f / %f = %.2f\n", first, second, (first + second), first, second, (first - second), first, second, (first * second), first, second, (first / second));
    // Figure 4
    int first_num = first; int second_num = second;
    printf("Number Checking Result: \nFirst Number: %d\nSecond Number: %d\n", first_num, second_num);
    printf("First Number is Odd Number: %d\nFirst Number is Even Number: %d\nSecond Number is Odd Number: %d\nSecond Number is Even Number: %d", (first_num % 2 == 1), (first_num % 2 == 0), (second_num % 2 == 1), (second_num % 2 == 0));
}