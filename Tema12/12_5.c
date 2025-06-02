#include <stdio.h>

int n;
double obiecte[101], v;

double sumaMax = 0;
int solutieMax[101]; // marchează ce obiecte se aleg
int solutieCurenta[101];

void back(int k, double sumaCurenta) {
    if (sumaCurenta > v) return;

    if (sumaCurenta > sumaMax) {
        sumaMax = sumaCurenta;
        for (int i = 0; i < n; i++)
            solutieMax[i] = solutieCurenta[i];
    }

    if (k >= n) return;

    // includem obiectul k
    solutieCurenta[k] = 1;
    back(k + 1, sumaCurenta + obiecte[k]);

    // nu includem obiectul k
    solutieCurenta[k] = 0;
    back(k + 1, sumaCurenta);
}

int main() {
    printf("n = ");
    scanf("%d", &n);

    printf("Volumele obiectelor:\n");
    for (int i = 0; i < n; i++)
        scanf("%lf", &obiecte[i]);

    printf("Volumul cutiei: ");
    scanf("%lf", &v);

    back(0, 0);

    printf("\nVolum utilizat optim: %.2lf\nObiecte alese:\n", sumaMax);
    for (int i = 0; i < n; i++) {
        if (solutieMax[i])
            printf("Obiect %d (%.2lf)\n", i + 1, obiecte[i]);
    }

    return 0;
}
