#include <stdio.h>

/*
    ==================================================
    FITUR 3: PENGATURAN BOBOT NILAI
    ==================================================

    Fungsi:
    - Menyediakan bobot awal penilaian.
    - Memberikan pilihan untuk mengubah bobot.
    - Memastikan total bobot berjumlah 100%.

    Parameter:
    - bobot: Array untuk menyimpan bobot Tugas,
      Quiz, UTS, dan UAS.
*/

// <FUNGSI INPUT BOBOT>

void inputBobot(float bobot[])
{
    // Variabel untuk menyimpan pilihan pengguna.
    int pilihan;

    // Variabel untuk menyimpan total bobot.
    float totalBobot;

    // Variabel untuk menghitung perulangan.
    int i;

    // Menampilkan pilihan pengaturan bobot.
    printf("\n=== PENGATURAN BOBOT NILAI ===\n");
    printf("1. Menggunakan bobot awal\n");
    printf("2. Mengubah bobot penilaian\n");
    printf("Pilih pengaturan bobot: ");
    scanf("%d", &pilihan);

    // Memeriksa pilihan pengguna.
    if (pilihan == 2)
    {
        // Mengulang input selama total bobot belum 100%.
        do
        {
            printf("\n=== UBAH BOBOT NILAI ===\n");

            printf("Masukkan bobot Tugas : ");
            scanf("%f", &bobot[0]);

            printf("Masukkan bobot Quiz  : ");
            scanf("%f", &bobot[1]);

            printf("Masukkan bobot UTS   : ");
            scanf("%f", &bobot[2]);

            printf("Masukkan bobot UAS   : ");
            scanf("%f", &bobot[3]);

            // Menghitung total seluruh bobot.
            totalBobot = 0;

            for (i = 0; i < 4; i++)
            {
                totalBobot += bobot[i];
            }

            // Memeriksa apakah total bobot sudah 100%.
            if (totalBobot != 100)
            {
                printf("\nTotal bobot: %.2f%%\n", totalBobot);
                printf("Total bobot harus berjumlah 100%%!\n");
            }

        } while (totalBobot != 100);

        printf("\nBobot berhasil diubah!\n");
    }
    else if (pilihan == 1)
    {
        printf("\nMenggunakan bobot awal.\n");
    }
    else
    {
        printf("\nPilihan tidak valid!\n");
    }
}


/*
    ==================================================
    FUNGSI MENGHITUNG NILAI AKHIR MAHASISWA
    ==================================================

    Fungsi:
    - Menghitung nilai akhir berdasarkan nilai
      mahasiswa dan bobot yang sudah ditentukan.

    Parameter:
    - nilai: Array untuk menyimpan nilai Tugas, Quiz,
      UTS, dan UAS.
    - bobot: Array untuk menyimpan bobot setiap
      komponen penilaian.

    Return:
    - Mengembalikan hasil nilai akhir mahasiswa.
*/

// <FUNGSI HITUNG NILAI AKHIR>

float hitungNilaiAkhir(float nilai[], float bobot[])
{
    // Variabel untuk menyimpan hasil nilai akhir.
    float nilaiAkhir = 0;

    // Variabel untuk menghitung perulangan.
    int i;

    // Menghitung nilai berdasarkan bobot.
    for (i = 0; i < 4; i++)
    {
        nilaiAkhir += nilai[i] * bobot[i] / 100;
    }

    // Mengembalikan hasil perhitungan.
    return nilaiAkhir;
}
