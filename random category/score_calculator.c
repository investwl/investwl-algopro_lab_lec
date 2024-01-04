#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <time.h>
int main(){
    double time_spent = 0.0;
    // clock_t begin = clock();
    // clock_t end = clock();
    int quit_input = 1, proceed = 0, update_which_index, index = 0, counter = 0, tumbal_credit, tumbal_score, sum_credit = 0, sum_score = 0, delete_index, change_credit_to, change_score_to;
    char course_name[3][51];
    int course_credit[3], course_score[3];
    char tumbal_name[51];
    char y_or_n;
    char change_name_to[51];
    while (quit_input){
        printf("Score Calculator\n==================\n1. Add Course\n2. Course List\n3. Update Course\n4. Delete Course\n5. Total GPA\n6. Exit\n>> ");
        int user_input;
        scanf("%d", &user_input);
        getchar();
        switch (user_input){
            case 1:
                if (index == 3){
                    printf("Data is set max to 3. You can't fill any more data.\n");
                    break;
                }
                while (1){
                    printf("Input course name (course name length has to be greater than 5 characters): ");
                    scanf("%[^\n]s", tumbal_name);
                    getchar();
                    if (strlen(tumbal_name) <= 5){
                        printf("Character have to be greater than 5. Try again\n");
                        continue;
                    }
                    break;
                }
                while (1){
                    printf("Input course credit (course credit must be an even number): ");
                    scanf("%d", &tumbal_credit);
                    getchar();
                    if (tumbal_credit % 2 == 1){
                        printf("Not an even number. Try again!\n");
                        continue;
                    }
                    break;
                }
                while (1){
                    printf("Input course credit (course credit must be less than or equal to 100): ");
                    scanf("%d", &tumbal_score);
                    getchar();
                    if (tumbal_score >= 101){
                        printf("Course score bigger than 100. Try again!\n");
                        continue;
                    }
                    break;
                }
                while (1){
                    printf("Press 'y' to procceed and 'n' to cancel (case sensitive): ");
                    scanf("%c", &y_or_n);
                    getchar();
                    if (y_or_n == 'y'){
                        for (int j = 0 ; j < strlen(tumbal_name); j++){
                            course_name[index][j] = tumbal_name[j];
                        }
                        course_name[index][strlen(tumbal_name)] = '\0';
                        course_credit[index] = tumbal_credit;
                        course_score[index] = tumbal_score;
                        index++;
                    }
                    else if (y_or_n == 'n'){
                        proceed = 0;
                    }
                    else{continue;}
                    break;
                }
                break;
            case 2:
                counter = 0;
                for (int i = 0 ; i < index ; i++){
                    if (course_name[i] == ""){continue;}
                    printf("+=============================================+\n");
                    printf("| %d | %s | %d | %d |\n", counter+1, course_name[i], course_credit[i], course_score[i]);
                    counter++;
                }
                printf("+=============================================+\n");
                printf("Press enter to continue...\n");
                getchar();
                break;
            case 3:
                counter = 0;
                for (int i = 0 ; i < index ; i++){
                    printf("+=============================================+\n");
                    printf("| %d | %s | %d | %d |\n", i+1, course_name[i], course_credit[i], course_score[i]);
                }
                printf("+=============================================+\nInput course index you want to update: ");
                scanf("%d", &update_which_index);
                getchar();
                update_which_index--;
                while (1){
                    printf("Input course name (course name length has to be greater than 5 characters): ");
                    scanf("%[^\n]s", change_name_to);
                    getchar();
                    if (strlen(change_name_to) <= 5){
                        printf("Character have to be greater than 5. Try again\n");
                        continue;
                    }
                    break;
                }
                while (1){
                    printf("Input course credit (course credit must be an even number): ");
                    scanf("%d", &change_credit_to);
                    getchar();
                    if (change_credit_to % 2 == 1){
                        printf("Not an even number. Try again!\n");
                        continue;
                    }
                    break;
                }
                while (1){
                    printf("Input course credit (course credit must be less than or equal to 100): ");
                    scanf("%d", &change_score_to);
                    getchar();
                    if (change_score_to >= 101){
                        printf("Course score bigger than 100. Try again!\n");
                        continue;
                    }
                    break;
                }
                for (int j = 0 ; j < strlen(change_name_to); j++){
                    course_name[update_which_index][j] = change_name_to[j];
                }
                course_name[update_which_index][strlen(change_name_to)] = '\0';
                course_credit[update_which_index] = change_credit_to; 
                course_score[update_which_index] = change_score_to;
                counter = 0;
                for (int i = 0 ; i < index ; i++){
                    if (course_name[i] == ""){continue;}
                    printf("+=============================================+\n");
                    printf("| %d | %s | %d | %d |\n", counter+1, course_name[i], course_credit[i], course_score[i]);
                    counter++;
                }
                printf("+=============================================+\n");
                break;
            case 4:
                counter = 0;
                for (int i = 0 ; i < index ; i++){
                    if (course_name[i] == ""){continue;}
                    printf("+=============================================+\n");
                    printf("| %d | %s | %d | %d |\n", counter+1, course_name[i], course_credit[i], course_score[i]);
                    counter++;
                }
                printf("+=============================================+\n");
                printf("Input course index you want to delete: ");
                scanf("%d", &delete_index);
                getchar();
                delete_index--;
                for (int j = 0 ; j < strlen(course_name[update_which_index]); j++){
                    course_name[update_which_index][j] = '\0';
                }
                course_credit[delete_index] = 0;
                course_score[delete_index] = 0;
                index--;
                counter = 0;
                for (int i = 0 ; i < index ; i++){
                    if (course_name[i] == ""){continue;}
                    printf("+=============================================+\n");
                    printf("| %d | %s | %d | %d |\n", counter+1, course_name[i], course_credit[i], course_score[i]);
                    counter++;
                }
                printf("+=============================================+\n");
                printf("Press enter to continue...\n");
                break;
            case 5:
                for (int i = 0; i < index; i++){
                    sum_score += course_score[i];
                    sum_credit += course_credit[i];
                }
                sum_score /= 20;
                float total = (float)sum_score * (float)sum_credit * 0.5;
                printf("Your score is %.2f\nPress enter to continue...\n", total);
                getchar();
                break;
            case 6:
                quit_input = 0;
                break;
            default:
                printf("Can only receive input from 1 - 6. Try again!\n");
                break;
        }
    }
    // time_spent += (double)(end - begin);
    // printf("Time spent running program = %.2lf", time_spent);
}