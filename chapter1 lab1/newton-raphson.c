#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) (3*x - cos(x) - 1)  // Define the equation
#define g(x) (3 + sin(x))        // Define the derivative

int main() {
    float x0, x1, e, f0, f1, g0;
    int step = 1, N;

    // Input initial guess, tolerable error, and maximum iterations
    printf("\nEnter initial guess, tolerable error, and max iterations:\n");
    scanf("%f %f %d", &x0, &e, &N);

    // Newton-Raphson Method
    printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    do {
        g0 = g(x0);
        if (g0 == 0.0) {
            printf("Mathematical Error: Division by zero.\n");
            return -1;
        }

        f0 = f(x0);
        x1 = x0 - f0 / g0;
        f1 = f(x1);

        printf("%d\t\t%f\t%f\t%f\t%f\n", step++, x0, f0, x1, f1);

        if (step > N) {
            printf("Not Convergent.\n");
            return -1;
        }

        x0 = x1;
    } while (fabs(f1) > e);

    printf("\nRoot is: %f\n", x1);
    return 0;
}
