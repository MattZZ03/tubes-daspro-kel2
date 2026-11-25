#define MAX_MAHASISWA 50
#define PANJANG_NIM 9
#define PANJANG_NAMA 50

#include <stdio.h>
#include "fitur1_input.h"
#include "fitur2_inputNilaiBobot.h"
//fitur3_hitungNilaiBobot.h sudah diinclude kedalam file fitur2_inputNilaiBobot.h
#include "fitur4_grade.h"
#include "fitur5_daftarNilai.h"
#include "fitur6_cariNim.h"
#include "fitur7_statistik.h"
#include "fitur8_remedial.h"


int main(){
    int jumlahMahasiswa = 0, pilih, i, j;
    char nim[MAX_MAHASISWA][PANJANG_NIM];
    char nama[MAX_MAHASISWA][PANJANG_NAMA];
    float nilai[MAX_MAHASISWA][4];
    int nilaiDiinput[MAX_MAHASISWA] = {0};
    float nilaiAkhir[MAX_MAHASISWA] = {0};

    // Bobot awal: Tugas, Quiz, UTS, UAS.
    float bobot[4] = {50, 10, 20, 20};

    // Penampung hasil grade & status kelulusan.
    char grade;
    int status;

    //Menu
    do{
        printf("\n=================================================================\n");
        printf("=========  SISTEM PENGELOLAAN NILAI AKADEMIK MAHASISWA  =========\n");
        printf("=================================================================\n");
        printf("1. Input data mahasiswa (NIM & nama)\n");
        printf("2. Input nilai (tugas, kuis, UTS, UAS)\n");
        printf("3. Atur bobot & hitung ulang nilai akhir\n");
        printf("4. Tampilkan grade & status kelulusan\n");
        printf("5. Tampilkan daftar mahasiswa & nilai akhir\n");
        printf("6. Cari mahasiswa berdasarkan NIM\n");
        printf("7. Statistik kelas\n");
        printf("8. Daftar mahasiswa perlu remedial\n");
        printf("0. Keluar\n");
        printf("================================================================\n");
        printf("Pilih fitur yang akan digunakan : ");
        scanf("%d", &pilih);

        switch(pilih){
            //Menu Input Data Mahasiswa
            case 1:

            printf("============================================================\n");
            printf("                     Input Data Mahasiswa                   \n");
            printf("============================================================\n");
            inputMahasiswa(nim, nama, &jumlahMahasiswa);
            break;



            //Input Nilai Mahasiswa
            case 2:
            if (jumlahMahasiswa == 0) {
            printf("============================================================\n");
            printf("                   Input Nilai Mahasiswa                    \n");
            printf("============================================================\n");
                printf("Input data mahasiswa terlebih dahulu.\n");
                break;
            }

            for (i = 0; i < jumlahMahasiswa; i++) {
                printf("\nInput nilai untuk %s (NIM: %s)\n", nama[i], nim[i]);
                for (j = 0; j < 4; j++) {
                    if (j == 0) {
                        printf("Masukkan nilai Tugas: ");
                    } else if (j == 1) {
                        printf("Masukkan nilai Quiz: ");
                    } else if (j == 2) {
                        printf("Masukkan nilai UTS: ");
                    } else {
                        printf("Masukkan nilai UAS: ");
                    }

                    scanf("%f", &nilai[i][j]);
                }

                nilaiDiinput[i] = 1;

                // Hitung nilai akhir memakai bobot yang sedang berlaku.
                nilaiAkhir[i] = hitungNilaiAkhir(nilai[i], bobot);

                printf("Tugas: %.2f | Quiz: %.2f | UTS: %.2f | UAS: %.2f\n",
                       nilai[i][0], nilai[i][1], nilai[i][2], nilai[i][3]);
            }
            break;





            //Atur Bobot Nilai & Hitung Nilai Akhir
            case 3:
                inputBobot(bobot);

                // Hitung ulang nilai akhir semua mahasiswa yang nilainya sudah diinput.
                for (i = 0; i < jumlahMahasiswa; i++) {
                    if (nilaiDiinput[i]) {
                        nilaiAkhir[i] = hitungNilaiAkhir(nilai[i], bobot);
                    }
                }
                break;



            //Status Kelulusan
            case 4:
                if (jumlahMahasiswa == 0) {
                    printf("\nInput data mahasiswa terlebih dahulu.\n");
                    break;
                }

                printf("\n========== GRADE & STATUS KELULUSAN ==========\n\n");
                printf("%-5s %-20s %-25s %-12s %-6s %-12s\n",
                       "No.", "NIM", "Nama", "Nilai Akhir", "Grade", "Status");
                printf("------------------------------------------------------------------------------------\n");

                for (i = 0; i < jumlahMahasiswa; i++) {
                    if (!nilaiDiinput[i]) {
                        printf("%-5d %-20s %-25s %s\n",
                               i + 1, nim[i], nama[i], "Nilai belum diinput");
                        continue;
                    }

                    prosesGradeStatus(nilaiAkhir[i], &grade, &status);

                    printf("%-5d %-20s %-25s %-12.2f %-6c %-12s\n",
                           i + 1, nim[i], nama[i], nilaiAkhir[i], grade,
                           (status == LULUS) ? "LULUS" : "TIDAK LULUS");
                }
                break;



            //Daftar Mahasiswa & Akumulasi Nilainya Masing-masing
            case 5:
                tampilkanDaftarNilai(nim, nama, nilaiAkhir, jumlahMahasiswa);
                break;



            //Cari Mahasiswa dengan NIM
            case 6:
                cariMahasiswa(jumlahMahasiswa, nim, nama, nilai, nilaiDiinput);
                break;



            //Statistik Kelas
            case 7:
                tampilkanStatistik(nilaiAkhir, jumlahMahasiswa);
                break;



            //Keterangan Remedial Mahasiswa
            case 8:
                tampilkanRemedial(nim, nama, nilaiAkhir, jumlahMahasiswa);
                break;

            case 0:
                printf("Terima kasih telah menggunakan layanan kami\n\n");
                break;
            default:
                printf("Menu tidak tersedia atau inputan salah!\n\n");
        }
    } while(pilih != 0);

    return 0;
}