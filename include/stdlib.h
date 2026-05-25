#ifndef MY_STDLIB_H
#define MY_STDLIB_H

int abs(int j);
long int labs(long int j);
long long int llabs(long long int j);

int atoi(const char *nptr);
long int atol(const char *nptr);
long long int atoll(const char *nptr);

/* Non-standard but very useful */
char *itoa(int value, char *str, int base);

#endif
