/*
 * ============================================================
 * FILE    : grade.h
 * FITUR   : 4 - Menentukan grade dan status kelulusan
 * PEMBUAT : (isi namamu)
 *
 * TUJUAN  : Menerima nilai akhir mahasiswa (hasil fitur 3),
 *           lalu menghasilkan grade dan status kelulusan.
 *
 * ATURAN GRADE:
 *   >= 80        : A
 *   >= 70 & < 80 : B
 *   >= 60 & < 70 : C
 *   >= 50 & < 60 : D
 *   <  50        : E
 * ATURAN LULUS: nilai akhir >= 60 (grade C ke atas)
 *
 * FUNGSI YANG DISEDIAKAN:
 *   - tentukanGrade     : mengisi grade (satu char)
 *   - tentukanStatus    : mengisi status lulus / tidak lulus
 *   - prosesGradeStatus : memanggil keduanya (INI YANG DIPAKAI
 *                         anggota lain di main)
 *
 * CATATAN: file ini cukup di-include SATU kali di main.c.
 * ============================================================
 */

#include <stdio.h>

/* Batas nilai tiap grade. Ubah di sini bila aturan berubah. */
#define BATAS_A      80
#define BATAS_B      70
#define BATAS_C      60
#define BATAS_D      50
#define BATAS_LULUS  60

/* Kode status kelulusan */
#define LULUS        1
#define TIDAK_LULUS  0

/*
 * Fungsi : tentukanGrade
 * Tugas  : menentukan grade dari nilai akhir
 * Input  : nilaiAkhir -> nilai akhir mahasiswa (0-100)
 * Output : *grade -> diisi huruf A/B/C/D/E
 * Cara kerja: nilai dicek dari batas tertinggi ke terendah,
 *             cek pertama yang benar langsung dipakai.
 */
void tentukanGrade(float nilaiAkhir, char *grade)
{
    if (nilaiAkhir >= BATAS_A) {
        *grade = 'A';
    } else if (nilaiAkhir >= BATAS_B) {
        *grade = 'B';
    } else if (nilaiAkhir >= BATAS_C) {
        *grade = 'C';
    } else if (nilaiAkhir >= BATAS_D) {
        *grade = 'D';
    } else {
        *grade = 'E';
    }
}

/*
 * Fungsi : tentukanStatus
 * Tugas  : menentukan status kelulusan dari nilai akhir
 * Input  : nilaiAkhir -> nilai akhir mahasiswa (0-100)
 * Output : *status -> LULUS (1) bila nilaiAkhir >= BATAS_LULUS,
 *                     selain itu TIDAK_LULUS (0)
 */
void tentukanStatus(float nilaiAkhir, int *status)
{
    if (nilaiAkhir >= BATAS_LULUS) {
        *status = LULUS;
    } else {
        *status = TIDAK_LULUS;
    }
}

/*
 * Fungsi : prosesGradeStatus
 * Tugas  : menentukan grade DAN status sekaligus
 * Input  : nilaiAkhir -> nilai akhir mahasiswa (0-100)
 * Output : *grade  -> huruf A/B/C/D/E
 *          *status -> LULUS atau TIDAK_LULUS
 * Cara kerja: memanggil tentukanGrade lalu tentukanStatus.
 *             grade dan status sudah berupa alamat, jadi
 *             diteruskan tanpa tanda &.
 */
void prosesGradeStatus(float nilaiAkhir, char *grade, int *status)
{
    tentukanGrade(nilaiAkhir, grade);
    tentukanStatus(nilaiAkhir, status);
}