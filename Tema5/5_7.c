#include <stdio.h>
#include <stdlib.h>

int hex_char_to_byte(const char *hex_str, unsigned char *byte) {
    char *endptr;
    long val = strtol(hex_str, &endptr, 16);
    if (*endptr != '\0' || val < 0 || val > 255)
        return -1;
    *byte = (unsigned char)val;
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <filename> <offset_hex> <byte1> [byte2] ...\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    long offset = strtol(argv[2], NULL, 16);
    if (offset < 0) {
        fprintf(stderr, "Invalid offset.\n");
        return 1;
    }

    FILE *f = fopen(filename, "rb+"); // citire + scriere, nu trunchiază
    if (!f) {
        perror("fopen");
        return 1;
    }

    if (fseek(f, offset, SEEK_SET) != 0) {
        perror("fseek");
        fclose(f);
        return 1;
    }

    for (int i = 3; i < argc; ++i) {
        unsigned char byte;
        if (hex_char_to_byte(argv[i], &byte) != 0) {
            fprintf(stderr, "Invalid byte value: %s\n", argv[i]);
            fclose(f);
            return 1;
        }
        if (fwrite(&byte, 1, 1, f) != 1) {
            perror("fwrite");
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}
