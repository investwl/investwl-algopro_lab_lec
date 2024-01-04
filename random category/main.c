#include <stdio.h>

int main(){
    int no_rek_saya, nominal_saya, no_rek_target, nominal_target;
    nominal_saya = 10000000;
    printf("Halo, saldo anda adalah Rp.%d,-\n", nominal_saya);
    printf("Isi nomor rekening tujuan anda : ");
    scanf("%d", &no_rek_target);
    while ((getchar()) != '\n');
    printf("Isi nominal transfer anda : ");
    scanf("%d", &nominal_target);
    
    printf("Rekening = %d\nNominal transfer = Rp %d ,-", no_rek_target, nominal_target);
    return 0;
}
