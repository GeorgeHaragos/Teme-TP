#include <stdio.h>
#include <stdlib.h>

typedef struct nod{
    int n;
    struct nod *urm, *pred;
}nod;

nod *nou(int n, nod *urm, nod *pred){
    nod *nod_nou=(nod *)malloc(sizeof(nod));
    if(!nod_nou){
        fprintf(stderr,"Eroare alocare nod nou!\n");
        exit(-1);
    }
    nod_nou->n=n;
    nod_nou->urm=urm;
    nod_nou->pred=pred;
    return nod_nou;
}

nod *adaugaInceput(nod *lista, int n){
    return nou(n,lista,NULL);
}

nod *adaugaSfarsit(nod *lista, int n){
    if(!lista) return nou(n,NULL,NULL);
    nod *p=lista,*urm;
    for(urm=p->urm;urm;p=urm,urm=p->urm);
    p->urm=nou(n,NULL,p);
    return lista;
}

void afisare_list(nod *lista){
    for(;lista;lista=lista->urm)
        printf("%d-",lista->n);
    printf("\b");
    printf(" ");
    printf("\n");
}

nod *eliberare_lista(nod *list){
    nod *p;
    while(list){
        p=list->urm;
        free(list);
        list=p;
    }
    list=NULL;
    return list;
}

int numarare_nod(nod *list){
    int nr=0;
    while(list){
        nr++;
        list=list->urm;
    }
    return nr;
}

nod *adaugareMijloc(nod *list, int mijloc, nod *list2){
    nod *urm2;
    while(mijloc-1>0){
        mijloc--;
        list=list->urm;
    }
    urm2=list->urm;
    list->urm=list2;
    nod *p=list2,*urm;
    urm=p->urm;
    while(urm){
        p=urm;
        urm=p->urm;
    }
    p->urm=urm2;
    return list;
}

nod *stergere_impare(nod *list){
    if(!list) return NULL;
    if(list->urm==NULL && list->n%2==1) {
        free(list);   
        return NULL;
    }
    nod *pred;
    nod *crt;
    for(pred=NULL,crt=list;crt;pred=crt,crt=crt->urm){
        if(crt->n%2==1){
            if(pred==NULL){
                list=list->urm;
            }
            else
            {
            pred->urm=crt->urm;
            }
            free(crt);
            if(pred==NULL)
            {
                crt=list;
            }
            else
            {
            crt=pred->urm;
            }
        }
    }
    return list;
}

int main(){
    nod *lista=NULL, *lista2=NULL;
    lista=adaugaInceput(lista,1);
    lista=adaugaSfarsit(lista,2);
    lista=adaugaSfarsit(lista,3);
    lista=adaugaSfarsit(lista,4);
    afisare_list(lista);
    lista2=adaugaInceput(lista2,5);
    lista2=adaugaSfarsit(lista2,6);
    lista2=adaugaSfarsit(lista2,7);
    lista2=adaugaSfarsit(lista2,8);
    afisare_list(lista2);
    int nr=numarare_nod(lista);
    printf("%d\n",nr);
    adaugareMijloc(lista,nr/2,lista2);
    afisare_list(lista);
    lista=stergere_impare(lista);
    afisare_list(lista);
    return 0;
}