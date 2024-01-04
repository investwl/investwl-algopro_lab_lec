#include <stdio.h>
#include <string.h>

struct user{
    char role[12];
    char name[50];
    char email[50];
    union id{
        char st_id[11];
        int lec_id[6];
    };
};

void menu(){
    printf("Bimay User Management\n===================\n1. Register new user\n2. Show all users\n3. Exit\nChoose >> ");
}

int is_numeric(char arr[], int len, int start){
    for (int i = start ; i < len ; i++){
        if (arr[i] < '0' || arr[i] > '9'){
            return 0;
        }
    }
    return 1;
}

void regist(){
    char role[12] = "";
    char name[50] = "";
    char email[50] = "";
    char student_id[11] = "";
    char lecturer_id[6] = "";
    int student_len = sizeof(student_id) / sizeof(student_id[0]);
    int lec_len = sizeof(lecturer_id) / sizeof(lecturer_id[0]); 

    do{
        printf("Role : ");
        scanf("%s", role); getchar();
    }while(strcmp(role, "Student") != 0 && strcmp(role, "Lecturer") != 0);

    do{
        printf("Name : ");
        scanf("%[^\n]", name); getchar();
    }while (strlen(name) == 0);

    do{
        printf("Email : ");
        scanf("%s", email); getchar();
    }while (strlen(email) == 0);

    if(strcmp(role, "Student") == 0){
        do{
            printf("Student id : ");
            scanf("%s", student_id);
        }while (strlen(student_id) != 10 || !is_numeric(student_id, student_len - 1, 0)); 
    }
    else{
        do{
            printf("Lecturer id : ");
            scanf("%s", lecturer_id);
        }while(lecturer_id[0] != 'D' || strlen(lecturer_id) != 5 || !is_numeric(lecturer_id, lec_len - 1, 1));
    }
}

int main(){

    FILE *fptr = fopen("users.txt", "r");
    struct user user_list[10];
    int index = 0;
    // while (feof(fptr) == 0){ // supaya scanf sampe abis filenya, cek sampe file eof
    //     fscanf(fptr, "%[^\n]\n", &str);
    // }

    int user_input = -9;
    do{
        menu();
        scanf("%d", &user_input);
        switch(user_input){
            case 1:
                regist();
                break;
            case 2:
                break;
            case 3:
                break;
        }
    } while (user_input != 3);

    fclose(fptr);
}