/*
 * ============================================================
 *  basic_sort.c  –  Sorting Dasar
 *  Algoritma : Bubble Sort, Insertion Sort, Selection Sort
 *  Dataset   : 1000 integer random (di-generate otomatis)
 * ============================================================
 */

#include "functions.h"

/* ----------------------------------------------------------------
 *  UTILITY INTEGER
 * ---------------------------------------------------------------- */

/* Cetak n elemen pertama dari array integer */
void cetakArrayInt(int arr[], int n, int total) {
    printf("  [ ");
    for (int i = 0; i < n && i < total; i++) {
        printf("%d", arr[i]);
        if (i < n - 1 && i < total - 1) printf(", ");
    }
    if (total > n) printf(", ... (%d data tersembunyi)", total - n);
    printf(" ]\n");
}

/* Shuffle array integer dengan metode Fisher-Yates (rand + swap) */
void shuffleInt(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = arr[i];
        arr[i]  = arr[j];
        arr[j]  = tmp;
    }
}

/* Salin array integer dari src ke dst */
void salinInt(int src[], int dst[], int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}

/* ----------------------------------------------------------------
 *  ALGORITMA SORTING DASAR
 * ---------------------------------------------------------------- */

/*
 * Bubble Sort
 * Cara kerja : Bandingkan dua elemen berdekatan, tukar jika terbalik.
 *              Ulangi sampai tidak ada pertukaran (array terurut).
 * Kompleksitas: O(n²) worst/average, O(n) best (sudah terurut)
 */
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int tukar = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                /* swap */
                int tmp    = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = tmp;
                tukar = 1;
            }
        }
        if (!tukar) break; /* optimasi: berhenti jika sudah terurut */
    }
}

/*
 * Insertion Sort
 * Cara kerja : Ambil satu elemen (kunci), geser elemen yang lebih besar
 *              ke kanan, lalu sisipkan kunci ke posisi yang tepat.
 * Kompleksitas: O(n²) worst/average, O(n) best
 */
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int kunci = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > kunci) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = kunci;
    }
}

/*
 * Selection Sort
 * Cara kerja : Cari nilai minimum dari sisa array yang belum terurut,
 *              tukar ke posisi paling kiri yang belum terurut.
 * Kompleksitas: O(n²) semua kasus, jumlah swap paling sedikit
 */
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int idxMin = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[idxMin]) idxMin = j;
        }
        if (idxMin != i) {
            int tmp      = arr[i];
            arr[i]       = arr[idxMin];
            arr[idxMin]  = tmp;
        }
    }
}

/* ----------------------------------------------------------------
 *  RUNNER – Generate data, shuffle, sort, tampilkan hasil & waktu
 * ---------------------------------------------------------------- */
void jalankanSortingDasar(int pilihan) {
    const char *nama[] = { "", "Bubble Sort", "Insertion Sort", "Selection Sort" };

    /* 1. Generate 1000 data random */
    int dataAsli[JUMLAH_DATA_INT];
    srand((unsigned)time(NULL));
    for (int i = 0; i < JUMLAH_DATA_INT; i++)
        dataAsli[i] = rand() % 10000 + 1;  /* rentang 1 – 10000 */

    /* 2. Shuffle sebelum sorting */
    shuffleInt(dataAsli, JUMLAH_DATA_INT);

    /* 3. Salin ke array kerja (agar data asli tidak berubah) */
    int data[JUMLAH_DATA_INT];
    salinInt(dataAsli, data, JUMLAH_DATA_INT);

    printf("\n===== %s =====\n", nama[pilihan]);
    printf("Data SEBELUM sorting (%d data pertama dari %d):\n",
           TAMPIL, JUMLAH_DATA_INT);
    cetakArrayInt(data, TAMPIL, JUMLAH_DATA_INT);

    /* 4. Ukur waktu eksekusi dengan clock() */
    clock_t mulai = clock();

    switch (pilihan) {
        case 1: bubbleSort(data, JUMLAH_DATA_INT);    break;
        case 2: insertionSort(data, JUMLAH_DATA_INT); break;
        case 3: selectionSort(data, JUMLAH_DATA_INT); break;
    }

    clock_t selesai = clock();
    double waktu = (double)(selesai - mulai) / CLOCKS_PER_SEC;

    /* 5. Tampilkan hasil */
    printf("Data SETELAH sorting (%d data pertama dari %d):\n",
           TAMPIL, JUMLAH_DATA_INT);
    cetakArrayInt(data, TAMPIL, JUMLAH_DATA_INT);
    printf("Waktu eksekusi : %.6f detik\n\n", waktu);
}
