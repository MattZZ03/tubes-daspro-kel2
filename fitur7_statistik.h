/*
    ==================================================
    FITUR 7: STATISTIK NILAI MAHASISWA
    ==================================================

    Fungsi:
    - Menampilkan nilai tertinggi mahasiswa.
    - Menampilkan nilai terendah mahasiswa.
    - Menghitung rata-rata nilai mahasiswa.
    - Menghitung jumlah mahasiswa yang lulus.

    Parameter:
    - nilaiAkhir: Array yang menyimpan nilai akhir mahasiswa.
    - jumlahMahasiswa: Jumlah mahasiswa yang sudah terdaftar.
*/

// <-- FUNGSI MENAMPILKAN STATISTIK NILAI MAHASISWA -->

void tampilkanStatistik(
    float nilaiAkhir[],
    int jumlahMahasiswa)
{
    // Memeriksa apakah sudah ada mahasiswa yang terdaftar.
    if (jumlahMahasiswa == 0)
    {
        printf("\nBelum ada data mahasiswa!\n");
        return;
    }

    // Variabel untuk menyimpan nilai tertinggi dan terendah.
    float nilaiTertinggi;
    float nilaiTerendah;

    // Variabel untuk menyimpan total dan rata-rata nilai.
    float totalNilai = 0;
    float rataRata;

    // Variabel untuk menghitung jumlah mahasiswa yang lulus.
    int jumlahLulus = 0;

    // Variabel untuk menghitung perulangan.
    int i;

    // Menggunakan nilai mahasiswa pertama sebagai nilai awal.
    nilaiTertinggi = nilaiAkhir[0];
    nilaiTerendah = nilaiAkhir[0];

    // Mengulangi proses untuk membandingkan nilai setiap mahasiswa.
    for (i = 1; i < jumlahMahasiswa; i++)
    {

        // Memeriksa apakah nilai mahasiswa lebih tinggi.
        if (nilaiAkhir[i] > nilaiTertinggi)
        {
            nilaiTertinggi = nilaiAkhir[i];
        }

        // Memeriksa apakah nilai mahasiswa lebih rendah.
        if (nilaiAkhir[i] < nilaiTerendah)
        {
            nilaiTerendah = nilaiAkhir[i];
        }
    }

    // Mengulangi proses untuk menjumlahkan seluruh nilai mahasiswa.
    for (i = 0; i < jumlahMahasiswa; i++)
    {
        totalNilai += nilaiAkhir[i];
    }

    // Menghitung rata-rata nilai seluruh mahasiswa.
    rataRata = totalNilai / jumlahMahasiswa;

    // Mengulangi proses untuk menghitung jumlah mahasiswa yang lulus.
    for (i = 0; i < jumlahMahasiswa; i++)
    {

        // Memeriksa apakah nilai akhir mahasiswa memenuhi batas kelulusan.
        if (nilaiAkhir[i] >= 65)
        {
            jumlahLulus++;
        }
    }

    // Menampilkan hasil statistik nilai mahasiswa.
    printf("\n========== STATISTIK NILAI MAHASISWA ==========\n");

    // Menampilkan nilai tertinggi.
    printf("Nilai tertinggi       : %.2f\n", nilaiTertinggi);

    // Menampilkan nilai terendah.
    printf("Nilai terendah        : %.2f\n", nilaiTerendah);

    // Menampilkan rata-rata nilai.
    printf("Rata-rata nilai       : %.2f\n", rataRata);

    // Menampilkan jumlah mahasiswa yang lulus.
    printf("Jumlah mahasiswa lulus: %d\n", jumlahLulus);

    // Menampilkan jumlah mahasiswa yang tidak lulus.
    printf("Jumlah tidak lulus    : %d\n", jumlahMahasiswa - jumlahLulus);
}