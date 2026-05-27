#include "functions.h"

// Cetak n kata pertama dari array string
void cetakArrayStr(char arr[][MAX_PANJANG_KATA], int n, int total) {
    printf("  [ ");
    for (int i = 0; i < n && i < total; i++) {
        printf("\"%s\"", arr[i]);
        if (i < n - 1 && i < total - 1) printf(", ");
    }
    if (total > n) printf(", ... (%d kata tersembunyi)", total - n);
    printf(" ]\n");
}

// Shuffle array string dengan rand + swap
void shuffleStr(char arr[][MAX_PANJANG_KATA], int n) {
    char tmp[MAX_PANJANG_KATA];
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        strcpy(tmp,    arr[i]);
        strcpy(arr[i], arr[j]);
        strcpy(arr[j], tmp);
    }
}

/* Membaca kata dari file .txt, satu kata per baris / per token */
int bacaFile(char arr[][MAX_PANJANG_KATA], int maks) {
    FILE *fp = fopen("words.txt", "r");
    if (!fp) {
        printf("[ERROR] File '%s' tidak ditemukan!\n", "words.txt");
        printf("Pastikan file text ada di folder yang sama.\n\n");
        return 0;
    }
    int n = 0;
    while (n < maks && fscanf(fp, "%99s", arr[n]) == 1) n++;
    fclose(fp);
    return n;
}


//MERGE SORT

//Fungsi bantu: gabungkan dua sub-array yang sudah terurut
void merge(char arr[][MAX_PANJANG_KATA], int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;
    char (*L)[MAX_PANJANG_KATA] = malloc((size_t)n1 * MAX_PANJANG_KATA);
    char (*R)[MAX_PANJANG_KATA] = malloc((size_t)n2 * MAX_PANJANG_KATA);
    if (!L || !R) { free(L); free(R); return; }
    for (int i = 0; i < n1; i++) strcpy(L[i], arr[kiri + i]);
    for (int j = 0; j < n2; j++) strcpy(R[j], arr[tengah + 1 + j]);
    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0)
            strcpy(arr[k++], L[i++]);
        else
            strcpy(arr[k++], R[j++]);
    }
    while (i < n1) strcpy(arr[k++], L[i++]);
    while (j < n2) strcpy(arr[k++], R[j++]);

    free(L);
    free(R);
}

void mergeSort(char arr[][MAX_PANJANG_KATA], int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2; 
        mergeSort(arr, kiri, tengah);
        mergeSort(arr, tengah + 1, kanan);
        merge(arr, kiri, tengah, kanan);
    }
}


//QUICK SORT

//Fungsi bantu: partisi array, kembalikan indeks pivot akhir
int partisi(char arr[][MAX_PANJANG_KATA], int rendah, int tinggi) {
    char pivot[MAX_PANJANG_KATA];
    strcpy(pivot, arr[tinggi]);   /* pivot = elemen terakhir */
    int i = rendah - 1;
    char tmp[MAX_PANJANG_KATA];

    for (int j = rendah; j < tinggi; j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            strcpy(tmp,    arr[i]);
            strcpy(arr[i], arr[j]);
            strcpy(arr[j], tmp);
        }
    }

    strcpy(tmp,         arr[i + 1]);
    strcpy(arr[i + 1],  arr[tinggi]);
    strcpy(arr[tinggi], tmp);
    return i + 1;
}

void quickSort(char arr[][MAX_PANJANG_KATA], int rendah, int tinggi) {
    if (rendah < tinggi) {
        int pi = partisi(arr, rendah, tinggi);
        quickSort(arr, rendah, pi - 1);
        quickSort(arr, pi + 1, tinggi);
    }
}

//SHELL SORT
void shellSort(char arr[][MAX_PANJANG_KATA], int n) {
    char tmp[MAX_PANJANG_KATA];
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            strcpy(tmp, arr[i]);
            int j = i;
            while (j >= gap && strcmp(arr[j - gap], tmp) > 0) {
                strcpy(arr[j], arr[j - gap]);
                j -= gap;
            }
            strcpy(arr[j], tmp);
        }
    }
}

//Baca file, shuffle, sort, tampilkan hasil & waktu
void jalankanAdvanceSorting(int pilihan) {
    const char *nama[] = { "", "Merge Sort", "Quick Sort", "Shell Sort" };

    /* Alokasi dinamis (heap) agar tidak stack overflow untuk data besar */
    char (*data)[MAX_PANJANG_KATA] =
        malloc((size_t)MAX_KATA * MAX_PANJANG_KATA);
    if (!data) {
        printf("[ERROR] Gagal alokasi memori.\n");
        return;
    }

    //Baca seluruh kata dari file
    int n = bacaFile(data, MAX_KATA);
    if (n == 0) { free(data); return; }

    //2. Shuffle sebelum sorting
    srand((unsigned)time(NULL));
    shuffleStr(data, n);

    printf("\n===== %s =====\n", nama[pilihan]);
    printf("Total kata dibaca : %d\n", n);
    printf("Kata SEBELUM sorting (%d kata pertama):\n", TAMPIL);
    cetakArrayStr(data, TAMPIL, n);

    //3. Ukur waktu eksekusi dengan clock()
    clock_t mulai = clock();

    switch (pilihan) {
        case 1: mergeSort(data, 0, n - 1); break;
        case 2: quickSort(data, 0, n - 1); break;
        case 3: shellSort(data, n);         break;
    }

    clock_t selesai = clock();
    double waktu = (double)(selesai - mulai) / CLOCKS_PER_SEC;

    //4. Tampilkan hasil
    printf("Kata SETELAH sorting (%d kata pertama):\n", TAMPIL);
    cetakArrayStr(data, TAMPIL, n);
    printf("Waktu eksekusi : %.6f detik\n\n", waktu);

    free(data);
}