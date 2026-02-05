// Newton Raphson Method 
// (x*x*x*x)-x-10 , Epsilon :0.0001

#include <stdio.h>
#include <math.h>

// Function f(x) = x^4 - x - 10
float f(float x)
{
    return (x*x*x*x - x - 10);
}

// Derivative f'(x) = 4x^3 - 1
float df(float x)
{
    return (4*x*x*x - 1);
}

int main()
{
    float x0, x1, e;
    int iter = 1;

    e = 0.0001;   // Epsilon value

    printf("Enter initial guess: ");
    scanf("%f", &x0);

    do
    {
        if (df(x0) == 0)
        {
            printf("Mathematical Error! Derivative is zero.\n");
            return 0;
        }

        x1 = x0 - (f(x0) / df(x0));

        printf("Iteration %d: x = %.6f\n", iter, x1);

        x0 = x1;
        iter++;

    } while (fabs(f(x1)) > e);

    printf("\nRoot = %.6f\n", x1);

    return 0;
}
