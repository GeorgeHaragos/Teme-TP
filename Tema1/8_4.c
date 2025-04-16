#include <stdio.h>

#define MAX 50

int main() {
    int n;
    printf("Introduceti dimensiunea matricei patratice (n <= 50): ");
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("Dimensiune invalida!\n");
        return 1;
}

    int matrice[MAX][MAX];

    printf("Introduceti elementele matricei:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { //citesc toate elementele de la tastatura
            scanf("%d", &matrice[i][j]);
        }
    }

    for (int i = 0; i < n; i++) { //facem transpusa inversand elementele de deasupra diagonalei principale cu cele de sub aceasta
        for (int j = i + 1; j < n; j++) {
            int temp = matrice[i][j];
            matrice[i][j] = matrice[j][i];
            matrice[j][i] = temp;
        }
    }

    printf("Matricea modificata:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", matrice[i][j]);
        }
        printf("\n");
    }

    return 0;
}