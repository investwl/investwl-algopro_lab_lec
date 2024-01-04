#include <stdio.h>
#include <string.h>
int main(){
	int i = 0;
	char value[100][20];
	for (i = 0 ; i < 100; i++ ){
		strcpy(value[i], 'a');
		printf("%c\n", value[i]);
	}
}
