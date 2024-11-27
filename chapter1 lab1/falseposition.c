#include <stdio.h>
#include <math.h>

/* Defining equation to be solved. 
   Change this equation to solve another problem. */
#define f(x) (x * log10(x) - 1.2)

int main() {
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1;

    // Inputs
    do {
        printf("\nEnter two initial guesses:\n");
        scanf("%f%f", &x0, &x1);
        printf("Enter tolerable error:\n");
        scanf("%f", &e);

        // Calculating Functional Values
        f0 = f(x0);
        f1 = f(x1);

        // Checking whether the guesses bracket the root
        if (f0 * f1 > 0.0) {
            printf("Incorrect Initial Guesses. Try again.\n");
        }
    } while (f0 * f1 > 0.0);

    // Implementing Regula Falsi or False Position Method
    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do {
        x2 = x0 - (x0 - x1) * f0 / (f0 - f1);
        f2 = f(x2);

        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);

        if (f0 * f2 < 0) {
            x1 = x2;
            f1 = f2;
        } else {
            x0 = x2;
            f0 = f2;
        }

        step++;
    } while (fabs(f2) > e);

    printf("\nRoot is: %f\n", x2);

    return 0;
}
