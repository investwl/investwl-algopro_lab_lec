/* fokus structure, enumeration, dll gatau */

#include <stdio.h>
#include <string.h>

struct myStruct{
    // it is not possible to save a value in struct in the first time declaration
    int a;
    char b[10];
} struct1 ; // struct always ends with ; , can also put the name that can be called before ;

struct tumbalStr{
    int id;
    char name[32];
};

/* typedef : aliases, buat shortnaming. commonly used in struct (go line 49)*/
typedef struct identitas{
    char name[20];
    int nim;
    float gpa;
} mhs; // mhs --> alias name of struct identitas. define struct var use : mhs bambang, toni;

typedef struct identity{
    char name[30];
};


// union (go line 59)
union test1{
    int x;
    char y;
} a; // total size of union : 4 bc int is 4

struct test3{ // only integer / unsigned int
    unsigned 
}

int main(){
    // struct myStruct struct1;  kalo ga declare nama dr awal bisa kyk gini

    strcpy(struct1.b, "Hello"); // kalo mau isi value bisa kayak gini

    // atau bisa initialization dg cara kyk gini
    struct tumbalStr info = {1, "A. John"}; // bisa nitialize secara urutan di struct

    printf("%s\n", struct1.b);

    printf("Employee name : %s\n", info.name);
    printf("ID Employee %04d\n\n", info.id);


    // cara buat copypaste isi struct yg disimpan ke dalam variable kyk line 22
    struct tumbalStr bambang = info;
    // kondisinya belom dirubah isinya, bambang itu dia tetap isinya sama spt info (line 22).

    bambang.id = 2;
    strcpy(bambang.name, "Bambang");

    printf("Name employee : %s\n", bambang.name);
    printf("ID Employee : %04d\n\n", bambang.id);


    // cara lain buat alias typdef :
    typedef identity mhs;

    // union = memory join, memory locaton can be assigned for two or more variable with different data types
    // memory capacity yg dipake union : capacity terbesar yg dipake dari elemen union.

    // ketika kita isi data ke union, hanya DATA PALING TERAKHIR diinput yg disave.

    a.x = 100;
    a.y = 'a';

    // maka isi union hanya ada variable y , isinya 'a'. kalo coba print x, hasilnya pasti kosong

    // bitfield -> struct yang ngeisi elemen dengan angka bit

    // enumeration -> struct yang nyimpen nama variable. 
    // defaultnya yg plg atas 0 sampe kebawah +1
    /// bisa assign value sesuka kita apapun








    

}