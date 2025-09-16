#include <stdio.h>

int main(void) {
    long long n, original, rev = 0;
    printf("Enter a non-negative integer: ");
    if (scanf("%lld", &n) != 1) return 0;
    if (n < 0) {
        printf("Negative numbers are not considered palindromes.\n");
        return 0;
    }
    original = n;

    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }

    if (rev == original) printf("%lld is a palindrome.\n", original);
    else                 printf("%lld is not a palindrome.\n", original);
    return 0;
}
