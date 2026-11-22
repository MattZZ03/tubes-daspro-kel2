#include <stdio.h>

int main() {
float nilai[4];
int i;

for (i=0; i<4; i++) {
    if (i==0){
        printf ("Masukkan nilai tugas: ");
    } else if (i==1) {
        printf ("Masukkan nilai quiz: ");
    } else if (i==2) {
        printf ("Masukkan nilai UTS: ");
    } else {
         printf ("Masukkan nilai UAS: ");
    }

    scanf ("%f", &nilai[i]);
}

    printf("\n DATA NILAI \n");
    printf("Tugas : %.2f\n", nilai[0]);
    printf("Quiz  : %.2f\n", nilai[1]);
    printf("UTS   : %.2f\n", nilai[2]);
    printf("UAS   : %.2f\n", nilai[3]);

    return 0;
}