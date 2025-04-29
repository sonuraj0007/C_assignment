#include <stdio.h>
#include "stringtoolkit.h"

int main(void) {
    char s1[] = "Hello, World!";
    scanf("%s",&s1);
    to_uppercase(s1);
    printf("%s\n", s1);             // "HELLO, WORLD!"

    char s2[] = "This Is MIXED case.";
    to_lowercase(s2);
    printf("%s\n", s2);             // "this is mixed case."

    printf("Vowels: %d\n", count_vowels("Beautiful"));  // 5

    char s3[] = "abcdef";
    reverse_string(s3);
    printf("%s\n", s3);             // "fedcba"

    char names[5][100] = {
        "Charlie",
        "Alice",
        "Bob",
        "Eve",
        "David"
    };
    sort_strings(names, 5);
    for (int i = 0; i < 5; ++i) {
        puts(names[i]);
    }
    // Alice, Bob, Charlie, David, Eve

    char sentence[] = "one two three four";
    reverse_words(sentence);
    printf("%s\n", sentence);       // "four three two one"

    return 0;
}