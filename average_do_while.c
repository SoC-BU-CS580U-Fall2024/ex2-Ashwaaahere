#include <stdio.h>

int main(void) {
    double x, sum = 0.0;
    int count = 0;
    char cont;

    do {
        printf("Enter a number: ");
        if (scanf("%lf", &x) != 1) return 0;
        sum += x;
        count++;

        printf("Add another? (y/n): ");
        // consume trailing whitespace/newline then read a char
        do { cont = (char)getchar(); } while (cont == '\n' || cont == ' ');
        if (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N') {
            // if the first non-space wasn’t y/n, keep reading to find a valid answer
            while (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N') {
                cont = (char)getchar();
            }
        }
    } while (cont == 'y' || cont == 'Y');

    if (count == 0) {
        printf("No numbers entered.\n");
    } else {
        printf("Average = %.6f (from %d number%s)\n", sum / count, count, count == 1 ? "" : "s");
    }
    return 0;
}

