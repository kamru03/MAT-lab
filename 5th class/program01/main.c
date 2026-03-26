#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k, maxRow;
    float a[10][11], x[10], factor, sum, temp;

    printf("Enter number of variables: ");
    scanf("%d", &n);

    printf("Enter augmented matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Forward Elimination with Proper Pivoting
    for(i = 0; i < n-1; i++) {

        // Find max pivot row
        maxRow = i;
        for(j = i+1; j < n; j++) {
            if(fabs(a[j][i]) > fabs(a[maxRow][i])) {
                maxRow = j;
            }
        }

        // Swap rows
        if(maxRow != i) {
            for(k = 0; k <= n; k++) {
                temp = a[i][k];
                a[i][k] = a[maxRow][k];
                a[maxRow][k] = temp;
            }
        }

        // Elimination
        for(j = i+1; j < n; j++) {
            factor = a[j][i] / a[i][i];
            for(k = i; k <= n; k++) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }

    // Back Substitution
    for(i = n-1; i >= 0; i--) {
        sum = 0;
        for(j = i+1; j < n; j++) {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }

    // Output
    printf("\nSolution:\n");
    for(i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i+1, x[i]);
    }

    return 0;
}