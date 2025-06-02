#include <stdio.h>
#include <string.h>

char *culori[] = {"alb", "galben", "rosu", "verde", "albastru", "negru"};
int n = 6;
int sol[3];
int folosit[6];

void tipar() {
    if (strcmp(culori[sol[1]], "galben") != 0 && strcmp(culori[sol[1]], "verde") != 0) //conditia sa fie bine
        return;

    for (int i = 0; i < 3; i++) {
        printf("%s ", culori[sol[i]]);
    }
    printf("\n");
}

void back(int k) {
    for (int i = 0; i < n; i++) {
        if (!folosit[i]) {
            sol[k] = i;
            folosit[i] = 1;

            if (k == 2)
                tipar();
            else
                back(k + 1);

            folosit[i] = 0;
        }
    }
}

int main() {
    back(0);
    return 0;
}
