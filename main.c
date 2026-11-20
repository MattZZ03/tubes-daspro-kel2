#include <stdio.h>

int main(){
    int jumlahmahasiswa, i;

    printf("Masukkan jumlah mahasiswa : ");
    scanf("%d", &jumlahmahasiswa);

    char nim[jumlahmahasiswa][9], nama[jumlahmahasiswa][50];
    float tugas[jumlahmahasiswa], quiz[jumlahmahasiswa];
    float uts[jumlahmahasiswa], uas[jumlahmahasiswa];

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
}