
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
            strcpy(array[i], array[pivot_idx]);
            strcpy(array[pivot_idx], temp);