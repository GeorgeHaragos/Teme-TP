#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct{
    char *nume;
    float pret;
    }Produs;
 
Produs produse[1000];
int nProduse;
 
void adaugare()
{
    Produs p;
    char nume[1000];
 
    printf("nume: ");
    fgets(nume,1000,stdin);
    nume[strcspn(nume,"\r\n")]='\0';
    if((p.nume=(char*)malloc((strlen(nume)+1)*sizeof(char)))==NULL){
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
        }
    strcpy(p.nume,nume);
    printf("pret: ");
    scanf("%g",&p.pret);
    produse[nProduse]=p;
    nProduse++;
}
 
void afisare()
{
    int i;
    for(i=0;i<nProduse;i++){
        printf("%s: %g\n",produse[i].nume,produse[i].pret);
        }
}
 
void eliberare()
{
    int i;
    for(i=0;i<nProduse;i++)free(produse[i].nume);
}
 

void scriere()
{
    FILE *fis;
    fis = fopen("produse.dat", "wb");
    if (fis == NULL) {
        printf("Eroare la deschiderea fisierului pentru scriere.\n");
        return;
    }

    fwrite(&nProduse, sizeof(int), 1, fis);  // scrierea numarului de produse

    for (int i = 0; i < nProduse; i++) {
        unsigned short nNume = strlen(produse[i].nume);
        fwrite(&nNume, sizeof(unsigned short), 1, fis);
        fwrite(produse[i].nume, sizeof(char), nNume, fis);
        fwrite(&produse[i].pret, sizeof(float), 1, fis);
    }

    fclose(fis);
}
void citire()
{
    FILE *fis;
    int n;

    if ((fis = fopen("produse.dat", "rb")) == NULL)
        return;  // nu exista baza de date; iesire linistita

    if (fread(&n, sizeof(int), 1, fis) != 1) {
        fclose(fis);
        return;  // fisier corupt sau gol
    }

    for (int i = 0; i < n; i++) {
        unsigned short nNume;
        if (fread(&nNume, sizeof(unsigned short), 1, fis) != 1) break;

        char *pNume = (char *)malloc((nNume + 1) * sizeof(char));
        if (pNume == NULL) {
            printf("memorie insuficienta\n");
            fclose(fis);
            eliberare();
            exit(EXIT_FAILURE);
        }

        if (fread(pNume, sizeof(char), nNume, fis) != nNume) {
            free(pNume);
            break;
        }
        pNume[nNume] = '\0';

        produse[nProduse].nume = pNume;
        if (fread(&produse[nProduse].pret, sizeof(float), 1, fis) != 1) {
            free(pNume);
            break;
        }

        nProduse++;
    }

    fclose(fis);
}

int main()
{
    int optiune;
    do{
        printf("optiune: ");
        scanf("%d",&optiune);
        getchar();
        switch(optiune){
            case 1:adaugare();break;
            case 2:afisare();break;
            case 3:scriere();eliberare();break;
            default:printf("optiune invalida\n");
            }
        }while(optiune!=3);
    return 0;
}