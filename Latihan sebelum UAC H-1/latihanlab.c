#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mhs{
	char name[21];
	char nim[11];
	char gender;
	int umur;
	int hari;
	int bulan;
	int tahun;
	float ipk;
} mahasiswa[101];

void createprofile(){
	printf("Membuat profile mahasiswa :\n");
	while (1){
		printf("Masukkan nama [3 - 20 char]: ");
		char temp_name[21];
		scanf("%[^\n]", temp_name); getchar();
		if (strlen(temp_name) >= 3 && strlen(temp_name) <= 20){
			break;
		}
	}
	while (1){
		printf("Masukkan NIM[10 digits] : ");
		char temp_nim[11];
		scanf("%s", temp_nim);
		if (strlen(temp_nim) == 10){
			break;
		}
	}
	getchar();
	while (1){
		printf("Masukkan Jenis kelamin [L / P]: ");
		char temp_gender[2];
		scanf("%s", temp_gender); getchar();
		if (strcmp(temp_gender, "L") == 0 || strcmp(temp_gender, "P") == 0){
			break;
		}
	}
	while (1){
		printf("Masukkan umur[17 - 30] : ");
		int temp_umur;
		scanf("%d", &temp_umur); getchar();
		if (temp_umur >= 17 && temp_umur <= 30){
			break;
		}
	}
	while (1){
		printf("Masukkan tanggal lahir[dd/mm/yyyy]: ");
		int temp_hari, temp_bulan, temp_tahun;
		scanf("%0d/%d/%d", &temp_hari, &temp_bulan, &temp_tahun); getchar();
		if (temp_hari > 0 && temp_hari < 32 && temp_bulan > 0 && temp_bulan < 13 && temp_tahun > 0){
			break;
		}
	}
	while (1){
		printf("Masukkan IPK [0.00 - 4.00] : ");
		float ipk;
		scanf("%lf", &ipk);
		if (ipk >= 0 && ipk <= 4){
			break;
		}
	}
	getchar();
	printf("Profile created successfully\nEnter to continue...");
	getchar();
	getchar();
}

int menu(){
    printf("==================\nProfiling Mahasiswa\n==================\n1. Create Profile\n2. View Profile\n3. Search Profile\n4. Delete Profile\n5. Save Profile\n0. Exit\n>> ");
    int user_input;
    scanf("%d", &user_input); getchar();
    return user_input;
}

int main(){
	FILE* fptr = fopen("testdata.in", "r");
	int getout = 1;
    while (getout){
        switch(menu()){
        	case 0:
        		getout = 0;
				break;
        	case 1:
        		createprofile();
        		break;
        	case 2:
        		//viewprofile();
        		break;
        	case 3:
        		//searchprofile();
        		break;
        	case 4:
        		//deleteprofile();
        		break;
        	case 5:
        		//saveprofile();
        		break;
		}
		
    }
}
