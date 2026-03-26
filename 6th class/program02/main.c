#include <stdio.h>
#include <math.h>

// Function definition
#define f(x) (1.0 / (1.0 + pow(x, 2)))

int main() {
    int n = 6, i = 1;
    double a = 0, b = 1;
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    while(i < n) {
        if(i % 2 != 0)
            sum = sum + 4 * f(a + i * h);
        else
            sum = sum + 2 * f(a + i * h);
        i++;
    }

    double integral = (h * sum) / 3.0;

    printf("The integral is: %.10lf\n", integral);
    printf("PI/4 is approximately: %.10lf\n", 4 * integral);

    return 0;
}