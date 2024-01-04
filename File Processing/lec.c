#include <stdio.h>

int main(){
    File Processing

    syaratnya selalu buka dengan FILE *nama apa aja;
    digunakan untuk manipulasi File

    "r" : read File
    "w" : write File, bakal override isi file semuanya. kalo filenya gaada dia bikinin
    "a" : nambahin ke file, akan dimulai after the latest word in the file.
    kalo ditambah +, biasanya kalo r+ / w+ bisa read / write, kalo a+ buat read / append
    "rb" "wb" : buat buka ato bikin file binary

    digunakan dalam fopen

    fopen(filename (yang tadi file* ), (mode)) --> file* td nama apa aja, mode : r, w, a / +
    kl bener return file, gaaada return null. bisa dicek pake if == null, brti null aja.

    setelah open, fclose(nama apa aja);

    diantara fopen dan fclose, bisa baca tulis

    untuk input output file, bisa lakukan semuanya yang penting depannya ditambahin huruf 'f'
    tapi di dalam syntax, tambahin 1 parameter, yaitu nama filenya.

    input : fgetc(nama apa aja) -> getchar
            fscanf(nama apa aja, "%d %s", &angka, kalimat); --> dalam ambil string, kalo ketemu separator, kita pake capping : fscanf(... , "%[^]"),  setelah ^, separatornya apa diisi

    output : 

    yg plg penting adalah menyimpan data secara terstruktur
}