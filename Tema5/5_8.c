#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Convertire string hex -> byte
int hex_to_byte(const char *hex_str, unsigned char *byte) {
    char *endptr;
    long val = strtol(hex_str, &endptr, 16);
    if (*endptr != '\0' || val < 0 || val > 255)
        return -1;
    *byte = (unsigned char)val;
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <filename> <byte1> [byte2] ...\n", argv[0]);
        return 1;
    }

    // Construiește secvența de căutat
    int pattern_len = argc - 2;
    unsigned char *pattern = malloc(pattern_len);
    if (!pattern) {
        perror("malloc");
        return 1;
    }

    for (int i = 0; i < pattern_len; ++i) {
        if (hex_to_byte(argv[i + 2], &pattern[i]) != 0) {
            fprintf(stderr, "Invalid byte: %s\n", argv[i + 2]);
            free(pattern);
            return 1;
        }
    }

    // Deschide fișierul pentru citire binară
    FILE *f = fopen(argv[1], "rb");
    if (!f) {
        perror("fopen");
        free(pattern);
        return 1;
    }

    // Citește întregul fișier în memorie
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    rewind(f);

    unsigned char *buffer = malloc(fsize);
    if (!buffer) {
        perror("malloc");
        fclose(f);
        free(pattern);
        return 1;
    }

    if (fread(buffer, 1, fsize, f) != fsize) {
        perror("fread");
        fclose(f);
        free(buffer);
        free(pattern);
        return 1;
    }
    fclose(f);

    // Caută secvența în buffer
    for (long i = 0; i <= fsize - pattern_len; ++i) {
        if (memcmp(&buffer[i], pattern, pattern_len) == 0) {
            printf("Found at offset: 0x%lX\n", i);
        }
    }

    free(buffer);
    free(pattern);
    return 0;
}
