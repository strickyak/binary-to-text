#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char line[100];

unsigned unhex(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('A' <= c && c <= 'F') return c - 'A' + 10;
    if ('a' <= c && c <= 'f') return c - 'a' + 10;

    fprintf(stderr, "Bad char to unhex: %c\n", c);
    abort();
}

int main() {
    int n;
    unsigned hi, lo;

    while (1) {
        if (fgets(line, sizeof line, stdin) == 0) break;
        line[sizeof line - 1] = 0;  // assure termination

        for (char* s = line; *s; s++) {
            if (*s == '\n' || *s == '\r') {
                *s = 0;
                break;
            }
        }

        n = strlen(line);
            
        if (n == 0) {
            continue;
        }

        if (n == 1) {
            putchar(line[0]);
        } else {
            hi = unhex(line[0]); 
            lo = unhex(line[1]); 
            putchar( (hi<<4) | lo );
        }
    }
}
