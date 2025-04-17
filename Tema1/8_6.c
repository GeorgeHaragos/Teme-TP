#include <stdio.h>

#define MAX 10

int main() {
    int n;
    printf("Introduceti numarul de persoane (n <= 10): ");
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        fprintf(stderr,"Numar invalid de persoane!\n");
        return 1;
    }

    int numarPrieteni[MAX] = {0}; //am facut un array in care stochez numarul de prieteni a fiecarei persoane
    for(int i=0;i<n;i++){
        printf("Introduceti prietenii persoanei cu codul %d: ", i);
        int prieten;
        while (1){
            scanf("%d",&prieten);
            if(prieten==-1)//consideram ca -1 este separatorul listelor de prieteni
                break;
            if(prieten>=0 && prieten <n && prieten !=i) //consideram ca nu vor fi introduse valori duplicate, altfel ar fi trebuit sa facem o matrice de adiacenta pentru acest caz
                numarPrieteni[i]++;
            else
                if(prieten == i)
                    printf("O persoana nu poate fi prietena cu ea insasi!!\n");
                else
                    printf("Cod invalid, introduceti din nou!\n");
        }
    }
    printf("Numarul de prieteni pentru fiecare persoana:\n");
    for (int i = 0; i < n; i++) {
        printf("Persoana cu codul %d are %d prieteni.\n", i, numarPrieteni[i]);
    }
    return 0;
}