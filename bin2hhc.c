#include <stdio.h>

int main() {
    int c;
    while (1) {
        c = getchar();
        if (c==EOF) break;
        if (32 <= c && c <= 126) {
            printf("%02x %c\n", c, c);
        } else {
            printf("%02x\n", c);
        }
    }
}
