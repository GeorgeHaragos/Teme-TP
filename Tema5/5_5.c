#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilizare: %s nume_fisier\n", argv[0]);
        return 1;
    }

    FILE *fis = fopen(argv[1], "rb");
    if (!fis) {
        perror("Eroare la deschiderea fisierului");
        return 1;
    }

    unsigned char buffer[16];
    size_t bytesCititi;
    unsigned int offset = 0;

    while ((bytesCititi = fread(buffer, 1, 16, fis)) > 0) {
        // Afisare offset
        printf("%08X  ", offset);

        // Afisare octeti in hexa
        for (size_t i = 0; i < 16; i++) {
            if (i < bytesCititi)
                printf("%02X ", buffer[i]);
            else
                printf("00 ");  // completare cu 0
        }

        printf(" ");

        // Afisare caractere
        for (size_t i = 0; i < 16; i++) {
            unsigned char c = (i < bytesCititi) ? buffer[i] : 0;
            if (c >= 32 && c <= 255)
                printf("%c", c);
            else
                printf(".");
        }

        printf("\n");
        offset += 16;
    }

    fclose(fis);
    return 0;
}
