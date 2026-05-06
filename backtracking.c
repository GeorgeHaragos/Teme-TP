#include <stdio.h>
#include <limits.h> // pentru INT_MIN, INT_MAX
#include <string.h> // pentru memcpy()
#include "hs_utils.h"

int a[100][100];
int v[100];
int maxim = INT_MIN;
int vector_solutie[100];
int n=0;

void afisare(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(i<size-1)
            printf("%d-", array[i]);
        else if(i<size)
            printf("%d", array[i]);
    }
    printf("\n");
}

int validare(int k)
{
    // functie nefolosita, creata doar pentru a pastra 'scheletul' backtracking-ului
    return 1;
}

void backtrack(int k, int i)
{
    //if(k >= n) return; 
    {
        v[k] = a[k][i];
        if(validare(k) == 1)
        {   
            if(k == n - 1) // When we reach the last level
            {
                int s = 0;
                for(int j = 0; j < n; j++)
                    s += v[j];

                if(s > maxim)
                {
                    maxim = s;
                    memcpy(vector_solutie, v, n * sizeof(int));
                }
            }
            else
            {
                backtrack(k + 1, i + 1); //muti dreapta-jos
                backtrack(k+1, i); // muti jos
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if(estePar(23)){
        printf("Da!\n");
    }
    else
    printf("Nu!\n");
    FILE *f = fopen(argv[1], "r");

    fscanf(f, "%d", &n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            fscanf(f, "%d", &a[i][j]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    backtrack(0, 0);

    printf("Drum: ");
    afisare(vector_solutie, n);
    printf("Suma acestui drum este: %d.\n",maxim);

    fclose(f);
    return 0;
}