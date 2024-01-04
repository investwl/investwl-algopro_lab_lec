#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct user_data{
    char role[9];
    char name[101];
    char email[101];
    union id{
        char phone[13];
        char company[101];
    } id;
};

struct user_data user_datas[100];
int index_data = 0;

char comparefunc(const void* a, const void* b){
    char *const *kata1 = a;
    char *const *kata2 = b;
    return (strcmp(*kata1, *kata2));
}

void menu(){printf("Menu:\n1. Register new user\n2. Show all users\n3. Search user\n4. Save to file and exit\n>> ");}

void register_new(char(*) comparefunc(const void*, const void*)){ // validasi blm
    struct user_data tumbal_data;
    strcpy(tumbal_data.role, " ");
    strcpy(tumbal_data.name, " ");
    strcpy(tumbal_data.email, " ");
    printf("Enter role (Contact / Business): ");
    scanf("%s", tumbal_data.role); getchar();
    printf("Enter full name : ");
    scanf("%[^\n]", tumbal_data.name); getchar();
    printf("Enter email address : ");
    scanf("%[^\n]", tumbal_data.email); getchar();
    if (strcmp(tumbal_data.role, "Contact") == 0){
        printf("Enter phone number : ");
        scanf("%[^\n]", tumbal_data.id.phone);
    }
    else if (strcmp(tumbal_data.role, "Business") == 0){
        printf("Enter company name : ");
        scanf("%[^\n]", tumbal_data.id.company);
    }


    user_datas[index_data] = tumbal_data; 
    index_data++;
    qsort(user_datas->role, index_data, sizeof(user_datas->role), comparefunc);
    if (strcmp(tumbal_data.role, "Contact") == 0){
        qsort(user_datas->id.phone, index_data, sizeof(user_datas->id.phone), comparefunc);
    }
    else if (strcmp(tumbal_data.role, "Business") == 0){
        qsort(user_datas->id.company, index_data, sizeof(user_datas->id.company), comparefunc);
    }
}

void show_all_users(){
    for (int i = 0 ; i < index_data; i++){
        printf("Role : %s\t|| Name : %s\t|| Email : %s\t", user_datas[i].role, user_datas[i].name, user_datas[i].email);
        if (strcmp(user_datas[i].role, "Contact") == 0){
            printf("|| Phone : %s\n", user_datas[i].id.phone);
        }
        else if (strcmp(user_datas[i].role, "Business") == 0){
            printf("|| Phone : %s\n", user_datas[i].id.company);
        }
    }
}

int main(){
    // FILE *fptr = fopen("users.txt", "r");
    // int flag = 1;
    // if (fptr == NULL){flag = 0;}
    // else{
    //     while (!feof(fptr)){
    //         fscanf(fptr, " %[^#]#%[^#]#%[^#]#%[^\n]", user_datas[index_data].role, user_datas[index_data].name, user_datas[index_data].email, user_datas[index_data].id);
    //         index_data++;
    //     }
    // }

    while (1){
        menu();
        int user_input;
        scanf("%d", &user_input);
        switch (user_input){
            case 4:
                // qsort(array, length, sizeof(array[0]), comparefunc);
                // fptr = fopen("users.txt", "w");
                // //...
                exit(0);
            case 1:
                register_new(comparefunc);
                //for (int a = 0 ; a < index_data; a++){printf("%s %s %s %s\n", user_data[a].role, user_data[a].name, user_data[a].email, user_data[a].id);}
                break;
            case 2:
                show_all_users();
                break;
            case 3:
                break;
        }
    }

    //fclose(fptr);
}