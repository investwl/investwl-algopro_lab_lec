/* ini file utk eksperimen cara kerja bubble sort, bljr sendiri
   ini pake iteration, baru nanti coba aplikasikan ke recurse */

// already success lorrrr
#include <stdio.h>

int main(){
    printf("Please input the array size : ");
    unsigned int user_input;
    scanf("%u", &user_input); getchar();
    int list_bubble[user_input];
    for (int i = 0 ; i < user_input ; i++){
        scanf("%d", &list_bubble[i]);
    }
    getchar();

    // bikin bubble sort recursion pake loop ini
    for (int j = 0 ; j < user_input; j++){
        for (int k = j+1; k < user_input; k++){
            if (list_bubble[j] > list_bubble[k]){
                int temp = list_bubble[j];
                list_bubble[j] = list_bubble[k];
                list_bubble[k] = temp;
            }
        }
    }


    printf("result = ");
    for (int a = 0; a < user_input ; a++){
        printf("%d ", list_bubble[a]);
    }
}