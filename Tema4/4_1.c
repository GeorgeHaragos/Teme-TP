#include <stdio.h>
#include <string.h>

#define MAX_FISIER 1024
#define MAX_NUME 15

struct Fisier{
  char nume[MAX_NUME];
  unsigned int dimensiune:11; // (numar intre 0-1024)
  unsigned int extensie:2; //(0- .txt, 1- .doc, 2- .xls)
  unsigned int tip:1; //(0-normal, 1-read-only)
};

int main(void){
  struct Fisier fisier;
  unsigned int dimensiune_input , extensie_input , tip_input;
  
  printf("Introducerti numele fisierului:\n");
  fgets(fisier.nume,sizeof(fisier.nume),stdin);
  fisier.nume[strcspn(fisier.nume,"\n")]='\0';
  
  do{
    printf("Introduceti dimensiunea fisierului in bytes (0-%d):\n",MAX_FISIER);
    scanf("%u",&dimensiune_input);
  }while(dimensiune_input<0 || dimensiune_input>MAX_FISIER); //citim pana avem un numar corespunzator intre 0-1024
  fisier.dimensiune=dimensiune_input;
  do{
    printf("Introduceti tipul extensiei fisierului (0- .txt, 1- .doc, 2- .xls):\n");
    scanf("%u",&extensie_input);
  }while(extensie_input<0 || extensie_input>2); //citim pana avem un numar intre 0-2
  fisier.extensie=extensie_input;
  do{
    printf("Introduceti tipul fisierului (0- normal, 1- read-only):\n");
    scanf("%u",&tip_input);
  }while(tip_input<0 || tip_input>1);
  fisier.tip=tip_input;

  printf("Numele fisierului: %s\n",fisier.nume);
  printf("Dimensiunea fisierului in bytes: %u\n",fisier.dimensiune);
  printf("Extensia fisierului: ");
  switch(fisier.extensie){ //tiparim tipul extensiei fisierului
  case 0: printf("\".txt\"\n"); break;
  case 1: printf("\".doc\"\n"); break;
  case 2: printf("\".xls\"\n"); break;
  }
  printf("Tipul fisierului: ");
  switch(fisier.tip){ //tiparim tipul fisierului
  case 0: printf("normal\n"); break;
  case 1: printf("read-only\n"); break;
  }
  return 0;
}