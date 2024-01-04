#include <stdio.h>
#include <string.h>
int main(){
	char kalimat[100];
	scanf("%[^\n]s", kalimat);
	int panjang = strlen(kalimat);
	int i, kiri = 0, kanan = panjang-1;
	int indicate = 1;
	while (kiri < kanan){
		if (kalimat[kiri] != kalimat[kanan]){
			printf("Not a palindrome.\n");
			indicate = 0;
			break;
		}
		kiri++;
		kanan--;
	}
	if (indicate){printf("A palindrome it is.\n");}
}
