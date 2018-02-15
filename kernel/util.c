#include "./util.h"

void memory_copy(char *source, char *dest, int no_bytes) {
    int i;

    for ( i = 0; i < no_bytes; ++i ) {
        *(dest + i) = *(source + i);
    }
}

void int_to_ascii(int n, char str[]) {
    int i, sign;
    char *begin, *end, *saved_end;
    char tmp;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';

    /* TODO: implement "reverse" */
    begin = str;
    for ( end = str; *end; ++end );
    end--;
    saved_end = end;
    while ( begin < saved_end ) {
        tmp = *end;
        *end = *begin;
        *begin = tmp;
        begin++;
        end--;
    }
}

