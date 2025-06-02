#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JUCATORI 100
#define MAX_GRUPE 10

typedef struct {
    char nume[16];
    int valoare;
} Jucator;

int cmp(const void *a, const void *b) {
    return ((Jucator*)b)->valoare - ((Jucator*)a)->valoare;  // descrescător
}

int main() {
    Jucator jucatori[MAX_JUCATORI];
    Jucator grupe[MAX_GRUPE][MAX_JUCATORI];
    int nrJucatoriPeGrupa[MAX_GRUPE] = {0};

    int n, m;
    FILE *f = fopen("jucatori.txt", "r");

    if (!f) {
        printf("Eroare la deschiderea fisierului.\n");
        return 1;
    }

    fscanf(f, "%d %d", &n, &m);  // presupunem prima linie: n m
    if (n % m != 0 || m <= 0 || n > MAX_JUCATORI || m > MAX_GRUPE) {
        printf("Date invalide: n trebuie sa fie divizibil cu m.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(f, "%s %d", jucatori[i].nume, &jucatori[i].valoare);
    }
    fclose(f);

    qsort(jucatori, n, sizeof(Jucator), cmp);

    // distribuție pe grupe: câte un jucător per grupă în ordine
    for (int i = 0; i < n; i++) {
        int grupa = i % m;
        grupe[grupa][nrJucatoriPeGrupa[grupa]++] = jucatori[i];
    }

    // afișare
    for (int i = 0; i < m; i++) {
        printf("Grupa %d:\n", i + 1);
        for (int j = 0; j < nrJucatoriPeGrupa[i]; j++) {
            printf("  %s (%d)\n", grupe[i][j].nume, grupe[i][j].valoare);
        }
    }

    return 0;
}
