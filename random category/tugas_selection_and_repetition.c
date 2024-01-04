#include <stdio.h>

int main(){
    int menu;
    while (1){
        printf("Selection and Repetition\n=========================\n1. Shape Area Calculator\n2. Grade Calculator\n0. Exit\n>> ");
        scanf("%d", &menu);
        if (menu == 1){
            while (1){
                int shape_choice;
                printf("Shape Area Calculator\n=========================\n1. Square\n2. Rectangle\n3. Triangle\n0. Back\n>> ");
                scanf("%d", &shape_choice);
                if (shape_choice == 1){
                    int side;
                    printf("Square\n===============\nInput side for square = ");
                    scanf("%d", &side);
                    printf("Square area = %d\n", side * side);
                }
                else if (shape_choice == 2){
                    int length, width;
                    printf("Rectangle\n===============\nInput length = ");
                    scanf("%d", &length); //incase error, tambahin \n
                    printf("Input width = ");
                    scanf("%d", &width);
                    printf("Rectangle area = %d\n", length * width);
                }
                else if (shape_choice == 3){
                    int base, height;
                    printf("Triangle\n===============\nInput base = ");
                    scanf("%d", &base);
                    printf("Input height = ");
                    scanf("%d", &height);
                    printf("Triangle area = %.2f\n", base * height * 0.5);
                }
                else if (shape_choice == 0){
                    break;
                }
                else{
                    printf("Error input, only 0, 1, 2, 3 that can be received. Try again\n");
                }
                int again;
                while (1){
                    printf("Calculate again? (1 = Yes / 0 = No)\n>> ");
                    scanf("%d", &again);
                    if (again == 0 || again == 1){
                        break;
                    }
                    else{
                        continue;
                    }
                }
                if (again == 0){break;}
                else{continue;}
                
            }
            printf("\n=====================================\nPress enter to continue\n");
            getchar();
            getchar();
            printf("\n");
        }
        else if (menu == 2){
            double math, english, history, art;
            while (1){
                printf("Enter Math score [0.0 - 10.0]\t\t= ");
                scanf("%lf", &math);
                printf("Enter English score [0.0 - 10.0]\t= ");
                scanf("%lf", &english);
                printf("Enter History score [0.0 - 10.0]\t= ");
                scanf("%lf", &history);
                printf("Enter Art score [0.0 - 10.0]\t\t= ");
                scanf("%lf", &art);
                if (math <= 10.0 && math >= 0.0 && english <= 10.0 && english >= 0.0 && history <= 10.0 && history >= 0.0 && art <= 10.0 && art >= 0.0){
                    break;
                }
            }
            double average;
            char grade;
            average = (math + english + history + art) / 4;
            if (average >= 9){grade = 'A';}
            else if (average >= 8){grade = 'B';}
            else if (average >= 7){grade = 'C';}
            else if (average >= 6){grade = 'D';}
            else{grade = 'F';}
            printf("Report Card\n=====================================\nMath\t\t= %.1lf\nEnglish\t\t= %.1lf\nHistory\t\t= %.1lf\nArt\t\t= %.1lf\nAverage\t\t= %.1lf\nFinal Grade\t= %c\n", math, english, history, art, average, grade);
            printf("\n=====================================\nPress enter to continue");
            getchar();
            getchar();
            printf("\n");
        }
        else if (menu == 0){
            printf("Thank you for operating this program!\n");
            break;
        }
        else{
            printf("Only 1, 2, 3, 0 are allowed to be input.\n");
            continue;
        }
    }
}