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


// sort based on role and id
int compare_user(struct user_data user1, struct user_data user2){
    int hasilrole = strcmp(user1.role, user2.role);

    if (hasilrole != 0){return hasilrole;}
    
    if (strcmp(user1.role, "Contact") == 0){
        return strcmp(user1.id.phone, user2.id.phone);
    }
    else{
        return strcmp(user1.id.company, user2.id.company);
    }
}

int partition(int left, int right){
    int pivot = right, swap = left;

    for (int i = left ; i <= right; i++){
        if (i == pivot){continue;}
        if (compare_user(user_datas[i], user_datas[pivot]) < 0){
            struct user_data temp = user_datas[i];
            user_datas[i] = user_datas[swap];
            user_datas[swap] = temp;

            swap++;
        }
    }
    struct user_data temp = user_datas[pivot];
    user_datas[pivot] = user_datas[swap];
    user_datas[swap] = temp;

    return swap;
}

void quicksort(int left, int right){
    if (left > right){return;}

    int mid = partition(left, right);

    quicksort(left, mid - 1);
    quicksort(mid + 1, right);
}

void binary_search(char look[101], int left, int right){
    if (left > right){
        printf("No user found!\n");
        return;
    }
    int mid = left + (right - left) / 2;
    if (strcmp(user_datas[mid].name, look) == 0){
        if (strcmp(user_datas[mid].role, "Contact") == 0){
            printf("User found!\nRole : %s\nName : %s\nEmail : %s\nID : %s\n", user_datas[mid].role, user_datas[mid].name, user_datas[mid].email, user_datas[mid].id.phone);
        }
        else if (strcmp(user_datas[mid].role, "Business") == 0){
            printf("User found!\nRole : %s\nName : %s\nEmail : %s\nID : %s\n", user_datas[mid].role, user_datas[mid].name, user_datas[mid].email, user_datas[mid].id.company);
        }
        return;
    }
    else if (strcmp(user_datas[mid].name, look) < 0){
        binary_search(look, left, mid - 1);
    }
    else{
        binary_search(look, mid + 1, right);
    }
}

void initial_user(){
    FILE *fptr = fopen("users.txt", "r");
    if (fptr != NULL){
        while (!feof(fptr)){
            char tumbal[2560];
            fscanf(fptr, " %[^\n]", tumbal);
            //printf("%s\n", tumbal);
            if (tumbal == NULL || strlen(tumbal) == 0){
                return;
            }
            char t_role[9];
            char t_name[256];
            char t_email[256];
            char t_id[256];
            sscanf(tumbal, " %[^#]#%[^#]#%[^#]#%[^\n]", t_role, t_name, t_email, t_id);        
            strcpy(user_datas[index_data].role, t_role);
            strcpy(user_datas[index_data].name, t_name);
            strcpy(user_datas[index_data].email, t_email);
            if (strcmp(t_role, "Contact") == 0){
                strcpy(user_datas[index_data].id.phone, t_id);
            }
            else if (strcmp(t_role, "Business") == 0){
                strcpy(user_datas[index_data].id.company, t_id);
            }
            index_data++;
        }
    }
    fclose(fptr);
}

void menu(){
    printf("Menu:\n1. Register new user\n2. Show all users\n3. Search user\n4. Save to file and exit\n>> ");
}

void register_new(){ // validasi blm
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

    quicksort(0, index_data - 1);
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

void search_user(){
    if (index_data == 0){
        printf("No user data!\n");
        return;
    }
    printf("Input the name you're looking for : ");
    char find_who[101];
    scanf("%[^\n]", find_who); getchar();
    binary_search(find_who, 0, index_data - 1);
}

void save_to_file(){
    FILE *fptr = fopen("users.txt", "w");
    for (int u = 0; u < index_data; u++){
        if (strcmp(user_datas[u].role, "Contact") == 0){
            fprintf(fptr, "%s#%s#%s#%s\n", user_datas[u].role, user_datas[u].name, user_datas[u].email, user_datas[u].id.phone);
        }
        else if (strcmp(user_datas[u].role, "Business") == 0){
            fprintf(fptr, "%s#%s#%s#%s\n", user_datas[u].role, user_datas[u].name, user_datas[u].email, user_datas[u].id.company);
        }
    }
    fclose(fptr);
}


int main(){
    int keluar = 1;
    initial_user();
    while (keluar){
        menu();
        int user_input;
        scanf("%d", &user_input);
        getchar();
        //printf("%d\n", index_data);
        switch (user_input){
            case 4:
                save_to_file();
                keluar = 0;
                break;
            case 1:
                register_new();
                break;
            case 2:
                show_all_users();
                break;
            case 3:
                search_user();
                break;
        }
    }

    //fclose(fptr);
}