#include <stdio.h>
#include <stdlib.h>

typedef struct nod{
    int n;
    struct nod *urm;
}nod;

nod *nou(int n, nod *urm){
    nod *nod_nou=(nod *)malloc(sizeof(nod));
    if(!nod_nou){
        fprintf(stderr,"Eroare alocare nod!!\n");
        exit(-1);
    }
    nod_nou->n=n;
    nod_nou->urm=urm;
    return nod_nou;
}

nod *adaugareSfarsit(nod *list, int n){
    nod *p=list;
    nod *urm;
    if(!list)
        return nou(n,NULL);
    for(urm=p->urm;urm;p=urm,urm=p->urm);
    p->urm=nou(n,NULL,p);
    return list;
}

void afisare(nod *list){
    for(;list;list=list->urm)
        printf("(%d)-",list->n);
    printf("\b");
    printf(" \n");
}

nod *eliberare(nod *list){
    nod *p;
    while(list){
        p=list->urm;
        free(list);
        list=p;
    }
    list=NULL;
    return list;
}
int main(int argc, char **argv){
    if(argc!=2){
        fprintf(stderr,"Numar gresit de argumente (trebuie 2)!!\n");
        return -1;
    }
    FILE *f=fopen(argv[1],"r");
    if(!f){
        fprintf(stderr,"Eroare deschidere fisier!!\n");
        return -1;
    }

    nod *list1=NULL,*list2=NULL;
    int n,x;
    if(fscanf(f,"%d",&n)!=1){
        fprintf(stderr,"Eroare citire!\n");
        return -1;
    }
    for(int i=0;i<n;i++){
        x=0;
        fscanf(f,"%d",&x);
        list1=adaugareSfarsit(list1,x);
    }
    afisare(list1);
    nod *pred, *crt;
    do{
    for(pred=list1,crt=list1->urm;crt;pred=crt,crt=crt->urm){
        list2=adaugareSfarsit(list2,(pred->n+crt->n));
    }
    list1=eliberare(list1);
    list1=list2;
    afisare(list1);
    list2=NULL;
    }while(list1->urm);
    list1=eliberare(list1);
    afisare(list1);
    return 0;
}