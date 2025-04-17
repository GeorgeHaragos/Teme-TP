#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef double (*FuncMath)(double); //definim un pointer la functie care prelucreaza double-uri

void tabelare(double a, double b, int n, FuncMath f) {
    double pas = (b - a) / (n - 1); //calculam pasul pentru tabelare
    for (int i = 0; i < n; i++) {
        double x = a + i * pas;
        printf("f(%.2f) = %.5f\n", x, f(x)); // printam tabelarea
    }
}

int main() {
    double a, b;
    int n;
    printf("Introduceti a, b si n: ");
    scanf("%lf %lf %d", &a, &b, &n); //citim numere ca long float (lf)(double)
    printf("Tabelare cos:\n");
    tabelare(a, b, n, cos); //folosim functile predefinite in biblioteca math.h cos, sqrt, fabs
    printf("Tabelare sqrt:\n");
    tabelare(a, b, n, sqrt);
    printf("Tabelare fabs:\n");
    tabelare(a, b, n, fabs);
    return 0;
}

