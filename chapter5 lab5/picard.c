#include <stdio.h> 
#include <math.h> 
 
// Define the function f(x, y) = dy/dx 
double f(double x, double y) { 
    return x + y; // Example: dy/dx = x + y 
} 
 
// Picard Method for solving dy/dx = f(x, y) 
void picard(double x0, double y0, double xn, int iterations) { 
    double x = x0, y = y0; 
 
    printf("Initial condition: y(%.2f) = %.2f\n\n", x0, y0); 
 
    for (int i = 1; i <= iterations; i++) { 
        double y_next = y0; // Initialize y_next for current iteration 
 
        // Apply Picard's formula for iteration i 
        for (double xi = x0; xi <= xn; xi += 0.1) { 
            y_next += 0.1 * (f(xi, y)); // Approximation using dx = 0.1 
        } 
 
        printf("After iteration %d: y(%.2f) = %.6f\n", i, xn, y_next); 
 
        // Update for the next iteration 
        y = y_next; 
    } 
} 
 
int main() { 
    double x0, y0, xn; 
    int iterations; 
 
    // Input initial condition and iteration parameters 
    printf("Enter initial condition (x0, y0): "); 
    scanf("%lf %lf", &x0, &y0); 
    printf("Enter the value of xn (where to estimate y): "); 
    scanf("%lf", &xn); 
    printf("Enter the number of iterations: "); 
    scanf("%d", &iterations); 
 
    // Solve using Picard's method 
    picard(x0, y0, xn, iterations); 
 
    return 0; 
} 