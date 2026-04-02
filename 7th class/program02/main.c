// Runge - Kutta (4th order)

#include <stdio.h>

float f(float x, float y) {
    return x + y;   // Example function
}

int main() {
    float x = 0, y = 1;
    float h = 0.05;
    int n = 6;

    printf("Step\t x\t y\n");

    for(int i = 0; i <= n; i++) {
        printf("%d\t %.2f\t %.4f\n", i, x, y);

        float k1 = h * f(x, y);
        float k2 = h * f(x + h/2, y + k1/2);
        float k3 = h * f(x + h/2, y + k2/2);
        float k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
        x = x + h;
    }

    return 0;
}