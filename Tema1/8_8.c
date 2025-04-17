#include <stdio.h>

int main() {
    int m, n, p;
    printf("Introduceti dimensiunile matricelor (m, n, p): ");
    scanf("%d %d %d", &m, &n, &p);
    if(m>10 || n>10 || p>10){
        fprintf(stderr,"Date introduse gresit!\n");
        return 1;
    }
    
    int a[m][n], b[n][p], c[m][p];
    
    printf("Introduceti elementele matricei a:\n");  //citim matricea a
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d]:",i,j);
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("Introduceti elementele matricei b:\n"); //citim matricea b
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf("b[%d][%d]",i,j);
            scanf("%d", &b[i][j]);
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            c[i][j] = 0; //initializam elementul cu 0 ca sa putem adauga fiecare membru a sumei direct la el
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j]; //inmultire de matrici 
            }
        }
    }

    printf("Matricea rezultata c este:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}