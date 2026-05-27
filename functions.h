#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define JUMLAH_DATA_INT   1000    //jumlah integer untuk sorting dasar 
#define TAMPIL            10      // jumlah data yang ditampilkan
#define MAX_KATA          100000  // batas maksimum kata dari file 
#define MAX_PANJANG_KATA  100     // panjang maksimum satu kata
#define NAMA_FILE "words.txt"


// Deklarasi fungsi dari basic_sort.c
void cetakArrayInt(int arr[], int n, int total);
void shuffleInt(int arr[], int n);
void salinInt(int src[], int dst[], int n);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);
void jalankanSortingDasar(int pilihan);


// Deklarasi fungsi dari advance_sort.c
void cetakArrayStr(char arr[][MAX_PANJANG_KATA], int n, int total);
void shuffleStr(char arr[][MAX_PANJANG_KATA], int n);

// Membaca kata dari words.txt
int bacaFile(char arr[][MAX_PANJANG_KATA], int maks);
void merge(char arr[][MAX_PANJANG_KATA], int kiri, int tengah, int kanan);
void mergeSort(char arr[][MAX_PANJANG_KATA], int kiri, int kanan);

int  partisi(char arr[][MAX_PANJANG_KATA], int rendah, int tinggi);
void quickSort(char arr[][MAX_PANJANG_KATA], int rendah, int tinggi);
void shellSort(char arr[][MAX_PANJANG_KATA], int n);
void jalankanAdvanceSorting(int pilihan);

//Deklarasi fungsi menu dari main.c
void menuSortingDasar(void);
void menuAdvanceSorting(void);

#endif