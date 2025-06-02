#include <stdio.h>
#include <stdlib.h>

int copy_file(FILE *src, FILE *dest) {
    char buffer[4096];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        if (fwrite(buffer, 1, bytes, dest) != bytes) {
            return -1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input1> <input2> ... <output>\n", argv[0]);
        return 1;
    }

    const char *output_filename = argv[argc - 1];
    FILE *fout = fopen(output_filename, "wb");
    if (!fout) {
        perror("fopen (output)");
        return 1;
    }

    for (int i = 1; i < argc - 1; ++i) {
        FILE *fin = fopen(argv[i], "rb");
        if (!fin) {
            perror(argv[i]);
            fclose(fout);
            return 1;
        }

        if (copy_file(fin, fout) != 0) {
            fprintf(stderr, "Error copying from %s\n", argv[i]);
            fclose(fin);
            fclose(fout);
            return 1;
        }

        fclose(fin);
    }

    fclose(fout);
    return 0;
}
