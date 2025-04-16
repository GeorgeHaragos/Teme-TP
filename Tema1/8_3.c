#include <stdio.h>

int main() {
    int m, n;
    printf("Introduceti numarul de linii (m <= 20) si coloane (n <= 10): ");
    scanf("%d %d", &m, &n); //luam input de la tastatura numarul de linii si de coloane
 
    if (m > 20 || n > 10 || m <= 0 || n <= 0) {
        printf("Dimensiuni invalide!\n");
        return 1;
    }

    int matrice[20][10];  
    int numar = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *(*(matrice + i) + j) = numar++;  //am lucrat aici cu aritmetica de pointeri deoarece am vrut sa incerc si acest mod
        }
    }

    printf("Matricea generata:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", *(*(matrice + i) + j));//am mentionat ca fiecare print sa fie de 3 campuri, adica daca e un numar de mai putin de 3 cifre sa puna 2 spatii inaintea numarului respectiv
        }
        printf("\n");
    }

    return 0;
}

