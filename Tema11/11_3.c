#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int max(int a, int b) { return (a > b ? a : b); } //functie pentru maximul intre a si b
int min(int a, int b) { return (a < b ? a : b); } //functie pentru minimul intre a si b
 
int reducere(int a[][MAX], int lin1, int lin2, int col1, int col2) { //matricea si limitele ei, lin1= limita superioara, lin2=limita inferioara, col1=limita cea mai din dreapta, col2=limita cea mai din stanga
    
    if (lin1 > lin2 || col1 > col2)
        return 0;  // Matrice vidă

    if (lin1 == lin2 && col1 == col2)
        return a[lin1][col1];  // Matrice 1x1

    int mid_lin = (lin1 + lin2) / 2;
    int mid_col = (col1 + col2) / 2;

    int r1 = reducere(a, lin1, mid_lin, col1, mid_col);         // stânga sus
    int r2 = reducere(a, lin1, mid_lin, mid_col + 1, col2);     // dreapta sus
    int r3 = reducere(a, mid_lin + 1, lin2, col1, mid_col);     // stânga jos
    int r4 = reducere(a, mid_lin + 1, lin2, mid_col + 1, col2); // dreapta jos

    return max(r1, r2) - min(r3, r4);
}

int main() {
    int m, n, a[MAX][MAX];

    printf("Dimensiuni matrice (m n): ");
    scanf("%d %d", &m, &n);

    printf("Elementele matricei:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int rezultat = reducere(a, 0, m - 1, 0, n - 1);
    printf("Reducerea matricei este: %d\n", rezultat);

    return 0;
}
