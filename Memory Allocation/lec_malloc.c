#include <stdio.h>

int main(){
    static keyword --> variable apapun yang hanya bisa diakses di file itu sendiri (local file scope). default value = 0. pakai memory hanya saat program jalan.
    contoh:
    static int x;
    static void func();
    static juga mempertahankan isi valuenya terus, misal sudah diakses dan diolah isinya 5, terus pas dipanggil lagi, masih 5 dan value bisa dirubah dari 5.
    bisa dibilang nilainya bertahap.

    -----------------------------------------------

    external variable -->  gunanya buat ambil data dari file lain ke dalam file kita kerjakan sekarang.
    data yg diambil hrs udah ada dulu
    extern int y;

    syarat : di file tsb, variablenya nggak static.

    misal di data.c, 
    int y = 12;
    di file main.c bisa aja kyk gini

    int main(){
        extern int y;
        printf("%d\n", y);
    }

    ini bakal return 12 karena ambil dari data.c

    --------------------------------------------------

    const --> basically constant. value tidak bisa dirubah saat sudah di set.
    const char * --> unchangeable string. biasanya isinya string / pointer. cara lain adalah tetep set char string biasa tp lgsg isi value ""; , gabisa null.

    contohnya di strcmp, kedua syarat itu const char * , basically string yg udah ada isinya.
    kalo strcmp, dest gausah ada isi gapapa, tp source harus ada isi const char *

    --------------------------------------------------
    kalo void doang : kosong, no return
    void untuk variable, isinya bisa flexible, bebas. nanti harus type casting ke variable tujuannya atau return nya.
    void * data type --> 
    void func(void) (without actual parameter) (kosongin voidnya jg gpp yg dlm kurung)


    type void * always use type casting, ex :
    char *pstr;
    int *pint;
    pstr = (char *)malloc(20); --> itu yg (char *) itu namanya type casting
    pint = (int *)malloc(20); --> type casts to pointer.

    ---------------------------------------------------

    Memory Allocation (malloc)

    allocation : set memory yang ditahan antara mau dipake ato nggak
    de-allocation : set free memory yang ditahan

    alokasi yang diminta biasa akan disesuaikan dengan data type yang dibuat. (char : 1 , int : 4, struct : total all var, union : var terbesar)

    allocation --> misal int, float, char[2], maka use up 10 bytes
    deallocation --> maka saat nge free int, float, char[2], -10 bytes

    static
    : langsung assign berapa memory yang akan dipakai, pemaksaan. misal int x[5]; , langsung make 20 bytes
    : alokasi memori pas compile (run), disetor di local stack memory
    : lepas pengunaan memory pas code selesai

    ex : 
    ada struct isinya char[9], char[26], float. lalu struct tsb disimpan dalam array[100], dia akan make 4504 bytes

    dynamic
    : penggunaan memory akan disesuaikan dengan codingan, di dalam code bisa aja assign dan de-assign penggunaan memory.
    : stored in heap memory
    : kalo di code panggil, baru use memory. kalo nggak ya nggak use memory.
    : lepas pengunaan memory kapanpun kita mau

    bakal pakai function namanya malloc()

    malloc() --> assign mau pake berapa memory, kita yang tentuin mau pake berapa size memory yang mau dipake. reserve brp byk byte.

    void* malloc(size_t size); (disimpan dalam var)

    malloc adalah pointer, maka jika diisi dlm variable, var itu jg harus tipe data pointer, dan int karena malloc return nya angka.

    cukup umum untuk pake sizeof(tipe data variable), buat tau berapa byte yg dipake dr sebuah datatype dari sebuah variable.

    bisa aja kayak gini
    int *a;
    a = (int i*) malloc(sizeof(int)); --> malloc void*, maka type cast. ke int* (int pointer), sizeof() biar tau pasti kita mau pake brp memory.

    ketika malloc berhasil dilakukan, return address.
    ketika malloc gagal, return null.

    misal kita ada array dan mau malloc(), bisa langsung sizeof(data type * n)

    n : berapa panjang arraynya


    malloc mainnya address

    ------------------------------------------------------------

    setelah malloc, BEST PRACTICE nya adalah free()
    
    free() buat bebasin memory yang excessive / berlebih yg ga kepake.

    misal line 88 , 89. abis dari malloc,

    void free (a); (no assignment on variable)

    intinya kita nge bebasin malloc si variable karena udh selesai make memory, kalo ada sisa ya dilepas, biar memory bisa dipake.

    -----------------------------------------------------------


    misal ada a dan b

    a udah malloc, terus a ga butuh, tapi b butuh malloc

    kita bisa pake realloc()


    void* realloc(void *ptr, size_t size);
    size --> ya size
    *ptr --> target kita mau pindahin alokasi memorynya kemana


    ex : 
    int *a, *ptr;
    a = (int *) realloc(ptr, sizeof(int));

    --------------------------------------------------------

    calloc() , mirip dengan malloc()

    calloc() --> alokasi memory tapi ada tambahan parameter

    calloc itu kayak tadi yang malloc * berapa banyak, berguna buat array

    misal void* calloc(20, sizeof(int)); --> berarti ini buat assign array size 20 dengan datatype int
    
    sama aja kayak malloc(sizeof(int * 20));

    --------------------------------------------------------

    YANG DISIMPAN DALAM MALLOC ATAU CALLOC ITU MEMORY ADDRESS DARI HEAP MEMORY, BUKAN LOCAL STACK MEMORY

    HEAP MEMORY : MEMORY YG SEMENTARA DAN RESERVED
    LOCAL STACK MEMORY : MEMORY YANG DIPAKE BUAT SIMPEN SEMUA HAL DALAM FILE DALAM RAM LAPTOP, ATAU BAHKAN CLOUD :O

    ------------------------------------------------------------

    Macro

    --> tambahan doang, basically aliases.

    dipasang pake #define , selalu ditaro diatas

    misal #define ERROR as rusak

    ntar pas mau akses function ato command ERROR, tinggal panggil rusak, nanti pas di print juga sama aja error.

    --------------------------------------------------------------