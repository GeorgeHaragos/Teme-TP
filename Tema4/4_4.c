#include <stdio.h>
#include <string.h>

#define MAX_NUME 8
#define MAX_PICIOARE 1000
#define MAX_VARSTA 2000

struct Animal{
    unsigned int picioare:10; // numar mai mic de 1024
    float greutate;
    unsigned int periculos:1; //0- nu, 1- da
    char nume[MAX_NUME];
    unsigned int varsta:11; // numar mai mic de 2048
};

int main(void){
    struct Animal animal;
    unsigned int picioare_input, periculos_input, varsta_input;
    printf("Dimensiunea structului este de %lu de bytes\n",sizeof(struct Animal));
    do{
        printf("Introduceti numarul de picioare a animalului (numar din intervalul 0-%d):\n",MAX_PICIOARE);
        scanf("%u",&picioare_input);
    }while(picioare_input<0 || picioare_input>MAX_PICIOARE); //se citeste pana primeste o valoare valida
    animal.picioare=picioare_input;
    printf("Introduceti greutatea in kg (numar real):\n");
    scanf("%f",&animal.greutate);
    do{
        printf("Specificati daca animalul este sau nu periculos (0- nu, 1- da):\n");
        scanf("%u",&periculos_input);
    }while(periculos_input<0 || periculos_input>1); //se citeste pana primeste o valoare valida
    animal.periculos=periculos_input;
    getchar();
    printf("Introduceti prescurtarea stiintifica a speciei acestui animal (maxim 8 caractere):\n");
    fgets(animal.nume,sizeof(animal.nume),stdin);
    animal.nume[strcspn(animal.nume,"\n")]='\0'; //eliminam caracterul "newline din sirul de caractere"
    do{
        printf("Introduceti varsta maxima a animalului (numar din intervalul 0-%d):\n",MAX_VARSTA);
        scanf("%u",&varsta_input);
    }while(varsta_input<0 || varsta_input>MAX_VARSTA); //se citeste pana primeste o valoare valida
    animal.varsta=varsta_input;
    printf("Animalul are %u picioare\nGreutatea : %0.2f\nVarsta maxima %u\nApartine speciei %s\n",animal.picioare, animal.greutate, animal.varsta, animal.nume);
    if(animal.periculos)
    printf("Acest animal este periculos!!\n");
    else
    printf("Acest animal NU este periculos!\n");
    return 0;
}