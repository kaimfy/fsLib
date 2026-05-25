#include "../include/stdlib.h"
#include <stdbool.h>
#include <stddef.h>

int abs(int j) {
    return j < 0 ? -j : j;
}

long int labs(long int j) {
    return j < 0 ? -j : j;
}

long long int llabs(long long int j) {
    return j < 0 ? -j : j;
}

static int is_digit(char c) {
    return c >= '0' && c <= '9';
}

static int is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r';
}

int atoi(const char *nptr) {
    return (int)atol(nptr);
}

long int atol(const char *nptr) {
    return (long int)atoll(nptr);
}

long long int atoll(const char *nptr) {
    long long int result = 0;
    int sign = 1;

    while (is_space(*nptr)) {
        nptr++;
    }

    if (*nptr == '-' || *nptr == '+') {
        if (*nptr == '-') {
            sign = -1;
        }
        nptr++;
    }

    while (is_digit(*nptr)) {
        result = result * 10 + (*nptr - '0');
        nptr++;
    }

    return result * sign;
}

static void reverse(char str[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char *itoa(int value, char *str, int base) {
    int i = 0;
    bool isNegative = false;

    if (value == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (value < 0 && base == 10) {
        isNegative = true;
        value = -value;
    }

    while (value != 0) {
        int rem = value % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        value = value / base;
    }

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    reverse(str, i);

    return str;
}
