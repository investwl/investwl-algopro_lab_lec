#include <stdio.h>

int main(){
	int test_case;
	scanf("%d", &test_case); getchar();
	int i;
	int inputan, tumbal;
	int count = 0;
	int zero_counter = 0;
	for (i = 0; i < test_case; i++){
		scanf("%d", &inputan);
		tumbal = inputan;
		while (inputan % 10 != 0){
			count++;
			inputan /= 10;
		}
		for (i = 0; i < count; i++){
			printf("%d", tumbal % (10 * count-1-i));
		}
	}
}
