/* belajar mandiri selection sort pas lagi lab hehe*/

#include <stdio.h>

void selection_sort(int *unsorted_list, int length);

int main(){
    int length;
    printf("Input length : ");
    scanf("%d", &length); getchar();
    int unsorted_list[length];
    printf("List of numbers, unsorted : ");
    for (int i = 0 ; i < length ; i++){
        scanf("%d", &unsorted_list[i]);
    }
    printf("Selection sorted : ");
    selection_sort(unsorted_list, length);
    for (int l = 0; l < length; l++){
        printf("%d ", unsorted_list[l]);
    }
}

void selection_sort(int *unsorted_list, int length){
    int tumbal;

    for (int j = 0; j < length - 1; j++){
        tumbal = j;
        for (int k = j + 1; k < length; k++){
            if (unsorted_list[k] < unsorted_list[tumbal]){
                tumbal = k;
            }
        }

        if (tumbal != j){
            int temp = unsorted_list[j];
            unsorted_list[j] = unsorted_list[tumbal];
            unsorted_list[tumbal] = temp;
        }
    }
}


/*
64 25 12 22 11

i = 0
tumbal = i = 0
j = 1

25 < 64 true

tumbal = j = 1

j = 2 

12 < 25 wrong

j = 3

22 < 25 true

tumbal = j = 3

j = 4

11 < 25 true

tumbal = j = 4

tumbal (4) != i (0) true, tukar jadi 11 25 12 22 64

------------------------------------------------------------
11 25 12 22 64
i = 1
tumbal = i = 1
j = 2


12 < 25 true

tumbal = j = 2

j = 3

22 < 12 false

j = 4

64 < 12 false
------------------------------------------
11 12 25 22 64
0   1   2   3    4

i = 2
tumbal = i = 2

j = 3
22 < 25 true

tumbal = j = 3

j = 4

64 < 22 false
--------------------------
11 12 22 25 64
0     1   2   3  4

i = 3
tumbal = i =  3

j = 4

64 < 25 false

-------------------
i = 4 false because for stop condtion = i < n - 1,
4 < 4 is false. the reason n - 1 because length is just like strlen
and index 4 cannot be checked bc there's nothing in index 5
*/