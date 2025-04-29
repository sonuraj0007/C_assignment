#ifndef STRINGTOOLKIT_H
#define STRINGTOOLKIT_H

#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* Converts all characters of str to uppercase in place */
static inline void to_uppercase(char str[]) {
    for (size_t i = 0; str[i] != '\0'; ++i) {
        str[i] = (char)toupper((unsigned char)str[i]);
    }
}

/* Converts all characters of str to lowercase in place */
static inline void to_lowercase(char str[]) {
    for (size_t i = 0; str[i] != '\0'; ++i) {
        str[i] = (char)tolower((unsigned char)str[i]);
    }
}

/* Returns the number of vowels (aeiou, case-insensitive) in str */
static inline int count_vowels(const char str[]) {
    int count = 0;
    for (size_t i = 0; str[i] != '\0'; ++i) {
        char c = (char)tolower((unsigned char)str[i]);
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            ++count;
    }
    return count;
}

/* Reverses the characters of str in place */
static inline void reverse_string(char str[]) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len/2; ++i) {
        char tmp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = tmp;
    }
}

/* Helper for qsort: compare two C-strings */
static inline int _compare_strings(const void *a, const void *b) {
    const char * const *sa = a;
    const char * const *sb = b;
    return strcmp(*sa, *sb);
}

/* 
 Sorts an array of n strings (each up to 99 chars + null) 
 arr is declared as char arr[n][100]
*/
static inline void sort_strings(char arr[][100], int n) {
    /* Build an array of pointers for qsort */
    char *ptrs[n];
    for (int i = 0; i < n; ++i) {
        ptrs[i] = arr[i];
    }
    qsort(ptrs, n, sizeof(ptrs[0]), _compare_strings);

    /* Write back into arr in sorted order */
    char temp[100];
    for (int i = 0; i < n; ++i) {
        strcpy(temp, ptrs[i]);
        strcpy(arr[i], temp);
    }
}

/* 
 Reverses the order of words in str.
 Words are assumed to be separated by single spaces.
*/
static inline void reverse_words(char str[]) {
    /* First reverse the whole string */
    reverse_string(str);

    /* Now reverse each word back to normal order */
    char *start = str;
    while (*start) {
        /* find end of this word */
        char *end = strchr(start, ' ');
        if (end) {
            *end = '\0';
        }
        reverse_string(start);
        if (!end) break;
        *end = ' ';
        start = end + 1;
    }
}

#endif 