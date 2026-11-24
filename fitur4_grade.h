/*============================================================
 * FUNGSI UNTUK MENENTUKAN GRADE DAN STATUS KELULUS
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
 * ============================================================
 */

#include <stdio.h>

#define BATAS_A      80
#define BATAS_B      70
#define BATAS_C      60
#define BATAS_D      50
#define BATAS_LULUS  60
#define LULUS        1
#define TIDAK_LULUS  0

/*
 * Fungsi : tentukanGrade
 * Tugas  : menentukan grade dari nilai akhir
 * Input  : hitungNilaiAkhir -> nilai akhir mahasiswa (0-100)
 * Output : *grade -> diisi huruf A/B/C/D/E
 * Cara kerja: nilai dicek dari batas tertinggi ke terendah,
 *             cek pertama yang benar langsung dipakai.
 */
void tentukanGrade(float hitungNilaiAkhir, char *grade)
{
    if (hitungNilaiAkhir >= BATAS_A) {
        *grade = 'A';
    } else if (hitungNilaiAkhir >= BATAS_B) {
        *grade = 'B';
    } else if (hitungNilaiAkhir >= BATAS_C) {
        *grade = 'C';
    } else if (hitungNilaiAkhir >= BATAS_D) {
        *grade = 'D';
    } else {
        *grade = 'E';
    }
}

/*
 * Fungsi : tentukanStatus
 * Tugas  : menentukan status kelulusan dari nilai akhir
 * Input  : hitungNilaiAkhir -> nilai akhir mahasiswa (0-100)
 * Output : *status -> LULUS (1) bila hitungNilaiAkhir >= BATAS_LULUS,
 *                     selain itu TIDAK_LULUS (0)
 */
void tentukanStatus(float hitungNilaiAkhir, int *status)
{
    if (hitungNilaiAkhir >= BATAS_LULUS) {
        *status = LULUS;
    } else {
        *status = TIDAK_LULUS;
    }
}

/*
 * Fungsi : prosesGradeStatus
 * Tugas  : menentukan grade DAN status sekaligus
 * Input  : hitungNilaiAkhir -> nilai akhir mahasiswa (0-100)
 * Output : *grade  -> huruf A/B/C/D/E
 *          *status -> LULUS atau TIDAK_LULUS
 * Cara kerja: memanggil tentukanGrade lalu tentukanStatus.
 *             grade dan status sudah berupa alamat, jadi
 *             diteruskan tanpa tanda &.
 */
void prosesGradeStatus(float hitungNilaiAkhir, char *grade, int *status)
{
    tentukanGrade(hitungNilaiAkhir, grade);
    tentukanStatus(hitungNilaiAkhir, status);
}