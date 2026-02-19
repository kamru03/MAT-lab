#include <stdio.h>

float lagrangeInterpolation(float x[], float y[], int n, float value) {
    float result = 0.0;

    for (int i = 0; i < n; i++) {
        float term = y[i];

        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (value - x[j]) / (x[i] - x[j]);
            }
        }

        result = result + term;
    }

    return result;
}

int main() {
    float x[] = {1, 3, 4, 7, 8};
    float y[] = {1.25, 3.46, 5.96, 2.48, 7.89};
    int n = 5;

    float value = 5.96;

    float ans = lagrangeInterpolation(x, y, n, value);

    printf("The value of y(%.2f) = %.3f\n", value, ans);

    return 0;
}
