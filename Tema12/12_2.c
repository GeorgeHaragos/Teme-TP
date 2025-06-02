#include <stdio.h>

int n, p[20], folosit[20];

int este_descrescatoare(int start, int end) {
    for (int i = start; i < end - 1; i++) {
        if (p[i] <= p[i + 1]) return 0;
    }
    return 1;
}

int este_crescatoare(int start, int end) {
    for (int i = start; i < end-1; i++) {
        if (p[i] >= p[i + 1]) return 0;
    }
    return 1;
}

void backtracking(int k) {
    if (k == n) {
        int mij = n / 2;
        if (este_descrescatoare(0, mij+1) && este_crescatoare(mij, n)) {
            for (int i = 0; i < n; i++) {
                printf("%d ", p[i]);
            }
            printf("\n");
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!folosit[i]) {
            folosit[i] = 1;
            p[k] = i;
            backtracking(k + 1);
            folosit[i] = 0;
        }
    }
}

int main() {
    printf("n = ");
    scanf("%d", &n);
    backtracking(0);
    return 0;
}
