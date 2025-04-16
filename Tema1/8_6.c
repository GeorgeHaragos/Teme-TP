#include <stdio.h>

#define MAX 10

int main() {
    int n;
    printf("Introduceti numarul de persoane (n <= 10): ");
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("Numar invalid de persoane!\n");
        return 1;
    }

    int numarPrieteni[MAX] = {0}; //am facut un array in care stochez numarul de prieteni a fiecarei persoane
    for(int i=0;i<n;i++){
        printf("Introduceti prietenii persoanei %d: ", i);
        int prieten;
        while (scanf("%d",&prieten)){
            numarPrieteni[i]++;
        }
    }
    printf("Numarul de prieteni pentru fiecare persoana:\n");
    for (int i = 0; i < n; i++) {
        printf("Persoana %d are %d prieteni.\n", i, numarPrieteni[i]);
    }
    return 0;
}