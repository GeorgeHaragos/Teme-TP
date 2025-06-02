#include <stdio.h>
#include <string.h>

void scrie_litera(int n);

void scrie_litera(int n) {
    char *unitati[] = {
        "zero", "unu", "doi", "trei", "patru", "cinci",
        "șase", "șapte", "opt", "nouă", "zece", "unsprezece",
        "doisprezece", "treisprezece", "paisprezece", "cincisprezece",
        "șaisprezece", "șaptesprezece", "optsprezece", "nouăsprezece"
    };
    char *zeci[] = {
        "", "", "douăzeci", "treizeci", "patruzeci", "cincizeci",
        "șaizeci", "șaptezeci", "optzeci", "nouăzeci"
    };

    if (n < 20) {
        printf("%s", unitati[n]);
        return;
    }

    if (n < 100) {
        int z = n / 10;
        int u = n % 10;
        printf("%s", zeci[z]);
        if (u != 0) {
            printf(" și %s", unitati[u]);
        }
        return;
    }

    // n este între 100 și 999
    int s = n / 100;
    int rest = n % 100;

    if (s == 1)
        printf("o sută");
    else
        printf("%s sute", unitati[s]);

    if (rest != 0) {
        printf(" ");
        scrie_litera(rest);
    }
}

int main() {
    int n;
    printf("Introduceti numere (0-999), 1000 pentru iesire:\n");
    while (1) {
        printf("> ");
        scanf("%d", &n);
        if (n == 1000)
            break;
        if (n < 0 || n > 999) {
            printf("Numar invalid! Introduceti un numar intre 0 si 999.\n");
            continue;
        }
        scrie_litera(n);
        printf("\n");
    }
    return 0;
}
