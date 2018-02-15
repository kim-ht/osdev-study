#include "./string.h"

int strlen(char *str) {
    int len;
    for ( len = 0; *str; ++len, ++str );
    return len;
}

void append(char *str, char ch) {
    int len;

    len = strlen(str);
    str[len] = ch;
    str[len + 1] = '\0';
}

void backspace(char *str) {
    int len;

    if ( len > 0 ) {
        str[strlen(str) - 1] = 0x00;
    }
}

int strcmp(char *s1, char *s2) {
    int i;

    for ( i = 0; s1[i] == s2[i]; ++i ) {
        if ( !s1[i] ) {
            return 0;
        }
    }
    return s1[i] - s2[i];
}

