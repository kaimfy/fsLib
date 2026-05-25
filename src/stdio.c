#include "../include/stdio.h"
#include "../include/stdlib.h"
#include "../include/string.h"

// A very basic vsnprintf implementation.
// Supports %d, %i, %x, %s, %c
int vsnprintf(char *str, size_t size, const char *format, va_list ap) {
    if (size == 0) return 0;
    
    size_t count = 0;
    while (*format && count < size - 1) {
        if (*format == '%') {
            format++;
            if (*format == '\0') break;

            if (*format == 'd' || *format == 'i') {
                int val = va_arg(ap, int);
                char buf[32];
                itoa(val, buf, 10);
                size_t len = strlen(buf);
                for (size_t i = 0; i < len && count < size - 1; i++) {
                    str[count++] = buf[i];
                }
            } else if (*format == 'x' || *format == 'X') {
                int val = va_arg(ap, int);
                char buf[32];
                itoa(val, buf, 16);
                size_t len = strlen(buf);
                for (size_t i = 0; i < len && count < size - 1; i++) {
                    str[count++] = buf[i];
                }
            } else if (*format == 's') {
                const char *val = va_arg(ap, const char *);
                if (!val) val = "(null)";
                while (*val && count < size - 1) {
                    str[count++] = *val++;
                }
            } else if (*format == 'c') {
                char val = (char)va_arg(ap, int);
                str[count++] = val;
            } else if (*format == '%') {
                str[count++] = '%';
            }
            // Ignore unsupported formats for now
        } else {
            str[count++] = *format;
        }
        format++;
    }
    
    str[count] = '\0';
    return count;
}

int vsprintf(char *str, const char *format, va_list ap) {
    return vsnprintf(str, (size_t)-1, format, ap);
}

int snprintf(char *str, size_t size, const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    int res = vsnprintf(str, size, format, ap);
    va_end(ap);
    return res;
}

int sprintf(char *str, const char *format, ...) {
    va_list ap;
    va_start(ap, format);
    int res = vsprintf(str, format, ap);
    va_end(ap);
    return res;
}
