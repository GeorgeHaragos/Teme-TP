#include <stdio.h>

int main() {
    int n;
    printf("Introduceti numarul de orase: ");
    scanf("%d", &n);
    
    int dist[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i==j || i>j){//nu are sens sa cer distanta dintre un oras cu el insusi si nu am de ce sa cer aceeasi distanta de doua ori, asa ca am facut o matrice triangulara pozitiv definita fara diagonala principala
                dist[i][j]=0; //am setat distanta ca 0 in caz ca ma aflu in unul dintre cazurile descrise mai sus
                continue;
            }
            printf("Introduceti distanta dintre orasele %d si %d (0 pentru fara drum direct):\n",i,j);
            scanf("%d", &dist[i][j]);
        }
    }

    int min_dist = __INT_MAX__; //am initializat cu cel mai mare numar pozibil din int
    int city1, city2;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i==j || i>j) //cautam valori doar in partea populata a matricei
                continue;
            if (dist[i][j] != 0 && dist[i][j] < min_dist) {
                min_dist = dist[i][j];
                city1 = i;
                city2 = j;
            }
        }
    }

    printf("Cele mai apropiate orase sunt: %d si %d cu distanta de %d.\n", city1, city2, min_dist);
    return 0;
}