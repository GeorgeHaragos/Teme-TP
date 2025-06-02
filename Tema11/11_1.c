#include <stdio.h>
#include <math.h>

#define MAX 100

typedef struct { //structura in care salvam coordonatele punctelor si daca au fost vizitate sau nu
    double x, y;
    int vizitat;
} Punct;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main() {
    int n;
    Punct puncte[MAX];

    printf("Numarul de puncte (n < 100): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 100) {
        printf("n invalid!\n");
        return 1;
    }

    printf("Introduceti coordonatele fiecarui punct (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &puncte[i].x, &puncte[i].y);
        puncte[i].vizitat = 0;
    }

    double cur_x = 0.0, cur_y = 0.0; //Salvam coordonatele punctului in care ne aflam la momentul curent
    printf("Ordinea de dat gauri:\n");

    for (int pas = 0; pas < n; pas++) {
        int cel_mai_apropiat = -1; //setam un index negativ la care nu se poate ajunge niciodata
        double min_dist = 1e9; //setam distanta pe un numar foarte mare

        for (int i = 0; i < n; i++) { //trecem prin fiecare punct
            if (!puncte[i].vizitat) { //alegem doar punctele care nu au fost vizitate pana acuma
                double d = dist(cur_x, cur_y, puncte[i].x, puncte[i].y);//aflam care e cel mai apropiat punct de punctul in care ne aflam
                if (d < min_dist) {
                    min_dist = d;
                    cel_mai_apropiat = i;
                }
            }
        }

        if (cel_mai_apropiat != -1) { //daca avem cel putin un punct care este cel mai apropiat il printam
            puncte[cel_mai_apropiat].vizitat = 1;
            cur_x = puncte[cel_mai_apropiat].x;
            cur_y = puncte[cel_mai_apropiat].y;
            printf("(%lf, %lf)\n", cur_x, cur_y);
        }
    }

    return 0;
}