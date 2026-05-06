#include <stdio.h>
#include <stdlib.h>


int **alocare(int m,int n,int **a){
    if((a=(int **)malloc(m*sizeof(int *)))==NULL){
        fprintf(stderr,"Eroare alocare dinamica!!\n");
        exit(-1);
    }
    for(int i=0;i<m;i++){
        if((a[i]=(int *)malloc(n*sizeof(int)))==NULL){
            for(i--;i>=0;i--)
                free(a[i]);
            free(a);
            fprintf(stderr,"Eroare alocare dinamica!!\n");
            exit(-1);
        }
    }
    return a;
}

void print_matrice(int **a,int n, int m){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}

void free_all(int **a, int m){
    for(int i=0;i<m;i++)
        free(a[i]);
    free(a);
}


int compara(const void *a, const void *b){ //-1, 0 sau 1 musai 
    int *elem1= (int *)a;
    int *elem2= (int *)b;
    return ((*elem1>*elem2)-(*elem2>*elem1)); //ordoneaza crescator ( rez<0 ordonate corect, rez>0 ordonate incorect)
}

int main(int argc, char **argv){

    
    int **a=NULL;
    int m,n;
    scanf("%d %d",&m,&n);
    a=alocare(m,n,a);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            a[i][j]=(i+j)/2;
    print_matrice(a,n,m);
    free_all(a,m);


    return 0;
}