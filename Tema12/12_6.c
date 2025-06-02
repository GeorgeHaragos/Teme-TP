#include <stdio.h>
#include <string.h>

#define MAXN 20

// Codificăm entitățile cu indici:
enum { CASA, BLOC, GRADINA, ATELIER };

int c, b, g, a;
int n; // total entități

// Stocare entități disponibile
int disponibile[4]; // index 0=c,1=b,2=g,3=a

// Sirul rezultat (indici entitati)
int sol[MAXN];

// Matrice adiacenta vecini permisi (1 = valid, 0 = invalid)
int vecini[4][4] = {
//     C   B   G   A
    {1,  1,  1,  0}, // casa
    {1,  1,  0,  0}, // bloc
    {1,  0,  1,  1}, // gradina
    {0,  0,  1,  1}  // atelier
};

// Functie recursiva pentru backtracking
void back(int poz) {
    if (poz == n) {
        // am gasit o solutie - afisam
        for (int i = 0; i < n; i++) {
            switch(sol[i]) {
                case CASA: printf("Casa "); break;
                case BLOC: printf("Bloc "); break;
                case GRADINA: printf("Gradina "); break;
                case ATELIER: printf("Atelier "); break;
            }
        }
        printf("\n");
        return;
    }

    for (int tip = 0; tip < 4; tip++) {
        if (disponibile[tip] > 0) {
            // daca poz>0, verificam daca entitatea precedenta si cea curenta pot fi vecine
            if (poz == 0 || vecini[sol[poz-1]][tip]) {
                sol[poz] = tip;
                disponibile[tip]--;
                back(poz + 1);
                disponibile[tip]++;
            }
        }
    }
}

int main() {
    printf("Introduceti c b g a: ");
    scanf("%d %d %d %d", &c, &b, &g, &a);

    n = c + b + g + a;
    disponibile[CASA] = c;
    disponibile[BLOC] = b;
    disponibile[GRADINA] = g;
    disponibile[ATELIER] = a;

    back(0);

    return 0;
}
