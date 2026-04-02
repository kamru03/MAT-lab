//Gauss Siedel Method

#include <stdio.h>
#include <math.h>

int main() {
    float x = 0.0, y = 0.0, z = 0.0;
    float x_new, y_new, z_new;

    // Declare old variables OUTSIDE loop
    float x_old, y_old, z_old;

    float tolerance = 0.005;
    int iteration = 0;

    printf("Gauss-Seidel Method\n");
    printf("-------------------\n");

    do {
        // Store previous values
        x_old = x;
        y_old = y;
        z_old = z;

        // Gauss-Seidel formulas
        x_new = (14 - 3*y - z) / 10;
        y_new = (5 + 2*x_new + 3*z) / 10;
        z_new = (14 - x_new - 3*y_new) / 10;

        // Update values
        x = x_new;
        y = y_new;
        z = z_new;

        iteration++;

        printf("Iteration %d: x = %.4f, y = %.4f, z = %.4f\n",
               iteration, x, y, z);

    } while (fabs(x - x_old) > tolerance ||
             fabs(y - y_old) > tolerance ||
             fabs(z - z_old) > tolerance);

    printf("\nFinal Answer (2 decimal places):\n");
    printf("x = %.2f, y = %.2f, z = %.2f\n", x, y, z);

    return 0;
}