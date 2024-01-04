#include <stdio.h>
#include <string.h>

struct info_mhs{
    char name[30][30];
    int lokasi[30][30][1];
} info;

void menu(){
    printf("===============================\nMenu\n1. Lihat info mahasiswa\n2. Lihat denah\n3. Tambah mahasiswa\n0. Exit\n>> ");
}

void tambah_mahasiswa(){
    int tanda = 0;
    while (1){
        if (tanda == 1){
            getchar();
            tanda = 0;
        }
        char nama_mhs[30];
        printf("Input name : ");
        gets(nama_mhs);
        printf("Input lokasi kursi (baris, kolom) : ");
        int kursi_baris, kursi_kolom;
        scanf("%d %d", &kursi_baris, &kursi_kolom); getchar();
        printf("Name : %s\nLokasi kursi : (%d,%d)\nCorrect?\n(Y/N) >> ", nama_mhs, kursi_baris, kursi_kolom);
        kursi_baris--;
        kursi_kolom--;
        char confirm;
        scanf("%c", &confirm);
        if (confirm == 'N' || confirm == 'n'){
            tanda = 1;
        }
        else{
            strcpy(info.name[kursi_baris], nama_mhs);
            info.lokasi[kursi_baris][kursi_kolom][0] = nama_mhs[0];
            return;
        }
    }
    
}

void info_mahasiswa(){
    printf("Input baris dan kolom kursi yang dipisah dengan spasi (misal : 1 2)\n>> ");
    int cari_row, cari_col;
    scanf("%d %d", &cari_row, &cari_col); getchar();
    cari_row--; 
    cari_col--;
    if (info.lokasi[cari_row][cari_col][0] > 0){
        printf("Nama mahasiswa : %s\n", info.name[cari_row]);
    }
    else{
        printf("Empty!\n");
    }
}

void denah(){
    for (int a = 0 ; a < 30 ; a++){
        for (int b = 0 ; b < 30 ; b++){
            if (info.lokasi[a][b][0] > 0){
                printf("[%c]", info.lokasi[a][b][0]);
            }
            else{
                printf("[ ]");
            }
        }
        printf("\n");
    }
}

int main(){
    int flag = 1, index = 0;
    while (flag){
        menu();
        int user_input;
        scanf("%d", &user_input); getchar();
        switch (user_input){
            case 1:
                info_mahasiswa();
                break;
            case 2:
                denah();
                break;
            case 3:
                tambah_mahasiswa(&index);
                break;
            default:
                flag = 0;
                break;
        }
    }
}