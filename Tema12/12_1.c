#include <stdio.h>

int n, k;

void back(int poz, int nr_de_1, int numar) {
    if (poz == n) {
        if (nr_de_1 == k)
            printf("%0*d\n", n, numar); // afișează cu zerouri în față dacă e cazul
        return;
    }

    for (int cifra = 0; cifra <= 9; cifra++) {
        if (poz == 0 && cifra == 0 && n > 1) // fără zerouri la început dacă n > 1
            continue;

        int nou_nr_de_1 = nr_de_1 + (cifra == 1);
        if (nou_nr_de_1 <= k) {
            back(poz + 1, nou_nr_de_1, numar * 10 + cifra);
        }
    }
}

int main() {
    printf("n = ");
    scanf("%d", &n);
    printf("k = ");
    scanf("%d", &k);

    back(0, 0, 0);
    return 0;
}
