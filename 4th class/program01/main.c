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
    int n;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];

    printf("Enter values of x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter values of y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }

    float value;

    printf("Enter the value of x for interpolation: ");
    scanf("%f", &value);

    float ans = lagrangeInterpolation(x, y, n, value);

    printf("The value of y(%.2f) = %.3f\n", value, ans);

    return 0;
}