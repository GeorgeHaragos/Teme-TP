#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*Predicat)(int);

void filtreaza_vector(int *v, int *n, Predicat p) { //transmitem numarul de elemente din vector prin adresa ca sa putem sa il modificam in functie
    int j = 0;
    for (int i = 0; i < *n; i++) {
        if (p(v[i])) { //daca indeplineste conditia de filtrare il retinem in noul array (de fapt nu facem array nou doar suprascriem peste cel existent)
            v[j++] = v[i]; //in loc sa stergem elementele care nu corespund am ales sa le salvez doar pe cele care corespund deoarece este mai usor si condsider ca si suficient
        }
    }
    *n = j; //micsoram arrayul incat sa putem accesa doar elementele filtrate (de fapt noi pierdem accesul la elementele de dupa indexul j si nu am eliberat partea aceea de memorie si nici nu avem cum sa facem asta deoarece am ales sa lucram cu arrayuri definite static avand in vedere ca nu ne sunt impuse restrictii la aceasta adresa)
}

int este_negativ(int x) { //predicatul dupa care filtram arrayul
    return x < 0;
}

int main() {
    int n;
    printf("Numarul de elemente: ");
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++){
        printf("Introduceti elementul %d: ",i+1);
        scanf("%d", &v[i]);
    }
    filtreaza_vector(v, &n, este_negativ); //apelam functia scrisa mai sus, precizand ca argument adresa (&) lui n ca sa poata fi schimbat de catre functie
    printf("Vector filtrat:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}