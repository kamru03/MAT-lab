//Euler Method
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

        y = y + h * f(x, y);  // Euler formula
        x = x + h;
    }

    return 0;
}