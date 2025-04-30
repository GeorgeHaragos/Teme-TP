#include <stdio.h>
#include <string.h>

#define MAX_FISIER 1024
#define MAX_NUME 15
#define MAX_FISIERE 10

struct Fisier{
  char nume[MAX_NUME];
  unsigned int dimensiune:11; // (numar intre 0-1024)
  unsigned int extensie:2; //(0- .txt, 1- .doc, 2- .xls)
  unsigned int tip:1; //(0-normal, 1-read-only)
};

int main(void){
  struct Fisier fisier[MAX_FISIERE];
  unsigned int n,i,dimensiune_input,extensie_input,tip_input;
  FILE *f;
  f=fopen("memorie.txt","w");
  if(!f){
    fprintf(stderr,"Eroare deschidere fisier!\n");
      return 1;
  }
  
  printf("Introduceti numarul de fisiere (1-10):\n");
  scanf("%u",&n);
  
  for(i=0;i<n;i++){
    getchar(); //curatam bufferul ca sa putem folosi fgets
    printf("Introduceti informatiile pentru fisierul %u\n",i+1);  
    
    printf("\nIntroducerti numele fisierului:\n");  
    fgets(fisier[i].nume,sizeof(fisier[i].nume),stdin);
    fisier[i].nume[strcspn(fisier[i].nume,"\n")]='\0';
    
    do{
      printf("Introduceti dimensiunea fisierului in bytes (0-%d):\n",MAX_FISIER);
      scanf("%u",&dimensiune_input);
    }while(dimensiune_input<0 || dimensiune_input>MAX_FISIER); //citim pana avem un numar corespunzator intre 0-1024
    fisier[i].dimensiune=dimensiune_input;
    do{
      printf("Introduceti tipul extensiei fisierului (0- .txt, 1- .doc, 2- .xls):\n");
      scanf("%u",&extensie_input);
    }while(extensie_input<0 || extensie_input>2); //citim pana avem un numar intre 0-2
    fisier[i].extensie=extensie_input;
    do{
      printf("Introduceti tipul fisierului (0- normal, 1- read-only):\n");
      scanf("%u",&tip_input);
    }while(tip_input<0 || tip_input>1);
    fisier[i].tip=tip_input;
    
    fprintf(f,"Numele fisierului: %s\n",fisier[i].nume);
  fprintf(f,"Dimensiunea fisierului in bytes: %u\n",fisier[i].dimensiune);
  fprintf(f,"Extensia fisierului: ");
  switch(fisier[i].extensie){ //tiparim tipul extensiei fisierului
  case 0: fprintf(f,"\".txt\"\n"); break;
  case 1: fprintf(f,"\".doc\"\n"); break;
  case 2: fprintf(f,"\".xls\"\n"); break;
  }
  fprintf(f,"Tipul fisierului: ");
  switch(fisier[i].tip){ //tiparim tipul fisierului
  case 0: fprintf(f,"normal\n\n"); break;
  case 1: fprintf(f,"read-only\n\n"); break;
  }
  }
  printf("Informatiile au fost stocate in fisierul memorie.txt\n");
  return 0;
}