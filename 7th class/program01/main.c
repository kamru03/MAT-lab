//Euler Method
#include <stdio.h>

// Define the function f(x, y) = dy/dx
float f(float x, float y) {
    return x + y;   // Example: dy/dx = x + y
}

int main() {
    float x0, y0, xn, h;
    int n, i;

    printf("Enter initial value of x (x0): ");
    scanf("%f", &x0);

    printf("Enter initial value of y (y0): ");
    scanf("%f", &y0);

    printf("Enter step size (h): ");
    scanf("%f", &h);

    printf("Enter value of x at which y is required (xn): ");
    scanf("%f", &xn);

    n = (xn - x0) / h;

    printf("\nStep\t x\t\t y\n");
    printf("----------------------------------\n");

    for(i = 0; i < n; i++) {
        printf("%d\t %.4f\t %.4f\n", i, x0, y0);
        y0 = y0 + h * f(x0, y0);
        x0 = x0 + h;
    }

    printf("%d\t %.4f\t %.4f\n", n, x0, y0);

    printf("\nApproximate value of y at x = %.4f is %.4f\n", xn, y0);

    return 0;
}