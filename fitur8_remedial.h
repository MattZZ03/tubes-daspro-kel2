
/*
    ==================================================
    FITUR 8: DAFTAR MAHASISWA REMEDIAL
    ==================================================

    Fungsi:
    - Memeriksa nilai akhir setiap mahasiswa.
    - Menentukan mahasiswa yang harus remedial.
    - Menampilkan NIM, nama, dan nilai akhir mahasiswa.
    - Menghitung jumlah mahasiswa yang harus remedial.

    Kriteria:
    - Mahasiswa harus remedial jika nilai akhir < 65.

    Parameter:
    - nim: Array untuk menyimpan NIM mahasiswa.
    - nama: Array untuk menyimpan nama mahasiswa.
    - nilaiAkhir: Array untuk menyimpan nilai akhir mahasiswa.
    - jumlahMahasiswa: Jumlah mahasiswa yang sudah terdaftar.
*/

void tampilkanRemedial(
    char nim[][PANJANG_NIM],
    char nama[][PANJANG_NAMA],
    float nilaiAkhir[],
    int jumlahMahasiswa)
{
    // <-- MEMERIKSA DATA MAHASISWA -->

    if (jumlahMahasiswa == 0)
    {
        printf("\nBelum ada data mahasiswa!\n");
        return;
    }

    // <-- MENDEKLARASIKAN VARIABEL -->

    int jumlahRemedial = 0;
    int i;
    int nomor = 0;

    // <-- MENGHITUNG JUMLAH MAHASISWA REMEDIAL -->

    for (i = 0; i < jumlahMahasiswa; i++)
    {
        // Memeriksa apakah nilai akhir mahasiswa di bawah 65.
        if (nilaiAkhir[i] < 65)
        {
            jumlahRemedial++;
        }
    }

    // <-- MEMERIKSA HASIL PERHITUNGAN -->

    if (jumlahRemedial == 0)
    {
        printf("\nTidak ada mahasiswa yang harus remedial.\n");
        return;
    }

    // <-- MENAMPILKAN DAFTAR MAHASISWA REMEDIAL -->

    printf("\n========== DAFTAR MAHASISWA REMEDIAL ==========\n\n");

    // Menampilkan header tabel.
    printf("%-5s %-20s %-25s %-15s\n",
           "No.", "NIM", "Nama", "Nilai Akhir");

    printf("---------------------------------------------------------------------\n");

    // Mengulangi proses untuk menampilkan mahasiswa yang remedial.
    for (i = 0; i < jumlahMahasiswa; i++)
    {
        // Memeriksa apakah nilai akhir mahasiswa di bawah 65.
        if (nilaiAkhir[i] < 65)
        {
            // Menambah nomor urut mahasiswa remedial.
            nomor++;

            // Menampilkan data mahasiswa remedial.
            printf("%-5d %-20s %-25s %-15.2f\n",
                   nomor, nim[i], nama[i], nilaiAkhir[i]);
        }
    }

    // <-- MENAMPILKAN TOTAL MAHASISWA REMEDIAL -->

    printf("\nTotal mahasiswa remedial: %d\n", jumlahRemedial);
}
