// main.c

#include <stdio.h>
#include "header_file.h"
#include <math.h>

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    int original = num, sum = 0, digits = 0, temp = num;
    
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = num;
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return sum == original;
}

// Function to reverse a number
int reverseNumber(int num) {
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

// Function to check if a number is a palindrome
int isPalindrome(int num) {
    return num == reverseNumber(num);
}

// Main function
int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isArmstrong(number))
        printf("%d is an Armstrong number.\n", number);
    else
        printf("%d is not an Armstrong number.\n", number);

    printf("Reverse of %d is %d.\n", number, reverseNumber(number));

    if (isPalindrome(number))
        printf("%d is a palindrome.\n", number);
    else
        printf("%d is not a palindrome.\n", number);

    return 0;
}
