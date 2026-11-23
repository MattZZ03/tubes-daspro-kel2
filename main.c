#include <stdio.h>

int main(){
    int jumlahMahasiswa, pilih;
    int maxMahasiswa = 50;
    char nim[maxMahasiswa][9];
    char nama[maxMahasiswa][50];
    
    //Fungsi Cari Mahasiswa dengan NIM
    void cariMahasiswa(void){
        printf("\nCari Mahasiswa menggunakan NIM");
        printf("\nMasukkan NIM yang ingin dicari : ");
        scanf("%8s", nim[i]); 
    }
    
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
        printf("Pilih fitur yang akan digunakan :\n");
        scanf("%d", &pilih);
        
        switch(pilih){
            case 1:

            printf("Input Data Mahasiswa\n");
            printf("Jumlah mahasiswa yang akan dimasukkan : ");
            scanf("%d", &jumlahMahasiswa);

            for (int i = 0; i < jumlahMahasiswa; i++) {
                printf("Masukkan Nama Mahasiswa : ");
                scanf(" %49[^\n]", nama[i]);
                printf("Masukkan NIM Mahasiswa : ");
                scanf("%8s", nim[i]);
            }
                break;
            // case '2':
            //     inputNilai();
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
            // case '6':
            //     cariMahasiswa();
            //     break;
            // case '7':
            //     statistikKelas(); 
            //     break;
            // case '8':
            //     daftarRemedial();
            //     break;
            case 
            0:
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
