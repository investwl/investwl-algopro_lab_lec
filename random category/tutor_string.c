#include <stdio.h>
#include <string.h>

int main()
{
//     int length1, length2;
//     scanf("%d %d", &length1, &length2);
//     getchar();
//     char nama1[length1];
//     char nama2[length2];
//     scanf("%s %s", nama1, nama2);
//     getchar();
//     int flag = 1;
//     if (length1 == length2){
//         for (int i = 0; i < length2; i++){
//             if (nama1[i] != nama2[i]){
//                 flag = 0;
//                 break;
//             }
//         }
//     }
//     else{
//         printf("Error! Different string length");
//         flag = 0;
//     }
//     if (flag == 1){printf("%d", 0);}
    
// }

    char kalimat[101];
    printf("masukkan kalimat = ");
    scanf("%[^\n]s", &kalimat);
    getchar();
    printf("masukkan huruf yang dicari = ");
    char yang_dicari;
    scanf("%c", &yang_dicari);
    int count = 1;
    for (int i = 0; i < strlen(kalimat); i++){
        if (kalimat[i] == yang_dicari){
            printf("huruf  %c  atau huruf %c ke-%d : offset- %d\n", yang_dicari, (yang_dicari - 32), count, i);
            count++;
        }
    }
}