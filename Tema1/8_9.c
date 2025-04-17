#include <stdio.h>

int main() {
    int n;
    printf("Introduceti dimensiunea matricei (n): ");
    scanf("%d", &n);
    
    int matrix[n][n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) { //se adauga 1 daca indexii corespund diagonalei principale iar 0 in rest
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    printf("Matricea identitate este:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}