#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
	srand(time(NULL));
	int status = 1;
	int index_cust = 0;
	int count_customer = 0;
	int profit = 0;
	while (status){
		int i, j;
		int user_input;
		printf("Menu:\n1. Accept customer\n2. Show all customers\n3. Update customer order status\n4. Exit\n>> ");
		printf("Dine In Order Management\n=======================\nCount of customer(s): %d people\nCurrent profit: USD %d\n\n", count_customer, profit);
		scanf("%d", &user_input); getchar();
		char cust_coll[100][1];
		char cust_order_stat[100][20];
		int input_cus_update;
		char waiter_name[50];
		char chef_name[50];
		int est_current_cook;
		char stat_in_short[100][20];
		int input_payment;
		switch (user_input){
			case 4:
				// no problem
				status = 0;
				break;
			case 1:
				// no problem
				cust_coll[index_cust][0] = (rand() % 26) + 65;
				cust_coll[index_cust][1] = (rand() % 26) + 65;
				strcpy(cust_order_stat[index_cust], "Ready to order");
				strcpy(stat_in_short[index_cust], "Ready to order");
				index_cust++;
				count_customer++;
				break;
			case 2:
				// jesus christ bugnya kalo tiap kali jalan jadi broken if cust > 1
				if (count_customer == 0){
					printf("No customers yet...\n");
					break;
				}
				else{
					printf("==============================================================\n");
					printf("| No | Name | Status                                         |\n");
					printf("==============================================================\n");
					for (i = 0; i < index_cust; i++){
						printf("| %d |  %c%c  | %s                     |\n", i+1, cust_coll[i][0], cust_coll[i][1], cust_order_stat[i]);
					}
					printf("==============================================================\n");
					for (i = 0 ; i < index_cust ; i++){
						if (strcmp(stat_in_short[i], "Paid the food") == 0){
							for (j = i ; j < count_customer; j++){
								strcpy(cust_coll[i], cust_coll[i+1]);
								strcpy(stat_in_short[i], stat_in_short[i+1]);
								strcpy(cust_order_stat[i], cust_order_stat[i+1]);
							}
							count_customer--;
							count_customer--;
							printf("==============================================================\n");
							printf("| No | Name | Status                                         |\n");
							printf("==============================================================\n");
							for (i = 0; i < count_customer; i++){
								printf("| %d |  %c%c  | %s                                             |\n", i+1, cust_coll[i][0], cust_coll[i][1], cust_order_stat[i]);
							}
							printf("==============================================================\n");
						}	
					}
				}
				break;
			case 3:
				if (count_customer == 0){
					printf("No customer yet...\n");
					break;
				}
				else{
					printf("==============================================================\n");
					printf("| No | Name | Status                                         |\n");
					printf("==============================================================\n");
					for (i = 0; i < count_customer; i++){
						printf("| %d |  %c%c  | %s                                             |\n", i+1, cust_coll[i][0], cust_coll[i][1], cust_order_stat[i]);
					}
					printf("==============================================================\n");
					printf("Select customer that you want to update his / her status: ");
					scanf("%d", &input_cus_update); getchar();
					input_cus_update--;
					if (strcmp(stat_in_short[input_cus_update], "Ready to order") == 0){
						while (1){
							printf("Enter the waiter name that handles the order: ");
							scanf("%[^\n]s", waiter_name); getchar();
							if (strlen(waiter_name) < 3 && strlen(waiter_name) > 50){
								continue;
							}
							else if (waiter_name[0] == 'M'){
								if (waiter_name[1] == 'r' || waiter_name[1] == 's'){
									if (waiter_name[2] == '.'){
										if (strlen(waiter_name) > 3){
											strcpy(stat_in_short[input_cus_update], "Taking order");
											sprintf(cust_order_stat[input_cus_update], "Taking order, PIC: %s", waiter_name);
											break;
										}
									}
								}
							}
						}
					}
					else if (strcmp(stat_in_short[input_cus_update], "Taking order") == 0){
						while (1){
							printf("Enter the chef name that handles the order: ");
							scanf("%[^\n]s", chef_name); getchar();
							if (strlen(chef_name) < 3 && strlen(chef_name) > 50){
								continue;
							}
							else{
								while (1){
									printf("Enter the duration of cooking process needs [in minutes]: ");
									scanf("%d", &est_current_cook); getchar();
									if (est_current_cook <= 0){
										continue;
									}
									else{
										strcpy(stat_in_short[input_cus_update], "In process of cooking");
										sprintf(cust_order_stat[input_cus_update], "In process of cooking, PIC: %s, Estimation: %d minutes", chef_name, est_current_cook);
									}
									break;
								}
							}
							break;
						}
					}
					else if (strcmp(stat_in_short[input_cus_update], "In process of cooking") == 0){
						while (1){
							printf("Enter the waiter name that handles the order: ");
							scanf("%[^\n]s", waiter_name); getchar();
							if (strlen(waiter_name) < 3 && strlen(waiter_name) > 50){
								continue;
							}
							else if (waiter_name[0] == 'M'){
								if (waiter_name[1] == 'r' || waiter_name[1] == 's'){
									if (waiter_name[2] == '.'){
										if (strlen(waiter_name) > 3){
											strcpy(stat_in_short[input_cus_update], "Delivered to customer");
											sprintf(cust_order_stat[input_cus_update], "Delivered to customer, PIC: %s", waiter_name);
											break;
										}
									}
								}
							}
						}
					}
					else if (strcmp(stat_in_short[input_cus_update], "Delivered to customer") == 0){
						while (1){
							printf("Enter the payment amount the customer paid: ");
							scanf("%d", &input_payment); getchar();
							if (input_payment <= 0){
								continue;
							}
							break;
						}
						strcpy(stat_in_short[input_cus_update], "Paid the food");
						sprintf(cust_order_stat[input_cus_update], "Paid the food");
						profit += input_payment;
//						count_customer++;
						break;
					}
					else if ((strcmp(stat_in_short[input_cus_update], "Paid the food")) == 0){
						printf("Customer has paid the order, you cannot update the customer data...\n");
					}
				}
				break;
		}
	}
}
