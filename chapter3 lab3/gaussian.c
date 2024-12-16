#include <stdio.h> 
#include <math.h> 
#define N 5  // Number of sample points 
// Function to integrate (example: f(x) = x^2) 
double f(double x) { 
return x * x;  // Change the function here as needed 
} 
// Function to perform Gaussian integration 
double gaussianIntegration(double a, double b) { 
// Gauss-Legendre weights and nodes for N=5 (you can adjust N) 
double x[N] = {-0.9061798459, -0.5384693101, 0.0, 0.5384693101, 0.9061798459}; 
double w[N] = {0.2369268850, 0.4786286705, 0.5688888889, 0.4786286705, 
0.2369268850}; 
double sum = 0.0; 
double midpoint = (b + a) / 2.0; 
double half_length = (b - a) / 2.0; 
// Applying the transformation to the Gauss-Legendre nodes and weights 
for (int i = 0; i < N; i++) { 
double transformed_x = midpoint + half_length * x[i]; 
sum += w[i] * f(transformed_x); 
} 
return sum * half_length;  // Scaling by half the length of the interval 
} 
int main() { 
double a, b; 
// Get user input for limits of integration 
printf("Enter the lower limit (a): "); 
scanf("%lf", &a); 
printf("Enter the upper limit (b): "); 
scanf("%lf", &b); 
// Perform the Gaussian integration 
double result = gaussianIntegration(a, b); 
printf("Result of Gaussian integration = %lf\n", result); 
return 0; 
}