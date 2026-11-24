/*
    ==================================================
               FITUR 1: INPUT DATA MAHASISWA
    ==================================================

    Fungsi:
    - Memasukkan NIM mahasiswa.
    - Memasukkan nama mahasiswa.
    - Menyimpan identitas ke dalam array.

    Parameter:
    - nim: Array untuk menyimpan NIM.
    - nama: Array untuk menyimpan nama.
    - jumlahMahasiswa: Pointer untuk memperbarui jumlah
      mahasiswa yang sudah terdaftar.
*/

// <FUNGSI INPUT DATA MAHASISWA>

void inputMahasiswa(char nim[][PANJANG_NIM], char nama[][PANJANG_NAMA], int *jumlahMahasiswa){

    // Menyimpan jumlah mahasiswa yang ingin dimasukkan.
    int jumlahInput;

    // Variabel untuk menghitung perulangan input mahasiswa.
    int i;

    // Memeriksa apakah kapasitas mahasiswa masih tersedia.
    if (*jumlahMahasiswa >= MAX_MAHASISWA)
    {
        printf("Kapasitas mahasiswa sudah penuh!\n");
        return;
    }

    // Meminta pengguna memasukkan jumlah mahasiswa.
    printf("\nMasukkan jumlah mahasiswa: ");
    scanf("%d", &jumlahInput);

    // Memeriksa apakah jumlah input valid.
    if (jumlahInput <= 0 || jumlahInput > MAX_MAHASISWA - *jumlahMahasiswa)
    {
        printf("Jumlah mahasiswa tidak valid!\n");
        printf("Sisa kapasitas: %d\n", MAX_MAHASISWA - *jumlahMahasiswa);
        return;
    }

    // Mengulangi proses input sesuai jumlah mahasiswa yang diminta.
    for (i = *jumlahMahasiswa; i < *jumlahMahasiswa + jumlahInput; i++)
    {

        printf("\n=== INPUT MAHASISWA KE-%d ===\n", i + 1);

        // Meminta pengguna memasukkan NIM mahasiswa.
        printf("Masukkan NIM  : ");
        scanf("%9s", nim[i]);

        // Meminta pengguna memasukkan nama mahasiswa.
        printf("Masukkan Nama : ");
        scanf(" %49[^\n]", nama[i]);
    }

    // Menambahkan jumlah mahasiswa sesuai banyaknya data yang dimasukkan.
    *jumlahMahasiswa += jumlahInput;

    printf("\n%d data mahasiswa berhasil ditambahkan!\n", jumlahInput);
}