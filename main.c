#include "functions.h"

void menuSortingDasar(void) {
    int pilih;
    do {
        printf("\n===== SORTING DASAR =====\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Kembali\n");
        printf("Pilih metode : ");
        scanf("%d", &pilih);

        if (pilih >= 1 && pilih <= 3)
            jalankanSortingDasar(pilih);
        else if (pilih != 4)
            printf("Pilihan tidak valid! Silakan pilih 1-4.\n");

    } while (pilih != 4);
}


void menuAdvanceSorting(void) {
    int pilih;
    do {
        printf("\n===== ADVANCE SORTING =====\n");
        printf("1. Merge Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Shell Sort\n");
        printf("4. Kembali\n");
        printf("Pilih metode : ");
        scanf("%d", &pilih);

        if (pilih >= 1 && pilih <= 3)
            jalankanAdvanceSorting(pilih);
        else if (pilih != 4)
            printf("Pilihan tidak valid! Silakan pilih 1-4.\n");

    } while (pilih != 4);
}


//MENU UTAMA
int main(void) {
    int pilih;
    do {
        printf("\n===== MENU UTAMA =====\n");
        printf("1. Sorting Dasar\n");
        printf("2. Advance Sorting\n");
        printf("3. Keluar\n");
        printf("Pilih menu : ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1: menuSortingDasar();   break;
            case 2: menuAdvanceSorting(); break;
            case 3: printf("\nTerima kasih! Program selesai.\n\n"); break;
            default: printf("Pilihan tidak valid! Silakan pilih 1-3.\n");
        }
    } while (pilih != 3);

    return 0;
}
