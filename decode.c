#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <assert.h>

const int w_sz = 3;

short w[3] = { 0, -1, 0 };

void shift(short v) {
    int i;

    for (i = 0; i < w_sz - 1; i++) {
        w[i] = w[i + 1];
    }

    w[i] = v;
}

int is_max() {

    if (w[1] > w[0] && w[1] > w[2])
        return 1;

    return 0;
}

int main() {
    short val;
    int n;

    int run = 0;

    char skip[256];

    assert(sizeof(val) == 2);

    n = read(0, skip, 44);
    if (n != 44) {
        perror("READ");
        exit(EXIT_FAILURE);
    }

    while (1) {
        n = read(0, &val, sizeof(val));
        if (n == 0)
            break;
        if (n == -1) {
            perror("read()");
            exit(EXIT_FAILURE);
        }
        shift(val);

        if (is_max()) {
            printf("%d\n", run);
            run = 0;
        } else {
            run++;
        }
    }

    exit(EXIT_SUCCESS);
}
