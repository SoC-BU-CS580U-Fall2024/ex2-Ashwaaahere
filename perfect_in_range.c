#include <stdio.h>

int isPerfect(int n) {
    if (n < 2) return 0;            // 1 is not perfect by standard definition
    int sum = 1;                    // 1 is a proper divisor of any n>1
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0) {
            sum += d;
            int other = n / d;
            if (other != d) sum += other; // add the complementary divisor
        }
    }
    return sum == n;
}

int main(void) {
    int L, R;
    printf("Enter range [L R]: ");
    if (scanf("%d %d", &L, &R) != 1) return 0;
    if (L > R) { int tmp = L; L = R; R = tmp; }
    if (R < 2) { printf("No perfect numbers in this range.\n"); return 0; }

    printf("Perfect numbers in [%d, %d]:", L, R);
    int found = 0;
    for (int x = (L < 2 ? 2 : L); x <= R; ++x) {
        if (isPerfect(x)) { printf(" %d", x); found = 1; }
    }
    if (!found) printf(" (none)");
    printf("\n");
    return 0;
}
