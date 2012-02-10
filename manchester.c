#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

const int w = 96;

int main() {

    char line[128];
    char de[128];
    char code[17];

    int i = 0;
    char *p;
    long v;

    for (;;) {

        fgets(line, sizeof(line) - 1, stdin);
        p = strpbrk(line, "\n\r");
        if (p)
            *p = '\0';
        if (feof(stdin))
            break;

        memset(de, 0, sizeof(de));
        memset(code, 0, sizeof(code));

        p = de;

        for (i = 0; i < (int)strlen(line); i += 2) {
            if (line[i] == '1' && line[i + 1] == '0') {
                *p++ = '1';
            } else if (line[i] == '0' && line[i + 1] == '1') {
                *p++ = '0';
            } else {
                break;
            }
        }

		  printf("%s ", de);

        if (strlen(de) == 45) {
            memcpy(code, de + 28, 16);
            v = strtoul(code, NULL, 2);
            printf("(%ld)\n", v);
        } else {
            puts("(failure)");
        }
    }

    exit(EXIT_SUCCESS);
}
