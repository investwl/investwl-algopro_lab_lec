#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct web{
	char method[5];
	char path[31];
	char controller[31];
	char function[31];
} webroute[101];

int index = 0;

int menu(){
	printf("Web Route Registry\n===============\n1. Register new route\n2. Show all routes\n3. Delete specific route\n4. Exit\n>> ");
	int user_input;
	scanf("%d", &user_input); getchar();
	return user_input;
}

int main(){
	FILE* fptr = fopen("routes.cfg", "r");
	if (fptr != NULL){
		while (fscanf(fptr, " %[^#]#%[^#]#%[^#]#%[^\n]", webroute[index].method, webroute[index].path, webroute[index].controller, webroute[index].function) != EOF){
			index++;
		}
	}
	
	while (1){
		switch (menu()){
			case 4:
				break;
			case 1:
				registernewroute();
				break;
			case 2:
				
				break;
			case 3:
				break;
		}
		
	}
	
	
}
