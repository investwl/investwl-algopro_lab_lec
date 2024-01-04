#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user{
    char role[10];
    char full_name[51];
    char email[51];
    union id{
        char student_id[11];
        char lecturer_id[6];
    } id;
};

struct user user_list[10];
int user_index = 0;

void menu(){printf("Bimay User Management\n===================\n1. Register new user\n2. Show all users\n3. Exit\nChoose >> ");}

int partition(int left, int right){
    int pivot = right;
    int swap = left;

    for (int i = left; i < pivot; i++){
        if (strcmp(user_list[i].role, user_list[pivot].role) < 0){
            struct user temp;
            temp = user_list[i];
            user_list[i] = user_list[swap];
            user_list[swap] = temp;
        }

        else if (strcmp(user_list[i].role, user_list[pivot].role) == 0) {
            if (strcmp(user_list[i].role, "Student") == 0){
                if (strcmp(user_list[i].id.student_id, user_list[pivot].id.student_id) < 0){
                    struct user temp;
                    temp = user_list[i];
                    user_list[i] = user_list[swap];
                    user_list[swap] = temp;
                }
            }
            else{
                if (strcmp(user_list[i].id.lecturer_id, user_list[pivot].id.lecturer_id) < 0){
                    struct user temp;
                    temp = user_list[i];
                    user_list[i] = user_list[swap];
                    user_list[swap] = temp;
                }
            }
            
        }

        swap++;
    }

    struct user temp;
    temp = user_list[swap];
    user_list[swap] = user_list[pivot];
    user_list[pivot] = temp;

    return swap;

    // char tumbal[100];
    // strcpy(tumbal, user_list[pivot].role);
    // strcpy(user_list[pivot].role, user_list[swap].role);
    // strcpy(user_list[swap].role, tumbal);
    // strcpy(tumbal, user_list[pivot].full_name);
    // strcpy(user_list[pivot].full_name, user_list[swap].full_name);
    // strcpy(user_list[swap].full_name, tumbal);
    // strcpy(tumbal, user_list[pivot].email);
    // strcpy(user_list[pivot].email, user_list[swap].email);
    // strcpy(user_list[swap].email, tumbal);

    // if (strcmp(user_list[pivot].role, "Student") == 0){
    //     strcpy(tumbal, user_list[pivot].id.student_id);
    //     strcpy(user_list[pivot].id.student_id, user_list[swap].id.student_id);
    //     strcpy(user_list[swap].id.student_id, tumbal);
    // }
    // else{
    //     strcpy(tumbal, user_list[pivot].id.lecturer_id);
    //     strcpy(user_list[pivot].id.lecturer_id, user_list[swap].id.lecturer_id);
    //     strcpy(user_list[swap].id.lecturer_id, tumbal);
    // }
    return swap;
}

void quick_sort(int left, int right){
    if (left > right){return;}
    int mid = partition(left, right);

    quick_sort(left, mid - 1);
    quick_sort(mid + 1, right);
}

void register_new(){
    char input_role[10];
    char input_full_name[51];
    char input_email[51];
    char id[11];
    while (1){
        printf("Role [Student | Lecturer]: ");
        scanf("%s", input_role); getchar();
        if (strcmp(input_role, "Student") != 0 && strcmp(input_role, "Lecturer") != 0){
            printf("Only 'Student' or 'Lecturer' is acceptable!\n");
        }
        else{break;}
    }
    while (1){
        printf("Full name [must not be empty]: ");
        scanf("%[^\n]", input_full_name); getchar();
        if (strlen(input_full_name) == 0){
            printf("Empty is not allowed.\n");
        }
        else{break;}
    }
    while (1){
        printf("Email [must not be empty]: ");
        scanf("%s", input_email); getchar();
        if (strlen(input_email) == 0){
            printf("Empty is not allowed.\n");
        }
        else {break;}
    }
    if (strcmp(input_role, "Student") == 0){
        while (1){
            printf("Student Code [must be 10 digits]: ");
            scanf("%s", id); getchar();
            int flag = 1;
            if (strlen(id) == 10){
                for (int a = 0 ; a < 10; a++){
                    if (id[a] < '0' || id[a] > '9'){
                        printf("Only 0 - 9 is accepted.\n");
                        flag = 0;
                        break;
                    }
                }
                if (flag){break;}
            }
            else{printf("10 digits!");}
        }
        strcpy(user_list[user_index].id.student_id, id);
    }
    else if (strcmp(input_role, "Lecturer") == 0){
        while (1){
            printf("Lecturer Code [stars with 'D' and follows by 4 digits]: ");
            scanf("%s", id); getchar();
            int flag = 1;
            if (id[0] == 'D' && strlen(id) == 5){
                for (int a = 1; a < 5; a++){
                    if (id[a] < '0' || id[a] > '9'){
                        printf("Only 0 - 9 is accepted.\n");
                        flag = 0;
                        break;
                    }
                }
                if (flag){break;}
            }
            else{printf("Must be followed by 'D' and 4 digits behind\n");}
        }
        strcpy(user_list[user_index].id.lecturer_id, id);
    }
    strcpy(user_list[user_index].role, input_role);
    strcpy(user_list[user_index].full_name, input_full_name);
    strcpy(user_list[user_index].email, input_email);
    user_index++;
    
    quick_sort(0, user_index);

    for (int k = 0; k < user_index; k++){printf("%s %s %s %s\n", user_list[k].role, user_list[k].full_name, user_list[k].email, user_list[k].id);}
}

void show_users(){
    if (user_index == 0){
        printf("Empty registered user data...");
        return;
    }
    printf("Role\t\t\tFull name\t\t\tE-mail\t\tUser ID\n");
    for (int k = 0 ; k < user_index ; k++){
        printf("%s\t\t\t%s\t\t\t%s\t\t\t%s\n", user_list[k].role, user_list[k].full_name, user_list[k].email, user_list[k].id);
    }
}

// multi conditional sorting utk exitnya
int main(){
    FILE *fptr;
    fptr = fopen("users.txt", "r");
    
    int loops = 1, is_null = 0;
    if (fptr == NULL){is_null = 1;}

    while (loops){
        menu();
        int user_input;
        scanf("%d", &user_input);
        switch (user_input){
            case 3:
                printf("Thanks for using this program\n");
                loops = 0;
                // masih ada lanjutan
                break;
            case 1:
                register_new();
                break;
            case 2:
                show_users();
                break;
        }
    }
}