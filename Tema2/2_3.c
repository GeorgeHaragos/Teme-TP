#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compara_float(const void *a, const void *b) { //functie pentru qsort si bsearch care sorteaza crescator numerele
    float fa = *(const float *)a;
    float fb = *(const float *)b;
    return (fa > fb) - (fa < fb);
}

int main() {
    int n;
    printf("Numarul de elemente (max 10): ");
    scanf("%d", &n);
    if(n>10){
        fprintf(stderr,"Numar prea mare de elemente!!\n");
        return 1;
    }
    float v[n];
    for (int i = 0; i < n; i++){
        printf("Introduceti elementul %d: ",i);
        scanf("%f", &v[i]);
    }
    qsort(v, n, sizeof(float), compara_float); //sortam crescator folosind functia definita mai sus
    printf("Vector sortat:\n");
    for (int i = 0; i < n; i++)
        printf("%.2f ", v[i]);
    printf("\n");
    float x;
    printf("Numarul de cautat: ");
    scanf("%f", &x);
    float *rezultat = (float *)bsearch(&x, v, n, sizeof(float), compara_float); //bsearchu o sa ne dea return la un pointer catre ultimul element gasit, daca nu gaseste elementul atunci va returna NULL
    if (rezultat)
        printf("Numarul %.2f se afla in vector.\n", x);
    else
        printf("Numarul %.2f nu se afla in vector.\n", x);
    return 0;
}




