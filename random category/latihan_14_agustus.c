#include <stdio.h>

int main(){
    /* Buatlah program seperti berikut:
     Tampilkan menu:
     1. Jam:Menit:Detik ke Detik
     2. Detik ke Jam:Menit:Detik
     >> 
     Jika user input 1:
     Minta input Jam:Menit:Detik
     Tampilkan hasilnya
     JIka uaer input 2:
     Minta input berapa detikbya
     Tampilkan Jam:Menit:Detik
    */
    int choose_menu, quit = 1, jam, menit, detik, input_detik;
    while (quit == 1){
        printf("Menu:\n1. Jam:Menit:Detik ke Detik\n2. Detik ke Jam:Menit:Detik\nInput 1 atau 2 = \n>> ");
        scanf("%d", &choose_menu);
        if (choose_menu == 1){
            printf("1. Jam:Menit:Detik ke Detik\nMasukkan jam, menit, dan detik sesuai format jj:mm:dd = ");
            scanf("%02d:%02d:%02d", &jam, &menit, &detik);
            printf("%d detik.", ((jam * 3600) + (menit * 60) + detik));            
        }
        else if (choose_menu == 2){
            printf("2. Detik ke Jam:Menit:Detik\nMasukkan jumlah detik = ");
            scanf("%d", &input_detik);
            jam = input_detik / 3600;
            input_detik %= 3600;
            menit = input_detik / 60;
            input_detik %= 60;
            detik = input_detik;
            printf("%02d:%02d:%02d", jam, menit, detik);
        }
        else{
            printf("Only 1 or 2 menu is avaliable. Input again.\n");
        }
        while (1){
            printf("\nDo you want to run the program again? (1 / 0) = ");
            scanf("%d", &quit);
            if (quit >= 2 || quit <= -1){
                printf("Error, only 0 or 1 is available.");
            }
            else{
                break;
            }
        }
        if (quit == 0){
            printf("Thank you.");
            break;
        }
        else if (quit == 1){
            continue;
        }
        
    }
    
}