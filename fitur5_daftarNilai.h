/*
    ==================================================
    FITUR 5: MENAMPILKAN DAFTAR NILAI MAHASISWA
    ==================================================

    Fungsi:
    - Menampilkan NIM mahasiswa.
    - Menampilkan nama mahasiswa.
    - Menampilkan nilai akhir setiap mahasiswa.
    - Menampilkan seluruh data mahasiswa yang terdaftar.

    Parameter:
    - nim: Array yang menyimpan NIM mahasiswa.
    - nama: Array yang menyimpan nama mahasiswa.
    - nilaiAkhir: Array yang menyimpan nilai akhir mahasiswa.
    - jumlahMahasiswa: Jumlah mahasiswa yang sudah terdaftar.
*/

// <FUNGSI MENAMPILKAN DAFTAR NILAI MAHASISWA>

void tampilkanDaftarNilai(
    char nim[][PANJANG_NIM],
    char nama[][PANJANG_NAMA],
    float nilaiAkhir[],
    int jumlahMahasiswa)
{
    // Variabel untuk menghitung perulangan data mahasiswa.
    int i;

    // Memeriksa apakah sudah ada mahasiswa yang terdaftar.
    if (jumlahMahasiswa == 0)
    {
        printf("\nBelum ada data mahasiswa!\n");
        return;
    }

    // Menampilkan judul daftar nilai mahasiswa.
    printf("\n========== DAFTAR NILAI MAHASISWA ==========\n\n");

    // Menampilkan header tabel.
    printf("%-5s %-20s %-25s %-15s\n",
           "No.", "NIM", "Nama", "Nilai Akhir");

    // Menampilkan garis pembatas tabel.
    printf("---------------------------------------------------------------------\n");

    // Mengulangi proses untuk menampilkan setiap mahasiswa.
    for (i = 0; i < jumlahMahasiswa; i++)
    {

        // Menampilkan nomor, NIM, nama, dan nilai akhir mahasiswa.
        printf("%-5d %-20s %-25s %-15.2f\n",
               i + 1,
               nim[i],
               nama[i],
               nilaiAkhir[i]);
    }

    // Menampilkan jumlah seluruh mahasiswa yang terdaftar.
    printf("\nTotal mahasiswa: %d\n", jumlahMahasiswa);
}