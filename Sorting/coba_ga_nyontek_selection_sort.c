#include <stdio.h>

void selection_sort(int *the_list, int length);

int main(){
    int length;
    printf("Length = ");
    scanf("%d", &length);
    getchar();
    printf("Unsorted numbers = ");
    int the_list[length];
    for (int i = 0; i < length; i++){
        scanf("%d", &the_list[i]);
    }
    printf("Sorted by selection = ");
    selection_sort(the_list, length);
    for (int j = 0 ; j < length ; j++){
        printf("%d ", the_list[j]);
    }
}

void selection_sort(int *the_list, int length){
    int tumbal;

    for (int a = 0 ; a < length - 1 ; a++){
        tumbal = a;
        for (int b = 1 + a ; b < length ; b++){
            if (the_list[b] < the_list[a]){
                tumbal = b;
            }
        }
        if (tumbal != a){
            int temp = the_list[a];
            the_list[a] = the_list[tumbal];
            the_list[tumbal] = temp;
        }
    }
}