#include <stdio.h>
#include <string.h>

void cariMahasiswa(int jumlahMahasiswa, char nim[][9], char nama[][50],
                   float nilai[][4], int nilaiDiinput[]) {
    char nimDicari[9];
    int ditemukan = 0;

    if (jumlahMahasiswa == 0) {
        printf("Input data mahasiswa terlebih dahulu.\n");
        return;
    }

    printf("\nMasukkan NIM mahasiswa yang ingin dicari: ");
    if (scanf("%8s", nimDicari) != 1) {
        printf("NIM tidak valid.\n");
        return;
    }

    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (strcmp(nim[i], nimDicari) == 0) {
            printf("\nData mahasiswa ditemukan\n");
            printf("Nama: %s\n", nama[i]);
            printf("NIM : %s\n", nim[i]);

            if (nilaiDiinput[i]) {
                printf("Tugas: %.2f\n", nilai[i][0]);
                printf("Quiz : %.2f\n", nilai[i][1]);
                printf("UTS  : %.2f\n", nilai[i][2]);
                printf("UAS  : %.2f\n", nilai[i][3]);
            } else {
                printf("Nilai belum diinput.\n");
            }

            ditemukan = 1;
            break;
        }
    }

    if (!ditemukan) {
        printf("Mahasiswa dengan NIM %s tidak ditemukan.\n", nimDicari);
    }
}

int main(){
    int jumlahMahasiswa = 0, pilih, i, j;
    int maxMahasiswa = 50;
    char nim[maxMahasiswa][9];
    char nama[maxMahasiswa][50];
    float nilai[maxMahasiswa][4];
    int nilaiDiinput[50] = {0};
    
    //Menu
    do{
        printf("\n============================================================\n");
        printf("======  SISTEM PENGELOLAAN NILAI AKADEMIK MAHASISWA  =======\n");
        printf("============================================================\n");
        printf("1. Input data mahasiswa (NIM & nama)\n");
        printf("2. Input nilai (tugas, kuis, UTS, UAS)\n");
        printf("3. Atur bobot & hitung ulang nilai akhir\n");
        printf("4. Tampilkan grade & status kelulusan\n");
        printf("5. Tampilkan daftar mahasiswa & nilai akhir\n");
        printf("6. Cari mahasiswa berdasarkan NIM\n");
        printf("7. Statistik kelas\n");
        printf("8. Daftar mahasiswa perlu remedial\n");
        printf("0. Keluar\n");
        printf("============================================================\n");
        printf("Pilih fitur yang akan digunakan : ");
        scanf("%d", &pilih);
        
        switch(pilih){
            case 1:
            
            printf("============================================================\n");
            printf("                     Input Data Mahasiswa                   \n");
            printf("============================================================\n");
            printf("Jumlah mahasiswa yang akan dimasukkan : ");
            if (scanf("%d", &jumlahMahasiswa) != 1 ||
                jumlahMahasiswa < 1 || jumlahMahasiswa > maxMahasiswa) {
                printf("Jumlah mahasiswa harus antara 1 dan %d.\n", maxMahasiswa);
                jumlahMahasiswa = 0;
                break;
            }

            for (i = 0; i < jumlahMahasiswa; i++) {
                nilaiDiinput[i] = 0;
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                printf("\nMahasiswa ke-%d", i+1);
                printf("\nMasukkan Nama Mahasiswa : ");
                scanf(" %49[^\n]", nama[i]);
                printf("\nMasukkan NIM Mahasiswa : ");
                scanf("%9s", nim[i]);
            }
                break;

            case 2:
            if (jumlahMahasiswa == 0) {
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
                printf("Tugas: %.2f | Quiz: %.2f | UTS: %.2f | UAS: %.2f\n",
                       nilai[i][0], nilai[i][1], nilai[i][2], nilai[i][3]);
            }
            break;

            //     break;
            // case '3':
            //     aturBobotNilai(); 
            //     break;
            // case '4':
            //     gradeNilai();
            //     break;
            // case '5':
            //     daftarMahasiswa(); 
            //     break;
            case 6:
                cariMahasiswa(jumlahMahasiswa, nim, nama, nilai, nilaiDiinput);
                break;
            // case '7':
            //     statistikKelas(); 
            //     break;
            // case '8':
            //     daftarRemedial();
            //     break;
            case 0:
                printf("Terima kasih telah menggunakan layanan kami\n\n");
                break;
            default:
                printf("Menu tidak tersedia atau inputan salah!\n\n");
        }
    } while(pilih != 0);
}


/*
    for(i = 0; i < jumlahmahasiswa; i++){
        printf("\nMahasiswa %d\n", i+1);
        printf("Masukkan NIM Mahasiswa : ");
        scanf("%8s", nim[i]);
        printf("Masukkan Nama Mahasiswa : ");
        scanf(" %49[^\n]", nama[i]);
    }

    for(i = 0; i < jumlahmahasiswa; i++){
        printf("\nMasukkan nilai tugas mahasiswa %d : ", i+1);
        scanf("%f", &tugas[i]);
        printf("Masukkan nilai quiz mahasiswa %d : ", i+1);
        scanf("%f", &quiz[i]);
        printf("Masukkan nilai UTS mahasiswa %d : ", i+1);
        scanf("%f", &uts[i]);
        printf("Masukkan nilai UAS mahasiswa %d : ", i+1);
        scanf("%f", &uas[i]);


        printf("\nNilai Mahasiswa %d (%s)\n", i+1, nama[i]);
        printf("Tugas : %.2f\nQuiz  : %.2f\nUTS   : %.2f\nUAS   : %.2f\nRata-rata : %.2f\n", tugas[i], quiz[i], uts[i], uas[i], (tugas[i] + quiz[i] + uts[i] + uas[i])/4);
    }

    printf("\n%-4s %-12s %-20s %7s %7s %7s %7s\n",
       "No", "NIM", "Nama", "Tugas", "Quiz", "UTS", "UAS");
    for(i = 0; i < jumlahmahasiswa; i++){
        printf("%-4d %-12s %-20s %7.2f %7.2f %7.2f %7.2f\n",
            i+1, nim[i], nama[i], tugas[i], quiz[i], uts[i], uas[i]);
    }


    return 0;

    */