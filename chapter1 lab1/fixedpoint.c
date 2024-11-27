#include <stdio.h>
#include <math.h>

#define f(x) (cos(x) - 3 * x + 1)  // Define the equation
#define g(x) ((1 + cos(x)) / 3)    // Define the rearranged equation for iteration

int main() {
    int step = 1, N;
    float x0, x1, e;

    // Input initial guess, tolerable error, and maximum iteration
    printf("Enter initial guess: ");
    scanf("%f", &x0);
    printf("Enter tolerable error: ");
    scanf("%f", &e);
    printf("Enter maximum iteration: ");
    scanf("%d", &N);

    // Fixed Point Iteration
    printf("\nStep\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    do {
        x1 = g(x0);
        printf("%d\t%f\t%f\t%f\t%f\n", step, x0, f(x0), x1, f(x1));

        step++;

        if (step > N) {
            printf("Not Convergent.\n");
            return -1;
        }

        x0 = x1;

    } while (fabs(f(x1)) > e);

    printf("\nRoot is %f\n", x1);

    return 0;
}
