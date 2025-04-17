#include <stdio.h>

int main() {
    int n;
    printf("Introduceti numarul de produse: ");
    scanf("%d", &n);
    
    int sales[n][4];
    
    for (int i = 0; i < n; i++) {
        printf("Introduceti vanzarile pentru produsul %d (4 trimestre):\n",i);
        for (int j = 0; j < 4; j++) {
            scanf("%d", &sales[i][j]);
        }
    }
    
    printf("Produse cu vanzari in crestere continua:\n");
    for (int i = 0; i < n; i++) {
        int increasing = 1; //consideram din start ca sunt in crestere continua pana gasim ca nu sunt 
        for (int j = 1; j < 4; j++) {
            if (sales[i][j] <= sales[i][j-1]) { //cand gasim faptul ca nu mai este in crestere vanzarea continuam la urmatoarea iteratie
                increasing = 0;
                continue;
            }
        }
        if (increasing) {
            printf("Produsul %d\n", i);
        }
    }

    return 0;
}
