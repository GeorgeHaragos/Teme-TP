#include <stdio.h>
#include <math.h>

#define G 6.674e-11

int main() {
    int n;
    double ma, mb, m, d;

    printf("n (numar de pasi): ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("n trebuie sa fie strict pozitiv!\n");
        return 1;
    }

    printf("Introdu ma, mb, m, d: ");
    scanf("%lf %lf %lf %lf", &ma, &mb, &m, &d);

    double pas = d / n;

    printf("\nPas\tPozitie x\tForța F (N)\n");
    printf("----------------------------------------\n");

    for (int i = 0; i <= n; i++) {
        double x = i * pas;

        double dist_a = x;
        double dist_b = d - x;

        double Fa = 0.0, Fb = 0.0; //initializam forta cu 0

        if (dist_a != 0) //evitam impartirea cu 0
            Fa = -G * ma * m / (dist_a * dist_a);  // negativ: spre ma
        if (dist_b != 0) //evitam impartirea cu 0
            Fb =  G * mb * m / (dist_b * dist_b);  // pozitiv: spre mb

        double F = Fa + Fb;

        printf("%d\t%.4f\t%.10e\n", i, x, F);
    }

    return 0;
}
