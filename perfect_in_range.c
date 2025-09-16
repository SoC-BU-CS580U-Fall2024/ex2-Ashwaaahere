#include <stdio.h>

/* Return 1 if n is perfect, else 0 */
static int isPerfect(int n) {
    if (n < 2) return 0;            // by definition, 1 is not perfect
    int sum = 1;                    // 1 is a proper divisor of any n > 1
    for (int d = 2; (long long)d * d <= n; ++d) {
        if (n % d == 0) {
            sum += d;
            int other = n / d;
            if (other != d) sum += other;  // add complementary divisor
        }
    }
    return sum == n;
}

/* Try to read L and R from one line; if only one is given, prompt for the other. */
static int read_range(int *L, int *R) {
    char buf[256];
    printf("Enter range [L R]: ");
    fflush(stdout);

    if (!fgets(buf, sizeof buf, stdin)) return 0;

    int a, b;
    if (sscanf(buf, "%d %d", &a, &b) == 2) {         // both on one line
        *L = a; *R = b;
        return 1;
    }
    if (sscanf(buf, "%d", &a) == 1) {                // only L was given
        *L = a;
        printf("R: ");
        fflush(stdout);
        if (!fgets(buf, sizeof buf, stdin)) return 0;
        if (sscanf(buf, "%d", &b) == 1) { *R = b; return 1; }
        return 0;
    }

    // neither was given; prompt both
    printf("L: ");
    fflush(stdout);
    if (!fgets(buf, sizeof buf, stdin)) return 0;
    if (sscanf(buf, "%d", &a) != 1) return 0;

    printf("R: ");
    fflush(stdout);
    if (!fgets(buf, sizeof buf, stdin)) return 0;
    if (sscanf(buf, "%d", &b) != 1) return 0;

    *L = a; *R = b;
    return 1;
}

int main(void) {
    int L, R;
    if (!read_range(&L, &R)) {
        printf("Invalid input.\n");
        return 0;
    }

    if (L > R) { int t = L; L = R; R = t; }
    if (R < 2) { printf("No perfect numbers in this range.\n"); return 0; }
    if (L < 2) L = 2;

    printf("Perfect numbers in [%d, %d]:", L, R);
    int found = 0;
    for (int x = L; x <= R; ++x) {
        if (isPerfect(x)) { printf(" %d", x); found = 1; }
    }
    if (!found) printf(" (none)");
    printf("\n");
    return 0;
}
