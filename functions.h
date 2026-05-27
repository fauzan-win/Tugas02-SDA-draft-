/*
 * ============================================================
 *  functions.h  –  Deklarasi semua fungsi & konstanta global
 *  Penghubung antara main.c, basic_sort.c, dan advance_sort.c
 * ============================================================
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ─── Konstanta ─────────────────────────────────────────── */
#define JUMLAH_DATA_INT   1000    /* jumlah integer untuk sorting dasar  */
#define TAMPIL            10      /* jumlah data yang ditampilkan         */
#define MAX_KATA          100000  /* batas maksimum kata dari file        */
#define MAX_PANJANG_KATA  100     /* panjang maksimum satu kata           */
#define NAMA_FILE         "words_en.txt"

/* ================================================================
 *  Deklarasi fungsi dari basic_sort.c
 * ================================================================ */

/* Utility integer */
void cetakArrayInt(int arr[], int n, int total);
void shuffleInt(int arr[], int n);
void salinInt(int src[], int dst[], int n);

/* Algoritma sorting dasar */
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);

/* Runner sorting dasar (generate data, shuffle, sort, tampilkan waktu) */
void jalankanSortingDasar(int pilihan);

/* ================================================================
 *  Deklarasi fungsi dari advance_sort.c
 * ================================================================ */

/* Utility string */
void cetakArrayStr(char arr[][MAX_PANJANG_KATA], int n, int total);
void shuffleStr(char arr[][MAX_PANJANG_KATA], int n);

/* Baca kata dari file .txt */
int bacaFile(char arr[][MAX_PANJANG_KATA], int maks);

/* Algoritma sorting advance */
void merge(char arr[][MAX_PANJANG_KATA], int kiri, int tengah, int kanan);
void mergeSort(char arr[][MAX_PANJANG_KATA], int kiri, int kanan);
int  partisi(char arr[][MAX_PANJANG_KATA], int rendah, int tinggi);
void quickSort(char arr[][MAX_PANJANG_KATA], int rendah, int tinggi);
void shellSort(char arr[][MAX_PANJANG_KATA], int n);

/* Runner advance sorting (baca file, shuffle, sort, tampilkan waktu) */
void jalankanAdvanceSorting(int pilihan);

/* ================================================================
 *  Deklarasi fungsi menu dari main.c
 * ================================================================ */
void menuSortingDasar(void);
void menuAdvanceSorting(void);

#endif /* FUNCTIONS_H */
