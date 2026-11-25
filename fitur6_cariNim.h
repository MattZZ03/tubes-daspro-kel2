/* Membandingkan dua NIM teks karakter demi karakter.
   Mengembalikan 1 jika seluruh karakter sama dan 0 jika berbeda. */
int samaString(const char a[], const char b[]){
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0'){
        if (a[i] != b[i]){
            return 0;
        }

        i++;
    }

    /* Memastikan kedua teks memiliki panjang yang sama. */
    return a[i] == b[i];
}

/* Mencari mahasiswa berdasarkan NIM.
   Jika cocok, tampilkan nama, NIM, dan nilai Tugas, Quiz, UTS, UAS.
   Semua array memakai indeks yang sama untuk data mahasiswa terkait. */
void cariMahasiswa(int jumlahMahasiswa, char nim[][PANJANG_NIM],
                   char nama[][PANJANG_NAMA], float nilai[][4],
                   int nilaiDiinput[]){
    char nimDicari[PANJANG_NIM];
    int ditemukan = 0;
    int i;

    if (jumlahMahasiswa == 0){
        printf("Input data mahasiswa terlebih dahulu.\n");
        return;
    }

    printf("\nMasukkan NIM mahasiswa yang ingin dicari: ");
    if (scanf("%9s", nimDicari) != 1){
        printf("NIM tidak valid.\n");
        return;
    }

    for (i = 0; i < jumlahMahasiswa; i++){
        if (!samaString(nim[i], nimDicari)){
            continue;
        }

        printf("\nData mahasiswa ditemukan\n");
        printf("Nama: %s\n", nama[i]);
        printf("NIM : %s\n", nim[i]);

        if (nilaiDiinput[i]){
            printf("Tugas: %.2f\n", nilai[i][0]);
            printf("Quiz : %.2f\n", nilai[i][1]);
            printf("UTS  : %.2f\n", nilai[i][2]);
            printf("UAS  : %.2f\n", nilai[i][3]);
        }else{
            printf("Nilai belum diinput.\n");
        }

        ditemukan = 1;
        break;
    }

    if (!ditemukan){
        printf("Mahasiswa dengan NIM %s tidak ditemukan.\n", nimDicari);
    }
}
