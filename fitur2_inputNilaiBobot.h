#include <stdio.h>
#include "fitur3_hitungNilaiBobot.h"

// Membungkus logika main ke dalam fungsi agar aman dijadikan header file
void runMainProgram()
{
    // Array untuk menyimpan nilai Tugas, Quiz, UTS, dan UAS.
    float nilai[4];

    // Array untuk menyimpan bobot awal setiap komponen.
    float bobot[4] = {50, 10, 20, 20};

    // Variabel untuk menyimpan hasil nilai akhir.
    float hasil;

    // Variabel untuk perulangan input nilai.
    int i;

    // Memasukkan nilai mahasiswa.
    for (i = 0; i < 4; i++){
        if (i == 0){
            printf("Masukkan nilai tugas: ");
        }else if (i == 1){
            printf("Masukkan nilai quiz: ");
        }else if (i == 2){
            printf("Masukkan nilai UTS: ");
        }else{
            printf("Masukkan nilai UAS: ");
        }

        scanf("%f", &nilai[i]);
    }

    // Memanggil fungsi untuk mengatur bobot penilaian.
    inputBobot(bobot);

    // Menghitung nilai akhir berdasarkan nilai dan bobot.
    hasil = hitungNilaiAkhir(nilai, bobot);

    // Menampilkan hasil nilai akhir mahasiswa.
    printf("\n=== HASIL PERHITUNGAN NILAI ===\n");
    printf("Tugas       : %.2f\n", nilai[0]);
    printf("Quiz        : %.2f\n", nilai[1]);
    printf("UTS         : %.2f\n", nilai[2]);
    printf("UAS         : %.2f\n", nilai[3]);
    printf("Nilai Akhir : %.2f\n", hasil);
}