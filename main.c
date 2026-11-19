#include <stdio.h>

int main(){
    int jumlahmahasiswa, i;
    char nim[i], nama[i];
    float tugas[i], quiz[i], uts[i], uas[i];

    printf("Masukkan jumlah mahasiswa : ");
    scanf("%d", &jumlahmahasiswa);

    for(i = 0; i <= jumlahmahasiswa; i++){
        printf("\nMasukkan NIM Mahasiswa : ");
        scanf("%s", nim[i]);
        getchar();
        printf("\nMasukkan Nama Mahasiswa : ");
        scanf("%s", nama[i]);
        
        printf("\n\nNIM : %s \n Nama : %s", nim, nama);
    }

    for(i = 0; i <= jumlahmahasiswa; i++){
        printf("\nMasukkan nilai tugas mahasiswa %d", i+1);
        scanf("%f", &tugas[i]);
        printf("Masukkan nilai quiz mahasiswa %d", i+1);
        scanf("%f", &quiz[i]);
        printf("Masukkan nilai UTS mahasiswa %d", i+1);
        scanf("%f", &uts[i]);
        printf("Masukkan nilai UAS mahasiswa %d", i+1);
        scanf("%f", &uas[i]);

        printf("\n\nNilai Mahasiswa %d :", i+1);
        printf("\tTugas : %f \nQuiz : %f \nUTS : %f \nUAS : %f", tugas[i], quiz[i], uts[i], uas[i]);
    }
}