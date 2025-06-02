#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CITIRE 4096

void copiere(FILE *intrare,FILE *iesire){
    char text[MAX_CITIRE+1];
    while(fread(text,sizeof(text),MAX_CITIRE,intrare))
    fwrite(text,sizeof(text),MAX_CITIRE,iesire);
}


int main(int argc, char **argv){
    if (argc!=3){ //verificam ca avem destule argumente
        fprintf(stderr,"Numar gresit de argumente\n");
        exit(-1);
    }
    //deschidem fisierele cu care o sa lucram
    FILE *f=fopen(argv[1],"rb");
    if(!f){
        fprintf(stderr,"Fisierul de intrare nu a putut fi deschis!!\n");
        exit(-1);
    }
    FILE *g=fopen(argv[2],"wb");
    if(!g){
        fprintf(stderr,"Fisierul de iesire nu a putut fi deschis\n");
        exit(-1);
    }



    return 0;
}