#include <stdio.h>
#define N 100

int folosit[N+1];
int v[N];
int n,k;

void afis(int *array, int n){
    for(int i=0;i<n;i++)
        printf("%d ",array[i]);
    printf("\n");
}

void back(int pas){
    if(pas == k){
        afis(v,k);
        return ;
    }
    for(int i=1;i<=n;i++)
        if(!folosit[i]){
            v[pas]=i;
            folosit[i]=1;
            back(pas+1);
            folosit[i]=0;
        }
}


int main(){
    printf("Introduceti n:");
    scanf("%d",&n);
    printf("\nIntroduceti k:");
    scanf("%d",&k);
    if(k>n){
        printf("Nu este posibila operatia!!\n");
        return -1;
    }
    back(0);
    return 0;
}