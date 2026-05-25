extern int printf(const char *format, ...);

#include "../include/ctype.h"
#include "../include/string.h"
#include "../include/stdlib.h"
#include "../include/stdio.h"

int main() {
    // Test ctype
    if (!isdigit('5')) return 1;
    if (isdigit('a')) return 1;
    if (!isalpha('A')) return 1;

    // Test string
    const char *str = "hello";
    if (strlen(str) != 5) return 1;
    char buf[32];
    strcpy(buf, str);
    if (strcmp(buf, "hello") != 0) return 1;
    memset(buf, 0, sizeof(buf));
    if (buf[0] != 0) return 1;

    // Test stdlib
    if (abs(-10) != 10) return 1;
    if (atoi("123") != 123) return 1;
    if (atoi("-456") != -456) return 1;

    // Test stdio
    char out[64];
    sprintf(out, "Num: %d, Hex: %x, Str: %s", 42, 255, "test");
    if (strcmp(out, "Num: 42, Hex: ff, Str: test") != 0) return 1;

    printf("All tests passed!\n");
    return 0;
}
