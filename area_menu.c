#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(void) {
    int choice;
    double a, b, h, r;

    do {
        printf("\n=== Area Calculator ===\n");
        printf("1) Circle\n");
        printf("2) Rectangle\n");
        printf("3) Triangle\n");
        printf("4) Square\n");
        printf("5) Ellipse\n");   // <- new shape
        printf("0) Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) return 0;

        switch (choice) {
            case 1:
                printf("Enter radius r: ");
                if (scanf("%lf", &r) != 1) return 0;
                if (r < 0) { printf("Radius must be non-negative.\n"); break; }
                printf("Area (circle) = %.4f\n", M_PI * r * r);
                break;

            case 2:
                printf("Enter length a and width b: ");
                if (scanf("%lf %lf", &a, &b) != 2) return 0;
                if (a < 0 || b < 0) { printf("Sides must be non-negative.\n"); break; }
                printf("Area (rectangle) = %.4f\n", a * b);
                break;

            case 3:
                printf("Enter base b and height h: ");
                if (scanf("%lf %lf", &b, &h) != 2) return 0;
                if (b < 0 || h < 0) { printf("Values must be non-negative.\n"); break; }
                printf("Area (triangle) = %.4f\n", 0.5 * b * h);
                break;

            case 4:
                printf("Enter side a: ");
                if (scanf("%lf", &a) != 1) return 0;
                if (a < 0) { printf("Side must be non-negative.\n"); break; }
                printf("Area (square) = %.4f\n", a * a);
                break;

            case 5: {
                printf("Enter semi-major axis a and semi-minor axis b: ");
                if (scanf("%lf %lf", &a, &b) != 2) return 0;
                if (a < 0 || b < 0) { printf("Axes must be non-negative.\n"); break; }
                printf("Area (ellipse) = %.4f\n", M_PI * a * b);
                break;
            }

            case 0:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
