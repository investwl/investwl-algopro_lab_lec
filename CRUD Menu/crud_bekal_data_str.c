#include <stdio.h>
#include <string.h>

int main(){
    // learning about CRUD (create, read, update, delete)
    // contoh array yg bisa berhubungan dengan crud --> mahasiswa (nama, umur, ipk)
    //bikin array penyimpanannya dlu
    char names[10][51]; //10 names, 50 max letters
    int ages[10];
    double gpas[10];
    int number_of_students = 0; // berperan sbg index pas looping input user menu ke 1

    // \0 itu adalah penanda berhentinya array, jadi kalo kita edit isi valuenya ditengah2 jadi \0, dia bakal bisa diprint sampe sblm \0
    // mau coba bikin menu utk user create, read, update, ato delete data 
    while (1){
        // 1. Display Menu
        printf("1. Insert Student\n2. View Student\n3. Update Student's GPA\n4. Remove Student\n0. Exit\n>> ");
        // 2. Ambil Input User
        int user_input;
        scanf("%d", &user_input);
        getchar();
        // 3. Handle Input User
        if (user_input == 0){break;}
        else if (user_input == 1){
            // minta input dari user
            // save to array
            printf("Masukkan nama : ");
            scanf("%[^\n]s", &names[number_of_students]);
            getchar();
            printf("Masukkan umur : ");
            scanf("%d", &ages[number_of_students]);
            getchar();
            printf("Masukkan IPK : ");
            scanf("%lf", &gpas[number_of_students]);
            getchar();
            number_of_students++;
        }
        else if (user_input == 2){
            printf("====================================================\n");
            for (int i = 0; i < number_of_students; i++){
                printf("%s - %d - %.2lf\n", names[i], ages[i], gpas[i]);
            }
        }
        else if (user_input == 3){
            char name[51];
            // minta nama mahasiswa yang mau diupdate datanya
            printf("Masukkan nama : ");
            scanf("%[^\n]s", name);
            getchar();
            // minta ipk yang baru
            printf("Masukkan GPA yang mau dirubah : ");
            double newGPA;
            scanf("%lf", &newGPA);
            getchar();
            // update datanya
            for (int i = 0; i < number_of_students; i++){
                if (!(strcmp(name, names[i]))){
                    gpas[i] = newGPA;
                    break;
                }
            }

        }
        else if (user_input == 4){
            // minta nama mahasiswa yang mau dihapus
            // hapus mahasiswanya
            char name[51];
            printf("Masukkan nama mahasiswa yang mau dihapus : ");
            scanf("%[^\n]s", name);
            getchar();
            for (int i = 0; i < number_of_students; i++){
                if (!(strcmp(name, names[i]))){
                    // logic cara ngapusnya : 
                    // timpa aja data yg index skrg sama data yang ada dibawah dan number_of_student - 1
                    for (int j = i; j < number_of_students - 1; j++){
                        strcpy(names[j], names[j+1]);
                        ages[j] = ages[j+1];
                        gpas[j] = gpas[j+1];
                        // yg bakal ditimpa datanya semua termasuk ages dan gpas
                    }
                    number_of_students--;
                    break;
                }
            }
        }
        else {
            printf("Wrong input, only 0 - 4 acceptable! Try again!\n");
            continue;
        }
    }
}