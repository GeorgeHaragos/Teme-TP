#include <stdio.h>

#define MAX 20

int main() {
    int n;
    printf("Introduceti dimensiunea matricei patratice (n <= 20): ");
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("Dimensiune invalida!\n");
        return 1;
    }

    int matrice[MAX][MAX], sumaLinii[MAX] = {0}, sumaColoane[MAX] = {0}; //am initializat sumele cu 0 ca sa pot adauga la ele numerele din matrice

    printf("Introduceti elementele matricei:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrice[i][j]); //citire element cu element de la tastatura
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { //formam sumele adunand fiecare element la suma la care corespunde
            sumaLinii[i] += matrice[i][j]; 
            sumaColoane[j] += matrice[i][j];
        }
    }

    printf("Sumele pe linii:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", sumaLinii[i]);
    }
    printf("\n");

    printf("Sumele pe coloane:\n");
    for (int j = 0; j < n; j++) {
        printf("%d ", sumaColoane[j]);
    }
    printf("\n");
    return 0;
}