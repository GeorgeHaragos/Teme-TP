#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    printf("Introduceti m si n: ");
    scanf("%d %d", &m, &n);

    int a[m][n];

    // Citim matricea
    printf("Introduceti elementele matricei:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    // Scriere în fișier binar
    FILE *f = fopen("matrice.bin", "wb");
    if (!f) {
        perror("Eroare la deschiderea fisierului pentru scriere");
        return 1;
    }

    // Scriem dimensiunile
    fwrite(&m, sizeof(int), 1, f);
    fwrite(&n, sizeof(int), 1, f);

    // Scriem toată matricea odată
    fwrite(a, sizeof(int), m * n, f);

    fclose(f);

    // Citim matricea din fișier în b
    f = fopen("matrice.bin", "rb");
    if (!f) {
        perror("Eroare la deschiderea fisierului pentru citire");
        return 1;
    }

    int m2, n2;
    fread(&m2, sizeof(int), 1, f);
    fread(&n2, sizeof(int), 1, f);

    int b[m2][n2];
    fread(b, sizeof(int), m2 * n2, f);

    fclose(f);

    // Afișăm matricea citită
    printf("Matricea citita din fisier:\n");
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
