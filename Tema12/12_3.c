#include <stdio.h>
#include <string.h>

char numar[100];
char rezultat[100];
char best[100];
int lungime, k, lungime_finala;

void backtrack(int poz, int len_rez) {
    if (len_rez == lungime_finala) {
        rezultat[len_rez] = '\0';
        // comparăm lexicografic (string-uri)
        if (strcmp(rezultat, best) > 0)
            strcpy(best, rezultat);
        return;
    }

    if (poz >= lungime) return;

    // opțiune: includem cifra curentă
    rezultat[len_rez] = numar[poz];
    backtrack(poz + 1, len_rez + 1);

    // opțiune: sărim peste cifra curentă
    backtrack(poz + 1, len_rez);
}

int main() {
    printf("n = ");
    scanf("%s", numar);
    printf("k = ");
    scanf("%d", &k);

    lungime = strlen(numar);
    lungime_finala = lungime - k;

    best[0] = '\0'; // inițial, best e vid

    backtrack(0, 0);

    printf("Numarul maxim este: %s\n", best);
    return 0;
}
