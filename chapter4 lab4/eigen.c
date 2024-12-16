#include <stdio.h> 
#include <math.h> 
// Function to calculate eigenvalues and eigenvectors 
void calculateEigen(float a, float b, float c, float d) { 
    float trace = a + d; 
    float determinant = a * d - b * c; 
    float discriminant = trace * trace - 4 * determinant; 
 
    if (discriminant < 0) { 
        printf("Eigenvalues are complex.\n"); 
        return; 
    } 
 
    // Eigenvalues 
    float lambda1 = (trace + sqrt(discriminant)) / 2; 
    float lambda2 = (trace - sqrt(discriminant)) / 2; 
 
    printf("Eigenvalues: %.2f, %.2f\n", lambda1, lambda2); 
 
    // Eigenvectors 
    if (b != 0) { 
        printf("Eigenvector for lambda1: [%.2f, %.2f]\n", lambda1 - d, b); 
        printf("Eigenvector for lambda2: [%.2f, %.2f]\n", lambda2 - d, b); 
    } else if (c != 0) { 
        printf("Eigenvector for lambda1: [%.2f, %.2f]\n", c, lambda1 - a); 
        printf("Eigenvector for lambda2: [%.2f, %.2f]\n", c, lambda2 - a); 
    } else { 
printf("Eigenvectors cannot be determined uniquely.\n"); 
} 
} 
int main() { 
float a, b, c, d; 
// Input matrix elements 
printf("Enter the elements of the 2x2 matrix (a, b, c, d):\n"); 
scanf("%f %f %f %f", &a, &b, &c, &d); 
calculateEigen(a, b, c, d); 
return 0; 
}