#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char contacts[101][256];

int contacts_length = 0; // counter berapa nama yang sudah diisi dalam contacts

void add_contact(){
    char name[256];
    printf("Enter contact name :\n>> ");
    scanf("%[^\n]", name);
    getchar();

    strcpy(contacts[contacts_length], name);
    contacts_length++;
}

void show_contacts(){
    printf("Contacts : \n");
    for (int i = 0 ; i < contacts_length; i++){printf("%d. %s\n", i+1, contacts[i]);}
    printf("===============================\nPress enter to continue...");
    getchar();
}

void linear_search(){
    printf("Look for contact name : ");
    char look_for[256];
    scanf("%[^\n]", look_for); getchar();
    int flag = 1;
    for (int i = 0 ; i < contacts_length ; i++){
        if (strcmp(contacts[i], look_for) == 0){
            printf("Found at index %d\n", i);
            flag = 0;
            break;
        }
    }
    if (flag){printf("No contact name inside contacts.\n");}
    printf("Press enter to continue..."); getchar();
}

int partition(char array[][256], int left, int right){ // gunanya buat bagi 2 array
    int pivot_idx = right;
    int last_swap = left;

    for (int i = left; i < pivot_idx ; i++){
        if (strcmp(array[i] , array[pivot_idx]) < 0){
            char temp[256];
            strcpy(temp, array[i]);
            strcpy(array[i], array[last_swap]);
            strcpy(array[last_swap], temp);

            last_swap++;
        }
    }

    char temp[256];
    strcpy(temp, array[pivot_idx]);
    strcpy(array[pivot_idx], array[last_swap]);
    strcpy(array[last_swap], temp);

    return last_swap;
}

void quick_sort(char array[][256], int left, int right){
    if (left >= right){return;}

    int center = partition(array, left, right);

    quick_sort(array, left, center - 1);
    quick_sort(array, center + 1, right);

}

void binary_search(char array[][256], char* find, int left, int right){
    int mid = left + (right - left) / 2;

    if (left > right){printf("Not found\n"); return;}

    if (strcmp(array[mid], find) == 0){printf("Found at index %d\n", mid);}
    else if (strcmp(array[mid], find) > 0){binary_search(array, find, left, mid - 1);}
    else{binary_search(array, find, mid + 1, right);}
}

void main_menu(){
    int input = 0;

    do{
        printf("Phonebook Menu :\n1. Add contact\n2. Search contact (linear)\n3. Search contact (binary)\n4. Search contact (interpolation)\n5. Display all contacts\n6. Exit\n>> ");
        scanf("%d", &input);
        getchar();
        if (input == 1){
            add_contact();
        }
        else if (input == 2){
            linear_search();
        }
        else if (input == 3){
            quick_sort(contacts, 0, contacts_length - 1);
            printf("Search for contact name : ");
            char find[256];
            scanf("%[^\n]", find);
            getchar();
            binary_search(contacts, find, 0, contacts_length - 1);
        }
        else if (input == 4){

        }
        else if (input == 5){
            show_contacts();
        }
    } while (input != 6);
}

int main(){
    // start main menu
    main_menu();
}