#include <stdio.h> 
 
#define MAX 10 
 
int main() { 
    int n; 
    float A[MAX][MAX], L[MAX][MAX] = {0}, U[MAX][MAX] = {0}; 
 
    printf("Enter the order of the matrix: "); 
    scanf("%d", &n); 
 
    printf("Enter the matrix elements row-wise:\n"); 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            scanf("%f", &A[i][j]); 
 
    for (int i = 0; i < n; i++) { 
        for (int j = i; j < n; j++) {  // Calculate U 
            float sum = 0; 
            for (int k = 0; k < i; k++) 
                sum += L[i][k] * U[k][j]; 
            U[i][j] = A[i][j] - sum; 
        } 
        for (int j = i; j < n; j++) {  // Calculate L 
            if (i == j) 
                L[i][i] = 1; 
            else { 
                float sum = 0; 
                for (int k = 0; k < i; k++) 
                    sum += L[j][k] * U[k][i]; 
                L[j][i] = (A[j][i] - sum) / U[i][i]; 
            } 
        } 
    } 
 
    printf("\nLower Triangular Matrix (L):\n"); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) 
            printf("%8.3f", L[i][j]); 
        printf("\n"); 
    } 
 
    printf("\nUpper Triangular Matrix (U):\n"); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) 
            printf("%8.3f", U[i][j]); 
        printf("\n"); 
    } 
 
    return 0; 
} 