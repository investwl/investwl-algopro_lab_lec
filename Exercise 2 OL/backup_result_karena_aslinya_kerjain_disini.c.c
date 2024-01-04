#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length = 20;

char bought_code[21][6];
int bought_qty[21];
char bought_name[21][101];
int bought_price[21];
int bought_index = 0;

char dupe_code[21][6];
char dupe_name[21][101];
int dupe_qty[21];
int dupe_price[21];

void menu(){
    printf("Menu\n==========================\n1. Input sales\n2. Finish sales\n3. Exit\n>> ");
}

int binary_search(char code[][6], char find[6], int left, int right){
    if (left > right){return -1;}

    int mid = left + (right - left) / 2;

    if (strcmp(code[mid],find) == 0){
        return mid;
    }
    else if (strcmp(code[mid], find) > 0){binary_search(code, find, left, mid - 1);}
    else{binary_search(code, find, mid + 1, right);}
}

void input_sales(char code[][6], char name[][101], int* qty, int* price, int length){
    int index;
    while (1){
        char input_code[6];
        printf("Please input product code : ");
        scanf("%s", input_code);
        // gausah di sort lagi karena datanya udah sorted
        int tumbal_idx = binary_search(code, input_code, 0, length); 
        if (tumbal_idx == -1){
            printf("Product not found\n");
            getchar();
        }
        else{
            index = tumbal_idx;
            strcpy(bought_code[bought_index], input_code);
            strcpy(bought_name[bought_index], name[tumbal_idx]);
            bought_price[bought_index] = price[tumbal_idx];
            break;
        }

    }
    while (1){
        int buy_hmuch;
        printf("How many product would you buy : ");
        scanf("%d", &buy_hmuch); getchar();
        if (buy_hmuch >= 1 && buy_hmuch <= qty[index]){
            printf("Successfully save the purchased, please press enter to continue...");
            bought_qty[bought_index] = buy_hmuch;
            getchar();
            break;
        }
        else{
            printf("Quantity must atleast be 1 or not more than the quantity itself.\n");
            continue;
        }
    }

}

void merge_sort_array(int left, int mid, int right){
    int left_idx = mid - left + 1;
    int right_idx = right - mid;

    char a_idx[left_idx][101];
    char b_idx[right_idx][101];

    for (int i = 0 ; i < left_idx ; i++){strcpy(a_idx[i], bought_name[i + left]);}
    for (int i = 0 ; i < right_idx ; i++){strcpy(b_idx[i], bought_name[i + mid + 1]);}

    int kiri = 0, kanan = 0, start = left;

    while (kiri < left_idx && kanan < right_idx){
        if (strcmp(a_idx[kiri], b_idx[kanan]) < 0){
            strcpy(bought_name[start],a_idx[kiri]);
            kiri++;
        }
        else{
            strcpy(bought_name[start], b_idx[kanan]);
            kanan++;
        }
        start++;
    }

    while (kiri < left_idx){
        strcpy(bought_name[start], a_idx[kiri]); 
        kiri++; 
        start++;
    }

    while (kanan < right_idx){
        strcpy(bought_name[start], b_idx[kanan]);
        kanan++;
        start++;
    }
}

void merge_sort(int left, int right){
    while (left < right){
        int mid = left + (right - left) / 2;

        merge_sort(0, mid);
        merge_sort(mid + 1, right);

        merge_sort_array(left, mid, right);
        return;
    }
    
}

void finish_sale(char cust_name[]){
    int total_price = 0;
    int discount = 0;
    printf("Thank you %s,\n\nPurchase List\n=========\n\nProduct Name       Qty     Price       Subtotal\n", cust_name);
    for (int i = 0 ; i < bought_index; i++){
        int tumbal_subtotal = bought_qty[i] * bought_price[i];
        total_price += tumbal_subtotal;
        printf("%s       %d      %d      %d\n", bought_name[i], bought_qty[i], bought_price[i], tumbal_subtotal);
        for (int p = 0; p < length; p++){
            if (strcmp(bought_name[i], dupe_name[p]) == 0){
                dupe_qty[p] -= bought_qty[i];
                break;
            }
        }
    }
    if (total_price >= 1000000){discount = 10;}
    else if (total_price > 500000){discount = 8;}
    else if (total_price > 300000){discount = 5;}
    double discount_amt = (double) discount * (double) total_price / 100;
    double amount_due = (double) total_price - discount_amt;
    printf("\n");
    printf("Total           : %d\n", total_price);
    printf("Discount        : %d%%\n", discount);
    printf("Disc Amt        : %.2lf\n", discount_amt);
    printf("Amount Due      : %.2lf\n", amount_due);
    printf("\nPress Enter to Continue...");
    getchar();
    printf("\n");
    getchar();

}

int main(){
    FILE *fptr;
    fptr = fopen("data.txt", "r+");
    char code[length][6];
    char name[length][101];
    int qty[length];
    int price[length];
    char cust_name[31];
    // fscanf ini udah bener
    for (int i = 0 ; i < length; i++){
        fscanf(fptr, " %[^#]#%[^#]#%d#%d", code[i], name[i], &qty[i], &price[i]);
    }
    for (int l = 0; l < length; l++){
        strcpy(dupe_code[l], code[l]);
        strcpy(dupe_name[l], name[l]);
        dupe_qty[l] = qty[l];
        dupe_price[l] = price[l];
    }
    while (1){
        printf("Please insert your name (5-30 char) : ");
        char tumbal[31];
        scanf("%[^\n]", tumbal);
        if (strlen(tumbal) >= 5 && strlen(tumbal) <= 30){
            strcpy(cust_name, tumbal);
            break;
        }
        printf("Only 5 - 30 char!\n");
        getchar();
    }
    
    int input = 0;
    do{
        menu();
        scanf("%d", &input);
        if (input == 1){
            input_sales(code, name, qty, price, length);
            bought_index++;
        }
        else if (input == 2){
            merge_sort(0, bought_index - 1);
            finish_sale(cust_name);
            char write_to_new[110];
            sprintf(write_to_new, "%s.txt", cust_name);
            fptr = fopen(write_to_new, "a");
            for (int x = 0 ; x < bought_index; x++){
                fprintf(fptr, "%s#%s#%d#%d\n", bought_code[x], bought_name[x], bought_qty[x], bought_price[x]);
            }
            system("cls");
        }
    } while (input != 3);

    fptr = fopen("data.txt", "w");
    for (int d = 0; d < length; d++){
        fprintf(fptr, "%s#%s#%d#%d\n", dupe_code[d], dupe_name[d], dupe_qty[d], dupe_price[d]);
    }
    fclose(fptr);
}