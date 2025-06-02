#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Utilizare: %s fisier1 fisier2\n", argv[0]);
        return 1;
    }

    FILE *f1 = fopen(argv[1], "rb");
    FILE *f2 = fopen(argv[2], "rb");

    if (!f1 || !f2) {
        perror("Eroare la deschiderea fisierelor");
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return 1;
    }

    int b1, b2;
    unsigned int offset = 0;
    int diferente = 0;

    while (1) {
        b1 = fgetc(f1);
        b2 = fgetc(f2);

        if (b1 == EOF && b2 == EOF)
            break;

        if (b1 != b2) {
            printf("%08X: %02X %02X\n", offset,
                   (b1 == EOF) ? 0 : b1,
                   (b2 == EOF) ? 0 : b2);
            diferente = 1;
        }

        offset++;
    }

    fclose(f1);
    fclose(f2);
    return 0;
}
