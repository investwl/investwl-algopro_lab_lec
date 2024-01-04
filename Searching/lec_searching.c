#include <stdio.h>

int main(){
    /*
    searching itu terbagi menjadi linear search dan binary search

    searching, looking for smth. antara sudah sorted atau belom.

    kalo unsorted, sort dlu lah

    1. Linear Search
    : mencari data dari 0 sampe akhir
    misal 4, 2, 7, 5, 6, 3, 1, 9
    mau cari 6

    berarti pake for dan if buat nyari angkanya dari awal sampe akhir

    2. Binary Search
    : kita udah tau karakteristik dari data kita, misal kamus. 
    kamus udah ordered.

    misal di kamus mau cari tulisan komputer. maka mulai dari k.

    intinya kita kalo binary search carinya dengan motong 1/2. cek di tengah ada ga datanya.
    kalo gaada di tengah, coba cek dia lebih kecil nggak? kalo iya ke kiri
    kalo lebih besar ke kanan

    binary search syaratnya harus ordered data dulu.

    while (middle != key){
        middle = batas tinggi + batas rendah / 2
        if (array[middle] == key) --> found

        else
            if a[middle] < key --> low = mid + 1
            if a[middle] > key --> high = mid - 1
    }

    3. Interpolation Search
    : nilai mid yang diubah
    : mirip kayak binary search, cuman bedanya ada di =

    kalo binary, mid nya : high + low / 2,
    interpolation : mid = key - a[low] / a[high] - a[low] x (high - low) + low

    
    */
}