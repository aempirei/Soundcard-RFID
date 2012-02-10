#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

const int w = 96;

int main() {

    char line[128];

    short val;

    int hi = 0;
    int lo = 0;

    int i = 0;

    int n = 0;
    int j = 0;

    int v;

    for (;;) {

        fgets(line, sizeof(line) - 1, stdin);
        if (feof(stdin))
            break;

        sscanf(line, "%hd ", &val);

        if (val < 6 || val > 9) {
            lo = hi = n = 0;
            continue;
        }

        if (lo) {
            if (val <= 7) {
                n++;
            } else {

                v = (int)rint(n / 6.0);
                for (i = 0; i < v; i++) {
                    putchar('0');
                    if (++j % w == 0)
                        putchar('\n');
                }

                n = 1;
                lo = 0;
                hi = 1;
            }
        } else {
            if (val >= 8) {
                n++;
            } else {

                v = (int)rint(n / 5.0);
                for (i = 0; i < v; i++) {
                    putchar('1');
                    if (++j % w == 0)
                        putchar('\n');
                }

                n = 1;
                lo = 1;
                hi = 0;
            }
        }
    }

    exit(EXIT_SUCCESS);
}
